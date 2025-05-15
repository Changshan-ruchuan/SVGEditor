#include "kpentagon.h"

KPentagon::KPentagon(QObject *parent)
	: KShape(parent)
{
}

KPentagon::~KPentagon()
{
}

void KPentagon::drawShape(QPaintDevice *parent)
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
    painter.setPen(QPen(QColor(borderColor), width, borderStyle));
    painter.setBrush(QBrush(QColor(getShapeColor())));
    QRectF shapeRect = getShapeRect();
    int rectWidth = shapeRect.width();
    int rectHeight = shapeRect.height();
	QPointF points[5];
    points[0] = QPointF(shapeRect.x() + rectWidth / 2.0, shapeRect.y());
    points[1] = QPointF(shapeRect.right(), shapeRect.y() + rectHeight / 2.0);
    points[2] = QPointF(shapeRect.x() + rectWidth * 3.0 / 4.0, shapeRect.bottom());
    points[3] = QPointF(shapeRect.x() + rectWidth / 4.0, shapeRect.bottom());
    points[4] = QPointF(shapeRect.x(), shapeRect.y() + rectHeight / 2.0);
    painter.drawPolygon(points,5);
}

KShapeType KPentagon::getShapeType()
{
    return KShapeType::PentagonShapeType;
}
