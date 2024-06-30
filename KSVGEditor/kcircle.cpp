#include "kcircle.h"

KCircle::KCircle(QObject *parent)
	: KShape(parent)
{
}

KCircle::~KCircle()
{
}

void KCircle::drawShape(QPaintDevice *parent)
{
    QPainter painter(parent);
    // ���������
    painter.setRenderHint(QPainter::Antialiasing);
    // Ӧ�����ű任
    QTransform transform;
    qreal scaleFactor = getShapeScale();
    transform.scale(scaleFactor, scaleFactor);
    painter.setTransform(transform);
    // ��ȡ�߿��ȡ���ʽ����ɫ�������ɫ
    qreal width = qreal(getBorderWidth());
    Qt::PenStyle borderStyle = getBorderStyle();
    QRgb borderColor = getBorderColor();
    QRgb shapeColor = getShapeColor();
    // ���û���
    painter.setPen(QPen(QColor(borderColor), width, borderStyle));
    painter.setBrush(QBrush(QColor(getShapeColor())));
    painter.drawEllipse(getShapeRect());
}

KShapeType KCircle::getShapeType()
{
    return KShapeType::CircleShapeType;
}
