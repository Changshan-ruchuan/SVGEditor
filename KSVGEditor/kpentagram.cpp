#include "kpentagram.h"

KPentagram::KPentagram(QObject *parent)
	: KShape(parent)
{
}

KPentagram::~KPentagram()
{
}

void KPentagram::drawShape(QPaintDevice *parent)
{
    QPainter painter(parent);
    painter.setRenderHint(QPainter::Antialiasing);
    QTransform transform;
    qreal scaleFactor = getShapeScale();
    transform.scale(scaleFactor, scaleFactor);
    painter.setTransform(transform);
    qreal width = qreal(getBorderWidth());
    Qt::PenStyle borderStyle = getBorderStyle();
    QColor borderColor = QColor(getBorderColor());
    QColor shapeColor = QColor(getShapeColor());
    painter.setPen(QPen(borderColor, width, borderStyle));
    painter.setBrush(QBrush(shapeColor));
    QRectF shapeRect = getShapeRect();
    qreal centerX = shapeRect.center().x();
    qreal centerY = shapeRect.center().y();
    qreal outerRadius = qMin(shapeRect.width(), shapeRect.height()) / 2.0;
    qreal innerRadius = outerRadius / 2.5;
    QPointF points[10];
    for (int i = 0; i < 10; ++i) 
    {
        double angle = M_PI / 5.0 * i; 
        qreal radius = (i % 2 == 0) ? outerRadius : innerRadius;
        points[i] = QPointF(centerX + radius * cos(angle - M_PI / 2.0),
            centerY + radius * sin(angle - M_PI / 2.0));
    }
    painter.drawPolygon(points, 10);
}

KShapeType KPentagram::getShapeType()
{
    return KShapeType::PentagramShapeType;
}
