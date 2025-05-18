// -----------------------------------------------------------
// kellipse.h
// 功能：椭圆图形类定义
// Copyright 2025 Kingsoft
// -----------------------------------------------------------

#ifndef _KSVGEDITOR_KELLIPSE_H_
#define _KSVGEDITOR_KELLIPSE_H_

#include "kshape.h"

class KEllipse : public KShape
{
    Q_OBJECT

public:
    explicit KEllipse(QObject* parent = nullptr);
    ~KEllipse();

    // 重写父类纯虚函数
    void drawShape(QPaintDevice* parent = nullptr) override;
    virtual KShapeType getShapeType() override;
};

#endif // _KSVGEDITOR_KELLIPSE_H_