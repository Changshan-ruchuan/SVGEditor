// -----------------------------------------------------------
// kcircle.h
// �����ߣ� �
// ����ʱ�䣺 2024/5/16
// ���������� ��ɽ��ҵ����SVG�༭����������Բ��
// Copyright 2024 Kingsoft
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
	// ����Բ��
	virtual void drawShape(QPaintDevice *parent = Q_NULLPTR) override;
	virtual KShapeType getShapeType() override;
};

#endif // _KSVGEDITOR_KCIRCLE_H_
