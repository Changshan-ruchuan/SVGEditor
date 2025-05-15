#include "krect.h"

KRect::KRect(QObject *parent)
	: KShape(parent)
{
}

KRect::~KRect()
{
}


void KRect::drawShape(QPaintDevice *parent)
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
    QRgb shapeColor = getShapeColor();
    painter.setPen(QPen(QColor(borderColor),width,borderStyle));
    painter.setBrush(QBrush(QColor(getShapeColor())));
    painter.drawRect(getShapeRect());
}

KShapeType KRect::getShapeType()
{
    return KShapeType::RectShapeType;
}
