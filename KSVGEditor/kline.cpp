#include "kline.h"

KLine::KLine(QObject *parent)
	: KShape(parent)
{
}

KLine::~KLine()
{
}

void KLine::drawShape(QPaintDevice *parent)
{
    QPainter painter(parent);
    painter.setRenderHint(QPainter::Antialiasing);
    QTransform transform;
    qreal scaleFactor = getShapeScale();
    transform.scale(scaleFactor, scaleFactor);
    painter.setTransform(transform);
    qreal width = qreal(getBorderWidth());
    Qt::PenStyle borderStyle = getBorderStyle();
    QRgb borderColor = getBorderColor();
    painter.setPen(QPen(QColor(borderColor), width, borderStyle));
    painter.drawLine(getShapeRect().topLeft(), getShapeRect().bottomRight());
}

KShapeType KLine::getShapeType()
{
    return KShapeType::LineShapeType;
}
