// -----------------------------------------------------------
// kline.h
// �����ߣ� �ܱ�
// ����ʱ�䣺 2025/4/29
// ���������� ��ɽ��ҵ����SVG�༭����������ֱ��
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
