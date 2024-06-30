// -----------------------------------------------------------
// kshape.h
// �����ߣ� �
// ����ʱ�䣺 2024/5/16
// ���������� ��ɽ��ҵ����SVG�༭������ͼ�εĻ���
// Copyright 2024 Kingsoft
// -----------------------------------------------------------

#ifndef _KSVGEDITOR_KSHAPE_H_
#define _KSVGEDITOR_KSHAPE_H_

#include <QObject>
#include <QPoint>
#include <QPainter>
#include <QPaintDevice>

enum class KShapeType
{
	None = 0,
	LineShapeType,	// ֱ��
	CircleShapeType,	// Բ��
	RectShapeType,	// ������
	PentagonShapeType,	// �����
	HexagonShapeType,	// ������
	PentagramShapeType,	// �����
};

class KShape : public QObject
{
	Q_OBJECT

public:
	explicit KShape(QObject *parent = Q_NULLPTR);
	virtual ~KShape();

	virtual void drawShape(QPaintDevice *parent = Q_NULLPTR) = 0;
	QPointF getStartPoint() const;	// ��ȡ�滭��ʼ�����
	QPointF getEndPoint() const;	// ��ȡ�滭���������
	void setStartPoint(const QPointF &point);	// ���û滭��ʼ�����
	void setEndPoint(const QPointF &point);	// ���û滭���������
	bool isShapeVaild() const;	// �жϻ滭�Ƿ�Ϸ�
	virtual KShapeType getShapeType();	// ��ȡ��ͼ������
	QRectF getShapeRect();	// ��ȡͼ�εı߽����
	void drawOutline(QPaintDevice *parent = Q_NULLPTR);	// �����ⲿ���
	void drawSelectedHighlight(QPaintDevice* parent = Q_NULLPTR, bool drawControl = true);	// ѡ��ͼ�εĸ�������
	void move(const QPointF &offset);	// �ƶ�ͼ��
	void moveTop(QPointF pos);	// �ƶ��ϱ߽�
	void moveBottom(QPointF pos);	// �ƶ��±߽�
	void moveLeft(QPointF pos);	// �ƶ���߽�
	void moveRight(QPointF pos);	// �ƶ��ұ߽�
	void moveTopLeft(QPointF pos);	// �ƶ����Ͻ�
	void moveTopRight(QPointF pos);	// �ƶ����Ͻ�
	void moveBottomLeft(QPointF pos);	// �ƶ����½�
	void moveBottomRight(QPointF pos);	// �ƶ����½�
	void setShapeScale(qreal scale);	// ����ͼ�ε����ű���
	qreal getShapeScale();	// ��ȡͼ�ε����ű���
	void setBorderWidth(int width);	// ����ͼ�εı߿���
	void setBorderStyle(Qt::PenStyle style);	// ����ͼ�εı߿���ʽ
	void setBorderColor(QRgb color);	// ����ͼ�εı߿���ɫ
	void setShapeColor(QRgb color);	// ����ͼ�ε������ɫ
	QRgb getBorderColor();	// ��ȡͼ�εı߿���ɫ
	Qt::PenStyle getBorderStyle();	// ��ȡͼ�εı߿���ʽ
	QRgb getShapeColor();	// ��ȡͼ�ε������ɫ
	int getBorderWidth();	// ��ȡͼ�εı߿���
	const int getControlRectIndex(QPoint pos);	// ���ݵ����λ�÷��ؿ��Ƶ���±�

private:
	qreal m_scaleFactor;	// ���ű���
	QPointF m_startPoint; // ��ʼ����
	QPointF m_endPoint; // ��������
	int m_borderWidth;	// �߿���
	Qt::PenStyle m_borderStyle;	// �߿���ʽ
	QRgb m_borderColor;// �߿���ɫ
	QRgb m_shapeColor;	// �����ɫ
	QRectF m_controlRect[8];	// ���εİ˸����Ƶ㣬�����Ͻǿ�ʼ˳ʱ������
};

#endif	// _KSVGEDITOR_KSHAPE_H_
