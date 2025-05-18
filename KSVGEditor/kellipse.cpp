// -----------------------------------------------------------
// kellipse.cpp
// 功能：椭圆图形类实现
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
    painter.setRenderHint(QPainter::Antialiasing); 
    QTransform transform;
    transform.scale(getShapeScale(), getShapeScale());
    painter.setTransform(transform);
    QPen pen(QColor(getBorderColor()), getBorderWidth(), getBorderStyle());
    painter.setPen(pen);
    painter.setBrush(QColor(getShapeColor()));
    QRectF rect = getShapeRect();
    painter.drawEllipse(rect);
}

KShapeType KEllipse::getShapeType()
{
    return KShapeType::EllipseShapeType; 
}