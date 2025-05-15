// -----------------------------------------------------------
// kshapeparameter.h
// 创建者： 周斌
// 创建时间： 2025/4/29
// 功能描述： 金山作业三：SVG编辑器——用来设置保存绘制图形参数的类，单例模式
// Copyright 2025 Kingsoft
// -----------------------------------------------------------

#ifndef _KSVGEDITOR_KSHAPEPARAMETER_H
#define _KSVGEDITOR_KSHAPEPARAMETER_H

#include "kcanvas.h"

class KShapeParameter
{
public:
	static KShapeParameter *getInstance();
	static void deleteGlobalData();
	void setDrawFlag(KCanvas::KDrawFlag flag);	
	KCanvas::KDrawFlag getDrawFlag() const;	
	qreal getShapeScale();	
	qreal getCanvasScale();	
	void setShapeScale(qreal scale);	
	void setCanvasScale(qreal scale);	
	void setCurrentShape(KShape *shape); 
	KShape *getCurrentShape(); 
	void setBorderWidth(int width);	
	int getBorderWidth();	
	void setBorderStyle(Qt::PenStyle style);	
	Qt::PenStyle getBorderStyle();	
	void setBorderColor(QRgb color);	
	QRgb getBorderColor();	
	void setShapeColor(QRgb color);	
	QRgb getShapeColor();	

private:
	KShapeParameter() = default;
	KShapeParameter(const KShapeParameter &other) = delete;
	KShapeParameter &operator=(const KShapeParameter &other) = delete;
	static KShapeParameter *s_shapeParameterObj;
	KCanvas::KDrawFlag m_drawFlag = KCanvas::KDrawFlag::NoneDrawFlag;
	qreal m_shapeScale = 1.0;	
	qreal m_canvasScale = 1.0;	
	int m_borderWidth = 2.0;	
	Qt::PenStyle m_borderStyle = Qt::SolidLine;	
	QRgb m_borderColor = qRgb(0, 0, 0);	
	QRgb m_shapeColor = qRgb(255, 255, 255);	
	KShape *m_currentShape = Q_NULLPTR;	
};

#endif // _KSVGEDITOR_KSHAPEPARAMETER_H
