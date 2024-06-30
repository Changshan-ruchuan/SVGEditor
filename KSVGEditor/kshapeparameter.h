// -----------------------------------------------------------
// kshapeparameter.h
// �����ߣ� �
// ����ʱ�䣺 2024/5/16
// ���������� ��ɽ��ҵ����SVG�༭�������������ñ������ͼ�β������࣬����ģʽ
// Copyright 2024 Kingsoft
// -----------------------------------------------------------

#ifndef _KSVGEDITOR_KSHAPEPARAMETER_H
#define _KSVGEDITOR_KSHAPEPARAMETER_H

#include "kcanvas.h"

class KShapeParameter
{
public:
	static KShapeParameter *getInstance();
	static void deleteGlobalData();
	void setDrawFlag(KCanvas::KDrawFlag flag);	// ���û滭��־
	KCanvas::KDrawFlag getDrawFlag() const;	// ��ȡ��ǰ�Ļ�ͼ��־
	qreal getShapeScale();	// ��ȡͼ�����ű���
	qreal getCanvasScale();	// ��ȡ�������ű���
	void setShapeScale(qreal scale);	// ����ͼ�����ű���
	void setCanvasScale(qreal scale);	// ���û������ű���
	void setCurrentShape(KShape *shape); //���õ�ǰͼ�ζ���
	KShape *getCurrentShape(); //��ȡ��ǰͼ�ζ���
	void setBorderWidth(int width);	// ����ͼ�α߿���
	int getBorderWidth();	// ��ȡͼ�α߿���
	void setBorderStyle(Qt::PenStyle style);	// ����ͼ�α߿���ʽ
	Qt::PenStyle getBorderStyle();	// ��ȡͼ�α߿���ʽ
	void setBorderColor(QRgb color);	// ����ͼ�α߿���ɫ
	QRgb getBorderColor();	// ��ȡ�߿���ɫ
	void setShapeColor(QRgb color);	// ����ͼ�������ɫ
	QRgb getShapeColor();	// ��ȡͼ����ɫ

private:
	KShapeParameter() = default;
	KShapeParameter(const KShapeParameter &other) = delete;
	KShapeParameter &operator=(const KShapeParameter &other) = delete;
	static KShapeParameter *s_shapeParameterObj;
	KCanvas::KDrawFlag m_drawFlag = KCanvas::KDrawFlag::NoneDrawFlag;
	qreal m_shapeScale = 1.0;	// ͼ�����ű�����Ĭ��1.0
	qreal m_canvasScale = 1.0;	// �������ű�����Ĭ��1.0
	int m_borderWidth = 2.0;	// �߿��ȣ�Ĭ��Ϊ2.0
	Qt::PenStyle m_borderStyle = Qt::SolidLine;	// ͼ�α߿���ʽ��Ĭ��Ϊֱ��
	QRgb m_borderColor = qRgb(0, 0, 0);	// ͼ�α߿���ɫ��Ĭ��Ϊ��ɫ
	QRgb m_shapeColor = qRgb(255, 255, 255);	// ͼ�������ɫ��Ĭ��Ϊ��ɫ
	KShape *m_currentShape = Q_NULLPTR;	// ��ǰͼ�ζ���
};

#endif // _KSVGEDITOR_KSHAPEPARAMETER_H
