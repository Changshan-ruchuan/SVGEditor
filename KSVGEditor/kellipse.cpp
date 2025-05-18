// -----------------------------------------------------------
// kellipse.cpp
// ���ܣ���Բͼ����ʵ��
// Copyright 2025 Kingsoft
// -----------------------------------------------------------

#include "kellipse.h"
#include <QPainter>

KEllipse::KEllipse(QObject* parent) : KShape(parent) {}
KEllipse::~KEllipse() {}

void KEllipse::drawShape(QPaintDevice* parent)
{
    if (!parent || !isShapeVaild()) return;

    QPainter painter(parent);
    painter.setRenderHint(QPainter::Antialiasing); // �����

    // Ӧ�����ű任����KShape�̳е��������ӣ�
    QTransform transform;
    transform.scale(getShapeScale(), getShapeScale());
    painter.setTransform(transform);

    // ���û��ʺͻ�ˢ����KShape�̳еı߿�/������ԣ�
    QPen pen(QColor(getBorderColor()), getBorderWidth(), getBorderStyle());
    painter.setPen(pen);
    painter.setBrush(QColor(getShapeColor()));

    // ������Բ��ʹ����ʼ��ͽ����㶨��ľ�����Ϊ��Ӿ���
    QRectF rect = getShapeRect();
    painter.drawEllipse(rect);
}

KShapeType KEllipse::getShapeType()
{
    return KShapeType::EllipseShapeType; // ������Բ����ö��
}