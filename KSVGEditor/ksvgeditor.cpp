#include "ksvgeditor.h"
#include <QScrollBar>

KSVGEditor::KSVGEditor(QWidget *parent)
    : QMainWindow(parent)
    , m_currentCanvasScale(1.0)
    , m_isSelectShape(false)
    , m_preShapeBorderWidth(2)
{
    ui.setupUi(this);
    moveCanvasToCenter();
    ui.m_shapeBorderWidth->installEventFilter(this);
    ui.m_shapeBorderStyle->installEventFilter(this);
    (void)connect(ui.m_cleanCanvasBtn, &QPushButton::clicked, this, &KSVGEditor::onCleanCanvasClicked);
    (void)connect(ui.m_exportPNGBtn, &QPushButton::clicked, this, &KSVGEditor::onExportPNGBtnClicked);
    (void)connect(ui.m_selectButton, &QToolButton::clicked, this, &KSVGEditor::onSelectButtonClicked);
    (void)connect(ui.m_lineButton, &QToolButton::clicked, this, &KSVGEditor::onLineButtonClicked);
    (void)connect(ui.m_circleButton, &QToolButton::clicked, this, &KSVGEditor::onCircleButtonClicked);
    (void)connect(ui.m_rectButton, &QToolButton::clicked, this, &KSVGEditor::onRectButtonClicked);
    (void)connect(ui.m_pentagonButton, &QToolButton::clicked, this, &KSVGEditor::onPentagonButtonClicked);
    (void)connect(ui.m_hexagonButton, &QToolButton::clicked, this, &KSVGEditor::onHexagonButtonClicked);
    (void)connect(ui.m_pentagramButton, &QToolButton::clicked, this, &KSVGEditor::onPentagramButtonClicked);
    (void)connect(ui.m_canvas, &KCanvas::canvasZoomRequested, this, &KSVGEditor::onZoomCanvas);
    (void)connect(ui.m_ellipseButton, &QToolButton::clicked, this, &KSVGEditor::onEllipseButtonClicked);

    (void)connect(ui.m_canvasWidth, 
        QOverload<int>::of(&QSpinBox::valueChanged), 
        this, 
        &KSVGEditor::onSetCanvasWidth);
    (void)connect(ui.m_canvasHeight, 
        QOverload<int>::of(&QSpinBox::valueChanged), 
        this, 
        &KSVGEditor::onSetCanvasHeight);
    (void)connect(ui.m_canvasZoom, 
        QOverload<qreal>::of(&QDoubleSpinBox::valueChanged), 
        this, 
        &KSVGEditor::onZoomCanvas);
    (void)connect(ui.m_setCanvasColorButton, &QPushButton::pressed, this, &KSVGEditor::setCanvasColor);

    (void)connect(ui.m_shapeBorderWidth,
        QOverload<int>::of(&QSpinBox::valueChanged),
        this,
        &KSVGEditor::onSetShapeBorderWidth);
    (void)connect(ui.m_shapeBorderStyle, 
        &KBorderStyleButton::setShapePen, 
        this, 
        &KSVGEditor::onSetShapeBorderStyle);
    (void)connect(ui.m_setShapeBorderColorButton, &QPushButton::pressed, this, &KSVGEditor::onSetShapeBorderColor);
    (void)connect(ui.m_setShapeColorButton, &QPushButton::pressed, this, &KSVGEditor::onSetShapeColor);
    (void)connect(ui.m_canvas, &KCanvas::currentShapeBorderWidth, this, &KSVGEditor::onSetBorderWidthSpinBoxValue);
    (void)connect(ui.m_canvas, 
        &KCanvas::currentShapeBorderStyle, 
        ui.m_shapeBorderStyle, 
        &KBorderStyleButton::setComBoxView);
    (void)connect(ui.m_canvas, 
        &KCanvas::currntShapeBorderColor, 
        this, 
        &KSVGEditor::onSetShapeBorderColorButtonColor);
    (void)connect(ui.m_canvas, &KCanvas::currntShapeColor, this, &KSVGEditor::onSetShapeColorButtonColor);
    (void)connect(ui.m_canvas, &KCanvas::shapeSelected, this, &KSVGEditor::onIsSelectShape);
}

void KSVGEditor::moveCanvasToCenter()
{
    int x, y;
    x = (ui.scrollArea->width() - ui.m_canvas->width()) / 2;
    y = (ui.scrollArea->height() - ui.m_canvas->height()) / 2;
    ui.m_canvas->move(x, y);
    ui.m_canvas->update();
}


void KSVGEditor::onCleanCanvasClicked()
{
	QMessageBox::StandardButton cleanReply;
    cleanReply = QMessageBox::question(this, QStringLiteral("��ջ���"), QStringLiteral("ȷ��Ҫ��ջ�����"),
        QMessageBox::Yes | QMessageBox::No);
    if (cleanReply == QMessageBox::Yes)
    {
		QMessageBox::StandardButton savePNGReply;
        savePNGReply = QMessageBox::question(this, QStringLiteral("����PNG"), QStringLiteral("��Ҫ����PNG�ļ���"),
			QMessageBox::Yes | QMessageBox::No);
        if (savePNGReply == QMessageBox::Yes)
            onExportPNGBtnClicked();
        ui.m_canvas->cleanCanvas();
    }   
}


void KSVGEditor::onExportPNGBtnClicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, QStringLiteral("����PNG"), "", "PNG Files (*.png)");
	if (!fileName.isEmpty())
    {
		QPixmap pixmap(ui.m_canvas->size());
		ui.m_canvas->render(&pixmap);
        if (pixmap.save(fileName))
            QMessageBox::information(this, QStringLiteral("��ʾ"), QStringLiteral("����PNG�ɹ���·��Ϊ") + fileName);
        else
            QMessageBox::warning(this, QStringLiteral("����"), QStringLiteral("����ʧ�ܣ�������"));
	}
}


void KSVGEditor::onSelectButtonClicked()
{
    KShapeParameter::getInstance()->setDrawFlag(KCanvas::KDrawFlag::MouseDrawFlag);
}


void KSVGEditor::onLineButtonClicked()
{
    KShapeParameter::getInstance()->setDrawFlag(KCanvas::KDrawFlag::LineDrawFlag);
}


void KSVGEditor::onCircleButtonClicked()
{
    KShapeParameter::getInstance()->setDrawFlag(KCanvas::KDrawFlag::CircleDrawFlag);
}


void KSVGEditor::onRectButtonClicked()
{
    KShapeParameter::getInstance()->setDrawFlag(KCanvas::KDrawFlag::RectDrawFlag);
}


void KSVGEditor::onPentagonButtonClicked()
{
    KShapeParameter::getInstance()->setDrawFlag(KCanvas::KDrawFlag::PentagonDrawFlag);
}


void KSVGEditor::onHexagonButtonClicked()
{
    KShapeParameter::getInstance()->setDrawFlag(KCanvas::KDrawFlag::HexagonDrawFlag);
}


void KSVGEditor::onPentagramButtonClicked()
{
    KShapeParameter::getInstance()->setDrawFlag(KCanvas::KDrawFlag::PentagramDrawFlag);
}

// ��Բ��ť����¼������õ�ǰ���Ʊ�־Ϊ��Բ
void KSVGEditor::onEllipseButtonClicked()
{
    KShapeParameter::getInstance()->setDrawFlag(KCanvas::KDrawFlag::EllipseDrawFlag);
}

void KSVGEditor::onSetCanvasWidth(int width)
{
    ui.m_canvas->setCanvasWidth(width);
}


void KSVGEditor::onSetCanvasHeight(int height)
{
    ui.m_canvas->setCanvasHeight(height);
}


void KSVGEditor::onZoomCanvas(qreal scale)
{
    // ���浱ǰ������λ�úͻ�����С
    QScrollBar* hbar = ui.scrollArea->horizontalScrollBar();
    QScrollBar* vbar = ui.scrollArea->verticalScrollBar();
    QPoint oldScrollPos(hbar->value(), vbar->value());
    QSize oldCanvasSize = ui.m_canvas->size();

    // ����ȫ�����Ų����������ࣩ
    KShapeParameter::getInstance()->setShapeScale(scale);
    KShapeParameter::getInstance()->setCanvasScale(scale);

    // ���û��������ź���������������С��ͼ�Σ�
    ui.m_canvas->zoomCanvas(scale);

    // �����µĹ�����λ�ã�����������λ�ò��䣩
    QSize newCanvasSize = ui.m_canvas->size();
    qreal scaleRatio = scale / m_currentCanvasScale; // �¾����ű����ı�ֵ

    // ����������λ�ã�ʹ������λ�������ź󱣳ִ�����ͬ
    int newHPos = qRound(oldScrollPos.x() * scaleRatio);
    int newVPos = qRound(oldScrollPos.y() * scaleRatio);
    hbar->setValue(qBound(0, newHPos, newCanvasSize.width() - ui.scrollArea->viewport()->width()));
    vbar->setValue(qBound(0, newVPos, newCanvasSize.height() - ui.scrollArea->viewport()->height()));

    // ���µ�ǰ���ű�����¼��UI�ؼ���ʾ
    m_currentCanvasScale = scale;
    ui.m_canvasZoom->setValue(scale); // ����m_canvasZoom�����ű�����QDoubleSpinBox�ؼ�
}


void KSVGEditor::setCanvasColor()
{
    QRgb color = selectColor();
    QString qssStr = QString("background: #%1;").arg(QString::number(color, 16));
    ui.m_canvas->setStyleSheet(qssStr);
    qssStr += "border:none;";
    ui.m_setCanvasColorButton->setStyleSheet(qssStr);
}


void KSVGEditor::onSetShapeBorderWidth(int width)
{
        KShapeParameter::getInstance()->setBorderWidth(width);
        ui.m_canvas->update();
}

void KSVGEditor::onSetBorderWidthSpinBoxValue(int width)
{
    ui.m_shapeBorderWidth->setValue(width);
}

void KSVGEditor::onSetShapeBorderStyle(Qt::PenStyle style)
{
    KShapeParameter::getInstance()->setBorderStyle(style);
    ui.m_canvas->update();
}


void KSVGEditor::onSetShapeBorderColor()
{
    if (m_isSelectShape)
    {
        QRgb color = selectColor();
        KShapeParameter::getInstance()->setBorderColor(color);
        onSetShapeBorderColorButtonColor(color);
        ui.m_canvas->update();
    }
    else
    {
        QMessageBox::warning(this, QStringLiteral("����"), QStringLiteral("δѡ��ͼ�Σ�����ѡ��ͼ��"));
    }
}


void KSVGEditor::onSetShapeBorderColorButtonColor(QRgb color)
{
    QString qssStr = QString("background: #%1;border:none;").arg(QString::number(color, 16));
    ui.m_setShapeBorderColorButton->setStyleSheet(qssStr);
}


void KSVGEditor::onSetShapeColor()
{
    if (m_isSelectShape)
    {
        if (KShapeParameter::getInstance()->getCurrentShape()->getShapeType() == KShapeType::LineShapeType)
        {
            QMessageBox::warning(this, QStringLiteral("����"), QStringLiteral("��ǰ���Ƶ���ֱ�ߣ�ֻ�����ñ߿���ɫ"));
        }
        else
        {
			QRgb color = selectColor();
			KShapeParameter::getInstance()->setShapeColor(color);
			onSetShapeColorButtonColor(color);
			ui.m_canvas->update();
        }
    }
    else
    {
        QMessageBox::warning(this, QStringLiteral("����"), QStringLiteral("δѡ��ͼ�Σ�����ѡ��ͼ��"));
    }
}


void KSVGEditor::onSetShapeColorButtonColor(QRgb color)
{
    QString qssStr = QString("background: #%1;border:none;").arg(QString::number(color, 16));
    ui.m_setShapeColorButton->setStyleSheet(qssStr);
}


void KSVGEditor::onIsSelectShape(bool isSelected)
{
    m_isSelectShape = isSelected;
    if (isSelected)
    {
        ui.m_shapeBorderWidth->setEnabled(true);
        ui.m_shapeBorderStyle->setEnabled(true);
    }
    else
    {
        ui.m_shapeBorderWidth->setEnabled(false);
        ui.m_shapeBorderStyle->setEnabled(false);
    }
}


QRgb KSVGEditor::selectColor()
{
    QColorDialog colorDialog(this);
    QColor color = colorDialog.getColor();
    if (!color.isValid())
        return qRgb(255, 255, 255);
    QRgb rgb = qRgb(color.red(), color.green(), color.blue());
    return rgb;
}

bool KSVGEditor::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == ui.m_shapeBorderWidth &&
        (event->type() == QEvent::MouseButtonPress ||
            event->type() == QEvent::Wheel))
    {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        if (!ui.m_shapeBorderWidth->isEnabled())
        {
            QMessageBox::warning(this, QStringLiteral("����"), QStringLiteral("δѡ��ͼ�Σ�����ѡ��ͼ��"));
            mouseEvent->ignore();
            return true;  
        }
    }
    else if (watched == ui.m_shapeBorderStyle && event->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        if (!ui.m_shapeBorderStyle->isEnabled())
        {
            QMessageBox::warning(this, QStringLiteral("����"), QStringLiteral("δѡ��ͼ�Σ�����ѡ��ͼ��"));
            mouseEvent->ignore();
            return true; 
        }
    }

    return QWidget::eventFilter(watched, event);
}
