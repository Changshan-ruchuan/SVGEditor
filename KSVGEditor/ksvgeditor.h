// -----------------------------------------------------------
// ksvgeditor.h
// �����ߣ� �
// ����ʱ�䣺 2024/5/16
// ���������� ��ɽ��ҵ����SVG�༭������������
// Copyright 2024 Kingsoft
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
    void moveCanvasToCenter();  // �������ƶ���QScrollArea�м�
    // ������������ز���
    void onCleanCanvasClicked();
    void onExportPNGBtnClicked();
    // ��๤������ز���
    void onSelectButtonClicked();
    void onLineButtonClicked();
    void onCircleButtonClicked();
    void onRectButtonClicked();
    void onPentagonButtonClicked();
    void onHexagonButtonClicked();
    void onPentagramButtonClicked();
    // �Ҳ໭��������ز���
    void onSetCanvasWidth(int width);   // ���û������
    void onSetCanvasHeight(int height);   // ���û����߶�
    void onZoomCanvas(qreal scale);   // ���Ż���
    void setCanvasColor();  // ���û�����ɫ
    // �Ҳ�ͼ�β�����ز���
    void onSetShapeBorderWidth(int width);  // ����ͼ�α߿���
    void onSetBorderWidthSpinBoxValue(int width);   // ���õ���ͼ�α߿��ȵ�SpinBox��ֵ
    void onSetShapeBorderStyle(Qt::PenStyle style); // ����ͼ�α߿���ʽ
    void onSetShapeBorderColor();   // ����ͼ�α߿���ɫ
    void onSetShapeBorderColorButtonColor(QRgb color);  // ���õ���ͼ�α߿���ɫ�İ�ť��ɫ
    void onSetShapeColor();   // ����ͼ�������ɫ
    void onSetShapeColorButtonColor(QRgb color);  // ���õ���ͼ�������ɫ�İ�ť��ɫ
    void onIsSelectShape(bool isSelected);  // �Ƿ�ѡ��ͼ�εĲۺ���

protected:
    QRgb selectColor(); // ����ɫѡ��Ի���ѡ��һ����ɫ
    virtual bool eventFilter(QObject *watched, QEvent *event) override;

signals:
    void onDrawingFlagChanged(KCanvas::KDrawFlag drawFlag);

private:
    Ui::KSVGEditorClass ui;
    double m_currentCanvasScale; // ������ǰ�����ű���
    bool m_isSelectShape; // �Ƿ�ѡ����ͼ��
    int m_preShapeBorderWidth;  // ��һ��ѡ���ͼ�α߿���
    bool m_isRestoreWidth;  // �Ƿ�ָ�ͼ�α߿��ֵ
};

#endif // _K_KSVGEDITOR_H_
