// -----------------------------------------------------------
// kline.h
// �����ߣ� �
// ����ʱ�䣺 2024/5/16
// ���������� ��ɽ��ҵ����SVG�༭����������ֱ��
// Copyright 2024 Kingsoft
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
	// ����ֱ��
	virtual void drawShape(QPaintDevice *parent = Q_NULLPTR) override;
	virtual KShapeType getShapeType() override;
};

#endif	// _KSVGEDITOR_KLINE_H_
