// -----------------------------------------------------------
// kshape.h
// 创建者： 周斌
// 创建时间： 2025/4/29
// 功能描述： 金山作业三：SVG编辑器——图形的基类
// Copyright 2025 Kingsoft
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
	LineShapeType,	
	CircleShapeType,
	RectShapeType,	
	PentagonShapeType,	
	HexagonShapeType,	
	PentagramShapeType,	
	EllipseShapeType,    
};

class KShape : public QObject
{
	Q_OBJECT

public:
	explicit KShape(QObject *parent = Q_NULLPTR);
	virtual ~KShape();

	virtual void drawShape(QPaintDevice *parent = Q_NULLPTR) = 0;
	QPointF getStartPoint() const;	
	QPointF getEndPoint() const;	
	void setStartPoint(const QPointF &point);	
	void setEndPoint(const QPointF &point);	
	bool isShapeVaild() const;	
	virtual KShapeType getShapeType();	
	QRectF getShapeRect();	
	void drawOutline(QPaintDevice *parent = Q_NULLPTR);	
	void drawSelectedHighlight(QPaintDevice* parent = Q_NULLPTR, bool drawControl = true);	
	void move(const QPointF &offset);	
	void moveTop(QPointF pos);	
	void moveBottom(QPointF pos);	
	void moveLeft(QPointF pos);	
	void moveRight(QPointF pos);	
	void moveTopLeft(QPointF pos);	
	void moveTopRight(QPointF pos);	
	void moveBottomLeft(QPointF pos);	
	void moveBottomRight(QPointF pos);	
	void setShapeScale(qreal scale);	
	qreal getShapeScale();	
	void setBorderWidth(int width);	
	void setBorderStyle(Qt::PenStyle style);	
	void setBorderColor(QRgb color);	
	void setShapeColor(QRgb color);	
	QRgb getBorderColor();	
	Qt::PenStyle getBorderStyle();	
	QRgb getShapeColor();	
	int getBorderWidth();	
	const int getControlRectIndex(QPoint pos);

private:
	qreal m_scaleFactor;	
	QPointF m_startPoint; 
	QPointF m_endPoint; 
	int m_borderWidth;	
	Qt::PenStyle m_borderStyle;	
	QRgb m_borderColor;
	QRgb m_shapeColor;	
	QRectF m_controlRect[8];
};

#endif	// _KSVGEDITOR_KSHAPE_H_
