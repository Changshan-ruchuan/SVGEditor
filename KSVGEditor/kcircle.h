// -----------------------------------------------------------
// kcircle.h
// �����ߣ� �ܱ�
// ����ʱ�䣺 2025/4/29
// ���������� ��ɽ��ҵ����SVG�༭����������Բ��
// Copyright 2025 Kingsoft
// -----------------------------------------------------------

#ifndef _KSVGEDITOR_KCIRCLE_H_
#define _KSVGEDITOR_KCIRCLE_H_

#include "kshape.h"

class KCircle : public KShape
{
	Q_OBJECT

public:
	explicit KCircle(QObject *parent = Q_NULLPTR);
	~KCircle();
	virtual void drawShape(QPaintDevice *parent = Q_NULLPTR) override;
	virtual KShapeType getShapeType() override;
};

#endif // _KSVGEDITOR_KCIRCLE_H_
