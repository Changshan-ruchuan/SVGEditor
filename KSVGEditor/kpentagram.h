// -----------------------------------------------------------
// kpentagram.h
// 创建者： 周斌
// 创建时间： 2025/4/29
// 功能描述： 金山作业三：SVG编辑器——绘制五角星
// Copyright 2025 Kingsoft
// -----------------------------------------------------------

#ifndef _KSVGEDITOR_KPENTAGRAM_H_
#define _KSVGEDITOR_KPENTAGRAM_H_

#include <cmath>

#include "kshape.h"

class KPentagram : public KShape
{
	Q_OBJECT

public:
	explicit KPentagram(QObject *parent = Q_NULLPTR);
	~KPentagram();
	virtual void drawShape(QPaintDevice *parent = Q_NULLPTR) override;
	virtual KShapeType getShapeType() override;
};

#endif	// _KSVGEDITOR_KPENTAGRAM_H_
