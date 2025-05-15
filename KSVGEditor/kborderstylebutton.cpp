#include "kborderstylebutton.h"

KBorderStyleButton::KBorderStyleButton(QWidget *parent)
	: QComboBox(parent)
{
	QStringList borderStyleItems;
	QTextCodec *codec = QTextCodec::codecForName("GBK");
	borderStyleItems
		<< codec->toUnicode("！！")
		<< "--------"
		<< "............."
		<< codec->toUnicode("！，！，！，");

	QListWidget *listWidget = new QListWidget(this);
	for (int i = 0; i < borderStyleItems.count(); i++)
	{
		QListWidgetItem *item = new QListWidgetItem(borderStyleItems.at(i));
		item->setTextAlignment(Qt::AlignCenter);
		listWidget->addItem(item);
	}
	QString qssStr = QString("color: #%1;").arg("FFFFFF");
	listWidget->setStyleSheet(qssStr);
	setModel(listWidget->model());
	setView(listWidget);
	m_pen.setColor(QColor(255, 255, 255));
	m_pen.setWidthF(2.0);
	connect(this, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &KBorderStyleButton::getPenStyle);
}

KBorderStyleButton::~KBorderStyleButton()
{
}

void KBorderStyleButton::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	painter.setPen(m_pen);
	painter.drawLine(QPoint(10, 20), QPoint(100, 20));
}

void KBorderStyleButton::getPenStyle(int index)
{
	switch (index)
	{
	case 0:
		emit setShapePen(Qt::SolidLine);
		setComBoxView(Qt::SolidLine);
		break;
	case 1:
		emit setShapePen(Qt::DashLine);
		setComBoxView(Qt::DashLine);
		break;
	case 2:
		emit setShapePen(Qt::DotLine);
		setComBoxView(Qt::DotLine);
		break;
	case 3:
		emit setShapePen(Qt::DashDotLine);
		setComBoxView(Qt::DashDotLine);
	default:
		break;
	}
}

void KBorderStyleButton::setComBoxView(Qt::PenStyle style)
{
	m_pen.setStyle(style);;
	update();
}
