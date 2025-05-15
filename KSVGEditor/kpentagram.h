// -----------------------------------------------------------
// kpentagram.h
// �����ߣ� �ܱ�
// ����ʱ�䣺 2025/4/29
// ���������� ��ɽ��ҵ����SVG�༭���������������
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
