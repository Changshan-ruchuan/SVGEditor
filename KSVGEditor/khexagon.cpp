#include "khexagon.h"

KHexagon::KHexagon(QObject *parent)
	: KShape(parent)
{
}

KHexagon::~KHexagon()
{
}

void KHexagon::drawShape(QPaintDevice *parent)
{
    QPainter painter(parent);
    painter.setRenderHint(QPainter::Antialiasing);
    QTransform transform;
    qreal scaleFactor = getShapeScale();
    transform.scale(scaleFactor, scaleFactor);
    painter.setTransform(transform);
    qreal borderWidth = qreal(getBorderWidth());
    Qt::PenStyle borderStyle = getBorderStyle();
    QColor borderColor = QColor(getBorderColor());
    QColor shapeColor = QColor(getShapeColor());

    painter.setPen(QPen(borderColor, borderWidth, borderStyle));
    painter.setBrush(QBrush(shapeColor));

    QRectF shapeRect = getShapeRect();
    int rectWidth = shapeRect.width();
    int rectHeight = shapeRect.height();
    QPointF points[6];
    points[0].setX(shapeRect.x() + rectWidth * 1.0 / 4.0);
    points[0].setY(shapeRect.y());
	points[1].setX(shapeRect.x() + rectWidth * 3.0 / 4.0);
	points[1].setY(shapeRect.y());
    points[2].setX(shapeRect.right());
    points[2].setY(shapeRect.y() + rectHeight * 1.0 / 2.0);
	points[3].setX(shapeRect.x() + rectWidth * 3.0 / 4.0);
    points[3].setY(shapeRect.bottom());
	points[4].setX(shapeRect.x() + rectWidth * 1.0 / 4.0);
	points[4].setY(shapeRect.bottom());
    points[5].setX(shapeRect.x());
    points[5].setY(shapeRect.y() + rectHeight * 1.0 / 2.0);
    painter.drawPolygon(points, 6);
}

KShapeType KHexagon::getShapeType()
{
    return KShapeType::HexagonShapeType;
}
