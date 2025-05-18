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
    painter.setRenderHint(QPainter::Antialiasing); // 抗锯齿

    // 应用缩放变换（从KShape继承的缩放因子）
    QTransform transform;
    transform.scale(getShapeScale(), getShapeScale());
    painter.setTransform(transform);

    // 设置画笔和画刷（从KShape继承的边框/填充属性）
    QPen pen(QColor(getBorderColor()), getBorderWidth(), getBorderStyle());
    painter.setPen(pen);
    painter.setBrush(QColor(getShapeColor()));

    // 绘制椭圆：使用起始点和结束点定义的矩形作为外接矩形
    QRectF rect = getShapeRect();
    painter.drawEllipse(rect);
}

KShapeType KEllipse::getShapeType()
{
    return KShapeType::EllipseShapeType; // 返回椭圆类型枚举
}