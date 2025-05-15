// -----------------------------------------------------------
// kborderstylebutton.h
// 创建者： 周斌
// 创建时间： 2025/4/29
// 功能描述： 金山作业三：SVG编辑器——自定义选择边界风格的QComBox
// Copyright 2025 Kingsoft
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
