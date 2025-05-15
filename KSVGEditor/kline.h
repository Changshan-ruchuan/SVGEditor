// -----------------------------------------------------------
// kline.h
// 创建者： 周斌
// 创建时间： 2025/4/29
// 功能描述： 金山作业三：SVG编辑器——绘制直线
// Copyright 2025 Kingsoft
// -----------------------------------------------------------

#ifndef _KSVGEDITOR_KLINE_H_
#define _KSVGEDITOR_KLINE_H_

#include "kshape.h"

class KLine : public KShape
{
	Q_OBJECT

public:
	explicit KLine(QObject *parent = Q_NULLPTR);
	~KLine();
	virtual void drawShape(QPaintDevice *parent = Q_NULLPTR) override;
	virtual KShapeType getShapeType() override;
};

#endif	// _KSVGEDITOR_KLINE_H_
