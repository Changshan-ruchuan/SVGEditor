// -----------------------------------------------------------
// kcanvas.h
// 创建者： 周斌
// 创建时间： 2025/4/29
// 功能描述： 金山作业三：SVG编辑器——创建画布，进行绘画操作
// Copyright 2025 Kingsoft
// -----------------------------------------------------------

#ifndef _KSVGEDITOR_KCANVAS_H_
#define _KSVGEDITOR_KCANVAS_H_

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QMessageBox>
#include <QKeyEvent>
#include "kshape.h"


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
		MouseDrawFlag,	
		LineDrawFlag,	
		CircleDrawFlag,	
		RectDrawFlag,	
		PentagonDrawFlag,	
		HexagonDrawFlag,	
		PentagramDrawFlag,	
		EllipseDrawFlag,         // 新增：椭圆绘制
	};

	explicit KCanvas(QWidget *parent = Q_NULLPTR);
	~KCanvas();

	virtual bool eventFilter(QObject *watched, QEvent *event) override;
	virtual void paintEvent(QPaintEvent *event) override;	
	virtual void mousePressEvent(QMouseEvent *event) override;	
	virtual void mouseMoveEvent(QMouseEvent *event) override;	
	virtual void mouseReleaseEvent(QMouseEvent *event) override;	
	virtual void wheelEvent(QWheelEvent* event) override;
	virtual void keyPressEvent(QKeyEvent* event) override; // 声明键盘事件处理函数
	virtual void copySelectedShape();         // 复制选中图形
	virtual void pasteCopiedShape();          // 粘贴复制的图形
	KShape* m_copiedShape = nullptr; // 保存复制的图形实例
	KShape *getCurrentShape(QPointF pos); 
	QList<KShape*> *getShapeList();

	void setCanvasWidth(int width);		
	void setCanvasHeight(int height);	
	void zoomCanvas(qreal scale);	

	int getCanvasWidth();	
	int getCanvasHeight();	
	void cleanCanvas();	



signals:
	void currentShapeBorderWidth(int width);
	void currentShapeBorderStyle(Qt::PenStyle style);
	void currntShapeBorderColor(QRgb color);
	void currntShapeColor(QRgb color);
	void shapeSelected(bool isSelected);
	void canvasZoomRequested(qreal scale);

private:
	KShape *m_pCurrentShape = Q_NULLPTR;	
	QList<KShape*> *m_pShapeList = Q_NULLPTR;	
	QPointF m_lastPos;	
	bool m_isLPress = false; 
	bool m_isDrawing = false;
	bool m_isSelected = false;
	KDrawFlag m_currentDrawFlag;
	KMoveType m_transType;	
	qreal m_scaleFactor;	
	int m_canvasHeight, m_canvasWidth;	
	bool m_enableSelect;	
	bool m_isCleanCanvas;	
};

#endif // _KSVGEDITOR_KCANVAS_H_
