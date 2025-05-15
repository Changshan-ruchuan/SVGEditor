// -----------------------------------------------------------
// khexagon.h
// �����ߣ� �ܱ�
// ����ʱ�䣺 2025/4/29
// ���������� ��ɽ��ҵ����SVG�༭����������������
// Copyright 2025 Kingsoft
// -----------------------------------------------------------

#ifndef _KSVGEDITOR_KHEXAGON_H_
#define _KSVGEDITOR_KHEXAGON_H_

#include <cmath>

#include "kshape.h"

class KHexagon : public KShape
{
	Q_OBJECT

public:
	explicit KHexagon(QObject *parent = Q_NULLPTR);
	~KHexagon();
	virtual void drawShape(QPaintDevice *parent = Q_NULLPTR) override;
	virtual KShapeType getShapeType() override;
};

#endif	// _KSVGEDITOR_KHEXAGON_H_
