// -----------------------------------------------------------
// kborderstylebutton.h
// �����ߣ� �
// ����ʱ�䣺 2024/5/16
// ���������� ��ɽ��ҵ����SVG�༭�������Զ���ѡ��߽����QComBox
// Copyright 2024 Kingsoft
// -----------------------------------------------------------

#ifndef _KSVGEDITOR_KBORDERSTYLEBUTTON_H_
#define _KSVGEDITOR_KBORDERSTYLEBUTTON_H_

#include <QComboBox>
#include <QListWidget>
#include <QPen>
#include <QPainter>
#include <QTextCodec>

class KBorderStyleButton : public QComboBox
{
	Q_OBJECT

public:
	explicit KBorderStyleButton(QWidget *parent);
	~KBorderStyleButton();

	void paintEvent(QPaintEvent *event);
	void getPenStyle(int index);
	void setComBoxView(Qt::PenStyle style);

signals:
	void setShapePen(Qt::PenStyle);

private:
	QPen m_pen;
};

#endif	// _KSVGEDITOR_KBORDERSTYLEBUTTON_H_
