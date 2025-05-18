// -----------------------------------------------------------
// ksvgeditor.h
// �����ߣ� �ܱ�
// ����ʱ�䣺 2025/4/29
// ���������� ��ɽ��ҵ����SVG�༭������������
// Copyright 2025 Kingsoft
// -----------------------------------------------------------

#ifndef _K_KSVGEDITOR_H_
#define _K_KSVGEDITOR_H_

#include <QtWidgets/QMainWindow>
#include <QColorDialog>
#include <QMessageBox>
#include <QFileDialog>
#include <QXmlStreamWriter>
#include <QImage>
#include <QPixmap>

#include "ui_ksvgeditor.h"
#include "kshapeparameter.h"

class KSVGEditor : public QMainWindow
{
    Q_OBJECT

public:
    explicit KSVGEditor(QWidget *parent = Q_NULLPTR);
    void moveCanvasToCenter();  
    void onCleanCanvasClicked();
    void onExportPNGBtnClicked();
    void onSelectButtonClicked();
    void onLineButtonClicked();
    void onCircleButtonClicked();
    void onRectButtonClicked();
    void onPentagonButtonClicked();
    void onHexagonButtonClicked();
    void onPentagramButtonClicked();
    void onSetCanvasWidth(int width);  
    void onSetCanvasHeight(int height);  
    void onZoomCanvas(qreal scale);   
    void setCanvasColor();  
    void onSetShapeBorderWidth(int width);  
    void onSetBorderWidthSpinBoxValue(int width);   
    void onSetShapeBorderStyle(Qt::PenStyle style); 
    void onSetShapeBorderColor();   
    void onSetShapeBorderColorButtonColor(QRgb color);  
    void onSetShapeColor();  
    void onSetShapeColorButtonColor(QRgb color);  
    void onIsSelectShape(bool isSelected);  
    void onEllipseButtonClicked(); 


protected:
    QRgb selectColor(); 
    virtual bool eventFilter(QObject *watched, QEvent *event) override;

signals:
    void onDrawingFlagChanged(KCanvas::KDrawFlag drawFlag);

private:
    Ui::KSVGEditorClass ui;
    double m_currentCanvasScale; 
    bool m_isSelectShape; 
    int m_preShapeBorderWidth;  
    bool m_isRestoreWidth;  
};

#endif // _K_KSVGEDITOR_H_
