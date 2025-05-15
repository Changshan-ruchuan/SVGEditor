#include "ksvgeditor.h"

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
    cleanReply = QMessageBox::question(this, QStringLiteral("清空画布"), QStringLiteral("确定要清空画布吗"),
        QMessageBox::Yes | QMessageBox::No);
    if (cleanReply == QMessageBox::Yes)
    {
		QMessageBox::StandardButton savePNGReply;
        savePNGReply = QMessageBox::question(this, QStringLiteral("导出PNG"), QStringLiteral("需要导出PNG文件吗"),
			QMessageBox::Yes | QMessageBox::No);
        if (savePNGReply == QMessageBox::Yes)
            onExportPNGBtnClicked();
        ui.m_canvas->cleanCanvas();
    }   
}


void KSVGEditor::onExportPNGBtnClicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, QStringLiteral("导出PNG"), "", "PNG Files (*.png)");
	if (!fileName.isEmpty())
    {
		QPixmap pixmap(ui.m_canvas->size());
		ui.m_canvas->render(&pixmap);
        if (pixmap.save(fileName))
            QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("导出PNG成功，路径为") + fileName);
        else
            QMessageBox::warning(this, QStringLiteral("错误"), QStringLiteral("导出失败，请重试"));
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
    KShapeParameter::getInstance()->setShapeScale(scale);
    KShapeParameter::getInstance()->setCanvasScale(scale);
    ui.m_canvas->zoomCanvas(scale);
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
        QMessageBox::warning(this, QStringLiteral("警告"), QStringLiteral("未选中图形，请先选择图形"));
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
            QMessageBox::warning(this, QStringLiteral("警告"), QStringLiteral("当前绘制的是直线，只能设置边框颜色"));
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
        QMessageBox::warning(this, QStringLiteral("警告"), QStringLiteral("未选中图形，请先选择图形"));
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
            QMessageBox::warning(this, QStringLiteral("警告"), QStringLiteral("未选中图形，请先选择图形"));
            mouseEvent->ignore();
            return true;  
        }
    }
    else if (watched == ui.m_shapeBorderStyle && event->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        if (!ui.m_shapeBorderStyle->isEnabled())
        {
            QMessageBox::warning(this, QStringLiteral("警告"), QStringLiteral("未选中图形，请先选择图形"));
            mouseEvent->ignore();
            return true; 
        }
    }

    return QWidget::eventFilter(watched, event);
}
