// -----------------------------------------------------------
// kcanvas.h
// �����ߣ� �
// ����ʱ�䣺 2024/5/16
// ���������� ��ɽ��ҵ����SVG�༭�������������������л滭����
// Copyright 2024 Kingsoft
// -----------------------------------------------------------

#ifndef _KSVGEDITOR_KCANVAS_H_
#define _KSVGEDITOR_KCANVAS_H_

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QMessageBox>

#include "kshape.h"

// �ƶ�����
enum class KMoveType
{
	None = 0,
	Move,
	Top,
	Bottom,
	Left,
	Right,
	TopRight,
	TopLeft,
	BottomLeft,
	BottomRight,
};


class KCanvas : public QWidget
{
	Q_OBJECT

public:
	enum class KDrawFlag
	{
		NoneDrawFlag = 0,
		MouseDrawFlag,	// ��깤�ߣ���һ��ѡ�񹤾ߣ�
		LineDrawFlag,	// ֱ��
		CircleDrawFlag,	// Բ��
		RectDrawFlag,	// ������
		PentagonDrawFlag,	// �����
		HexagonDrawFlag,	// ������
		PentagramDrawFlag,	// �����
	};

	explicit KCanvas(QWidget *parent = Q_NULLPTR);
	~KCanvas();

	virtual bool eventFilter(QObject *watched, QEvent *event) override;
	virtual void paintEvent(QPaintEvent *event) override;	// ��д�滭�¼�
	virtual void mousePressEvent(QMouseEvent *event) override;	// ��д��갴���¼�
	virtual void mouseMoveEvent(QMouseEvent *event) override;	// ��д����ƶ��¼�
	virtual void mouseReleaseEvent(QMouseEvent *event) override;	// ��д����ͷ��¼�
	KShape *getCurrentShape(QPointF pos); // ��ȡ��ǰλ��ͼ��
	QList<KShape*> *getShapeList();

	void setCanvasWidth(int width);		// ���û������
	void setCanvasHeight(int height);	// ���û����߶�
	void zoomCanvas(qreal scale);	// ���Ż��������ͼ��

	int getCanvasWidth();	// ��ȡ�������
	int getCanvasHeight();	// ��ȡ�����߶�

	void cleanCanvas();	// ��ջ���

signals:
	void currentShapeBorderWidth(int width);
	void currentShapeBorderStyle(Qt::PenStyle style);
	void currntShapeBorderColor(QRgb color);
	void currntShapeColor(QRgb color);
	void shapeSelected(bool isSelected);

private:
	KShape *m_pCurrentShape = Q_NULLPTR;	// ��ǰ�滭��ͼ��
	QList<KShape*> *m_pShapeList = Q_NULLPTR;	// �����Ѿ��滭�õ�ͼ��
	QPointF m_lastPos;	// ���һ�������
	bool m_isLPress = false; // ���������
	bool m_isDrawing = false; // �Ƿ�Ϊ��ͼ
	bool m_isSelected = false; // �Ƿ�Ϊѡ��
	KDrawFlag m_currentDrawFlag;
	KMoveType m_transType;	// ��¼�ƶ�����
	qreal m_scaleFactor;	// ���ű���
	int m_canvasHeight, m_canvasWidth;	// ������С
	bool m_enableSelect;	// �Ƿ������ק�ƶ����任
	bool m_isCleanCanvas;	// �Ƿ�������ջ�����ť
};

#endif // _KSVGEDITOR_KCANVAS_H_
