// -----------------------------------------------------------
// kellipse.h
// ���ܣ���Բͼ���ඨ��
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

    // ��д���ി�麯��
    void drawShape(QPaintDevice* parent = nullptr) override;
    virtual KShapeType getShapeType() override;
};

#endif // _KSVGEDITOR_KELLIPSE_H_