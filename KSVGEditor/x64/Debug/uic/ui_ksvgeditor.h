/********************************************************************************
** Form generated from reading UI file 'ksvgeditor.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KSVGEDITOR_H
#define UI_KSVGEDITOR_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "kborderstylebutton.h"
#include "kcanvas.h"

QT_BEGIN_NAMESPACE

class Ui_KSVGEditorClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QToolButton *m_cleanCanvasBtn;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *m_exportPNGBtn;
    QSpacerItem *horizontalSpacer_3;
    QToolButton *m_saveSVGBtn;
    QSpacerItem *horizontalSpacer;
    QToolButton *m_openSVGBtn;
    QSpacerItem *horizontalSpacer_5;
    QVBoxLayout *verticalLayout;
    QToolButton *m_selectButton;
    QToolButton *m_lineButton;
    QToolButton *m_circleButton;
    QToolButton *m_rectButton;
    QToolButton *m_pentagonButton;
    QToolButton *m_hexagonButton;
    QToolButton *m_pentagramButton;
    QScrollArea *scrollArea;
    KCanvas *m_canvas;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QWidget *m_EditCanvasWidth;
    QLabel *m_widthLabel;
    QSpinBox *m_canvasWidth;
    QWidget *m_EditCanvasWidth_2;
    QLabel *m_widthLabel_2;
    QSpinBox *m_canvasHeight;
    QWidget *m_EditCanvasWidth_3;
    QLabel *m_widthLabel_3;
    QDoubleSpinBox *m_canvasZoom;
    QWidget *m_canvasColor;
    QLabel *m_widthLabel_4;
    QPushButton *m_setCanvasColorButton;
    QGroupBox *groupBox_2;
    QWidget *m_EditCanvasWidth_13;
    QLabel *m_widthLabel_13;
    QSpinBox *m_shapeBorderWidth;
    QWidget *m_EditCanvasWidth_14;
    QLabel *m_widthLabel_14;
    KBorderStyleButton *m_shapeBorderStyle;
    QWidget *m_EditCanvasWidth_15;
    QLabel *m_widthLabel_15;
    QPushButton *m_setShapeBorderColorButton;
    QWidget *m_EditCanvasWidth_16;
    QLabel *m_widthLabel_16;
    QPushButton *m_setShapeColorButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QMainWindow *KSVGEditorClass)
    {
        if (KSVGEditorClass->objectName().isEmpty())
            KSVGEditorClass->setObjectName(QString::fromUtf8("KSVGEditorClass"));
        KSVGEditorClass->resize(1135, 846);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/LOGO.png"), QSize(), QIcon::Normal, QIcon::Off);
        KSVGEditorClass->setWindowIcon(icon);
        KSVGEditorClass->setStyleSheet(QString::fromUtf8("QMainWindow#KSVGEditorClass\n"
"{\n"
"	background-color: rgb(0, 0, 0);\n"
"	color: rgb(255, 255, 255);\n"
"}"));
        centralWidget = new QWidget(KSVGEditorClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_4 = new QSpacerItem(65, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        m_cleanCanvasBtn = new QToolButton(centralWidget);
        m_cleanCanvasBtn->setObjectName(QString::fromUtf8("m_cleanCanvasBtn"));
        QFont font;
        font.setPointSize(11);
        m_cleanCanvasBtn->setFont(font);
        m_cleanCanvasBtn->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"    background: rgb(0, 0, 0);\n"
"    border: none;\n"
"    color: rgb(255, 255, 255);\n"
"}\n"
"QToolButton:hover\n"
"{\n"
"	background-color: rgb(255, 0, 0);\n"
"}\n"
""));

        horizontalLayout_2->addWidget(m_cleanCanvasBtn);

        horizontalSpacer_2 = new QSpacerItem(25, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        m_exportPNGBtn = new QToolButton(centralWidget);
        m_exportPNGBtn->setObjectName(QString::fromUtf8("m_exportPNGBtn"));
        m_exportPNGBtn->setFont(font);
        m_exportPNGBtn->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"    background: rgb(0, 0, 0);\n"
"    border: none;\n"
"    color: rgb(255, 255, 255);\n"
"}\n"
"QToolButton:hover\n"
"{\n"
"	background-color: rgb(255, 0, 0);\n"
"}\n"
""));

        horizontalLayout_2->addWidget(m_exportPNGBtn);

        horizontalSpacer_3 = new QSpacerItem(25, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        m_saveSVGBtn = new QToolButton(centralWidget);
        m_saveSVGBtn->setObjectName(QString::fromUtf8("m_saveSVGBtn"));
        m_saveSVGBtn->setFont(font);
        m_saveSVGBtn->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"    background: rgb(0, 0, 0);\n"
"    border: none;\n"
"    color: rgb(255, 255, 255);\n"
"}\n"
"QToolButton:hover\n"
"{\n"
"	background-color: rgb(255, 0, 0);\n"
"}\n"
""));

        horizontalLayout_2->addWidget(m_saveSVGBtn);

        horizontalSpacer = new QSpacerItem(25, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        m_openSVGBtn = new QToolButton(centralWidget);
        m_openSVGBtn->setObjectName(QString::fromUtf8("m_openSVGBtn"));
        m_openSVGBtn->setFont(font);
        m_openSVGBtn->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"    background: rgb(0, 0, 0);\n"
"    border: none;\n"
"    color: rgb(255, 255, 255);\n"
"}\n"
"QToolButton:hover\n"
"{\n"
"	background-color: rgb(255, 0, 0);\n"
"}\n"
""));

        horizontalLayout_2->addWidget(m_openSVGBtn);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        m_selectButton = new QToolButton(centralWidget);
        m_selectButton->setObjectName(QString::fromUtf8("m_selectButton"));
        m_selectButton->setMinimumSize(QSize(65, 65));
        m_selectButton->setFocusPolicy(Qt::StrongFocus);
        m_selectButton->setStyleSheet(QString::fromUtf8("QToolButton\n"
"{\n"
"	background-color:transparent;  \n"
"	image: url(:/images/select_unchecked.png);\n"
"}\n"
"QToolButton:hover\n"
"{\n"
"  \n"
"	background-color:transparent;  \n"
"	image: url(:/images/select_hover.png);\n"
"}\n"
"QToolButton:checked\n"
"{\n"
" 	background-color:transparent;  \n"
"	image: url(:/images/select_checked.png);\n"
"}\n"
"\n"
"\n"
"\n"
""));
        m_selectButton->setCheckable(true);
        m_selectButton->setAutoExclusive(true);

        verticalLayout->addWidget(m_selectButton);

        m_lineButton = new QToolButton(centralWidget);
        m_lineButton->setObjectName(QString::fromUtf8("m_lineButton"));
        m_lineButton->setMinimumSize(QSize(65, 65));
        m_lineButton->setFocusPolicy(Qt::StrongFocus);
        m_lineButton->setStyleSheet(QString::fromUtf8("QToolButton\n"
"{\n"
"	background-color:transparent;  \n"
"	image: url(:/images/line_unchecked.png);\n"
"}\n"
"QToolButton:hover\n"
"{\n"
"  \n"
"	background-color:transparent;  \n"
"	image: url(:/images/line_hover.png);\n"
"}\n"
"QToolButton:checked\n"
"{\n"
" 	background-color:transparent;  \n"
"	image: url(:/images/line_checked.png);\n"
"}\n"
"\n"
"\n"
"\n"
""));
        m_lineButton->setCheckable(true);
        m_lineButton->setAutoExclusive(true);

        verticalLayout->addWidget(m_lineButton);

        m_circleButton = new QToolButton(centralWidget);
        m_circleButton->setObjectName(QString::fromUtf8("m_circleButton"));
        m_circleButton->setMinimumSize(QSize(65, 65));
        m_circleButton->setFocusPolicy(Qt::StrongFocus);
        m_circleButton->setStyleSheet(QString::fromUtf8("QToolButton\n"
"{\n"
"	background-color:transparent;  \n"
"	image: url(:/images/circle_unchecked.png);\n"
"}\n"
"QToolButton:hover\n"
"{\n"
"  \n"
"	background-color:transparent;  \n"
"	image: url(:/images/circle_hover.png);\n"
"}\n"
"QToolButton:checked\n"
"{\n"
" 	background-color:transparent;  \n"
"	image: url(:/images/circle_checked.png);\n"
"}\n"
"\n"
"\n"
"\n"
""));
        m_circleButton->setCheckable(true);
        m_circleButton->setAutoExclusive(true);

        verticalLayout->addWidget(m_circleButton);

        m_rectButton = new QToolButton(centralWidget);
        m_rectButton->setObjectName(QString::fromUtf8("m_rectButton"));
        m_rectButton->setMinimumSize(QSize(65, 65));
        m_rectButton->setFocusPolicy(Qt::StrongFocus);
        m_rectButton->setStyleSheet(QString::fromUtf8("QToolButton\n"
"{\n"
"	background-color:transparent;  \n"
"	image: url(:/images/rect_unchecked.png);\n"
"}\n"
"QToolButton:hover\n"
"{\n"
"  \n"
"	background-color:transparent;  \n"
"	image: url(:/images/rect_hover.png);\n"
"}\n"
"QToolButton:checked\n"
"{\n"
" 	background-color:transparent;  \n"
"	image: url(:/images/rect_checked.png);\n"
"}\n"
"\n"
"\n"
"\n"
""));
        m_rectButton->setCheckable(true);
        m_rectButton->setAutoExclusive(true);

        verticalLayout->addWidget(m_rectButton);

        m_pentagonButton = new QToolButton(centralWidget);
        m_pentagonButton->setObjectName(QString::fromUtf8("m_pentagonButton"));
        m_pentagonButton->setMinimumSize(QSize(65, 65));
        m_pentagonButton->setFocusPolicy(Qt::StrongFocus);
        m_pentagonButton->setStyleSheet(QString::fromUtf8("QToolButton\n"
"{\n"
"	background-color:transparent;  \n"
"	image: url(:/images/pentagon_unchecked.png);\n"
"}\n"
"QToolButton:hover\n"
"{\n"
"  \n"
"	background-color:transparent;  \n"
"	image: url(:/images/pentagon_hover.png);\n"
"}\n"
"QToolButton:checked\n"
"{\n"
" 	background-color:transparent;  \n"
"	image: url(:/images/pentagon_checked.png);\n"
"}\n"
"\n"
"\n"
"\n"
""));
        m_pentagonButton->setCheckable(true);
        m_pentagonButton->setAutoExclusive(true);

        verticalLayout->addWidget(m_pentagonButton);

        m_hexagonButton = new QToolButton(centralWidget);
        m_hexagonButton->setObjectName(QString::fromUtf8("m_hexagonButton"));
        m_hexagonButton->setMinimumSize(QSize(65, 65));
        m_hexagonButton->setFocusPolicy(Qt::StrongFocus);
        m_hexagonButton->setStyleSheet(QString::fromUtf8("QToolButton\n"
"{\n"
"	background-color:transparent;  \n"
"	image: url(:/images/hexagon_unchecked.png);\n"
"}\n"
"QToolButton:hover\n"
"{\n"
"  \n"
"	background-color:transparent;  \n"
"	image: url(:/images/hexagon_hover.png);\n"
"}\n"
"QToolButton:checked\n"
"{\n"
" 	background-color:transparent;  \n"
"	image: url(:/images/hexagon_checked.png);\n"
"}\n"
"\n"
"\n"
"\n"
""));
        m_hexagonButton->setCheckable(true);
        m_hexagonButton->setAutoExclusive(true);

        verticalLayout->addWidget(m_hexagonButton);

        m_pentagramButton = new QToolButton(centralWidget);
        m_pentagramButton->setObjectName(QString::fromUtf8("m_pentagramButton"));
        m_pentagramButton->setMinimumSize(QSize(65, 65));
        m_pentagramButton->setFocusPolicy(Qt::StrongFocus);
        m_pentagramButton->setStyleSheet(QString::fromUtf8("QToolButton\n"
"{\n"
"	background-color:transparent;  \n"
"	image: url(:/images/pentagram_unchecked.png);\n"
"}\n"
"QToolButton:hover\n"
"{\n"
"  \n"
"	background-color:transparent;  \n"
"	image: url(:/images/pentagram_hover.png);\n"
"}\n"
"QToolButton:checked\n"
"{\n"
" 	background-color:transparent;  \n"
"	image: url(:/images/pentagram_checked.png);\n"
"}\n"
"\n"
"\n"
"\n"
""));
        m_pentagramButton->setCheckable(true);
        m_pentagramButton->setAutoExclusive(true);

        verticalLayout->addWidget(m_pentagramButton);


        gridLayout->addLayout(verticalLayout, 1, 0, 1, 1);

        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setMinimumSize(QSize(650, 650));
        scrollArea->setStyleSheet(QString::fromUtf8("QScrollArea\n"
"{\n"
"	background-color: rgb(63, 63, 60);\n"
"	border: 0;\n"
"}"));
        scrollArea->setWidgetResizable(false);
        scrollArea->setAlignment(Qt::AlignCenter);
        m_canvas = new KCanvas();
        m_canvas->setObjectName(QString::fromUtf8("m_canvas"));
        m_canvas->setGeometry(QRect(58, 82, 600, 600));
        m_canvas->setStyleSheet(QString::fromUtf8("KCanvas\n"
"{\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        scrollArea->setWidget(m_canvas);

        gridLayout->addWidget(scrollArea, 1, 1, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(290, 300));
        groupBox->setMaximumSize(QSize(16777215, 501));
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox\n"
"{\n"
"	color: rgb(255, 255, 255);\n"
"}"));
        m_EditCanvasWidth = new QWidget(groupBox);
        m_EditCanvasWidth->setObjectName(QString::fromUtf8("m_EditCanvasWidth"));
        m_EditCanvasWidth->setGeometry(QRect(10, 40, 130, 111));
        sizePolicy.setHeightForWidth(m_EditCanvasWidth->sizePolicy().hasHeightForWidth());
        m_EditCanvasWidth->setSizePolicy(sizePolicy);
        m_EditCanvasWidth->setStyleSheet(QString::fromUtf8("background-color: rgb(63, 63, 60);"));
        m_widthLabel = new QLabel(m_EditCanvasWidth);
        m_widthLabel->setObjectName(QString::fromUtf8("m_widthLabel"));
        m_widthLabel->setGeometry(QRect(10, 10, 108, 24));
        m_widthLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        m_widthLabel->setAlignment(Qt::AlignCenter);
        m_canvasWidth = new QSpinBox(m_EditCanvasWidth);
        m_canvasWidth->setObjectName(QString::fromUtf8("m_canvasWidth"));
        m_canvasWidth->setGeometry(QRect(10, 40, 111, 71));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        m_canvasWidth->setFont(font1);
        m_canvasWidth->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 255);\n"
"border-width:0;\n"
"border-style:outset"));
        m_canvasWidth->setAlignment(Qt::AlignCenter);
        m_canvasWidth->setMinimum(600);
        m_canvasWidth->setMaximum(999);
        m_canvasWidth->setSingleStep(10);
        m_EditCanvasWidth_2 = new QWidget(groupBox);
        m_EditCanvasWidth_2->setObjectName(QString::fromUtf8("m_EditCanvasWidth_2"));
        m_EditCanvasWidth_2->setGeometry(QRect(150, 40, 130, 111));
        sizePolicy.setHeightForWidth(m_EditCanvasWidth_2->sizePolicy().hasHeightForWidth());
        m_EditCanvasWidth_2->setSizePolicy(sizePolicy);
        m_EditCanvasWidth_2->setStyleSheet(QString::fromUtf8("background-color: rgb(63, 63, 60);"));
        m_widthLabel_2 = new QLabel(m_EditCanvasWidth_2);
        m_widthLabel_2->setObjectName(QString::fromUtf8("m_widthLabel_2"));
        m_widthLabel_2->setGeometry(QRect(10, 10, 108, 24));
        m_widthLabel_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        m_widthLabel_2->setAlignment(Qt::AlignCenter);
        m_canvasHeight = new QSpinBox(m_EditCanvasWidth_2);
        m_canvasHeight->setObjectName(QString::fromUtf8("m_canvasHeight"));
        m_canvasHeight->setGeometry(QRect(10, 40, 111, 71));
        m_canvasHeight->setFont(font1);
        m_canvasHeight->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 255);\n"
"border-width:0;\n"
"border-style:outset"));
        m_canvasHeight->setAlignment(Qt::AlignCenter);
        m_canvasHeight->setMinimum(600);
        m_canvasHeight->setMaximum(999);
        m_canvasHeight->setSingleStep(10);
        m_canvasHeight->setValue(600);
        m_EditCanvasWidth_3 = new QWidget(groupBox);
        m_EditCanvasWidth_3->setObjectName(QString::fromUtf8("m_EditCanvasWidth_3"));
        m_EditCanvasWidth_3->setGeometry(QRect(10, 160, 130, 111));
        sizePolicy.setHeightForWidth(m_EditCanvasWidth_3->sizePolicy().hasHeightForWidth());
        m_EditCanvasWidth_3->setSizePolicy(sizePolicy);
        m_EditCanvasWidth_3->setStyleSheet(QString::fromUtf8("background-color: rgb(63, 63, 60);"));
        m_widthLabel_3 = new QLabel(m_EditCanvasWidth_3);
        m_widthLabel_3->setObjectName(QString::fromUtf8("m_widthLabel_3"));
        m_widthLabel_3->setGeometry(QRect(10, 10, 108, 24));
        m_widthLabel_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        m_widthLabel_3->setAlignment(Qt::AlignCenter);
        m_canvasZoom = new QDoubleSpinBox(m_EditCanvasWidth_3);
        m_canvasZoom->setObjectName(QString::fromUtf8("m_canvasZoom"));
        m_canvasZoom->setGeometry(QRect(20, 40, 101, 71));
        m_canvasZoom->setFont(font1);
        m_canvasZoom->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 255);\n"
"border-width:0;\n"
"border-style:outset"));
        m_canvasZoom->setDecimals(1);
        m_canvasZoom->setMinimum(0.100000000000000);
        m_canvasZoom->setMaximum(10.000000000000000);
        m_canvasZoom->setSingleStep(0.100000000000000);
        m_canvasZoom->setValue(1.000000000000000);
        m_canvasColor = new QWidget(groupBox);
        m_canvasColor->setObjectName(QString::fromUtf8("m_canvasColor"));
        m_canvasColor->setGeometry(QRect(150, 159, 130, 111));
        sizePolicy.setHeightForWidth(m_canvasColor->sizePolicy().hasHeightForWidth());
        m_canvasColor->setSizePolicy(sizePolicy);
        m_canvasColor->setStyleSheet(QString::fromUtf8("background-color: rgb(63, 63, 60);"));
        m_widthLabel_4 = new QLabel(m_canvasColor);
        m_widthLabel_4->setObjectName(QString::fromUtf8("m_widthLabel_4"));
        m_widthLabel_4->setGeometry(QRect(10, 10, 108, 24));
        m_widthLabel_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        m_widthLabel_4->setAlignment(Qt::AlignCenter);
        m_setCanvasColorButton = new QPushButton(m_canvasColor);
        m_setCanvasColorButton->setObjectName(QString::fromUtf8("m_setCanvasColorButton"));
        m_setCanvasColorButton->setGeometry(QRect(10, 50, 111, 46));
        m_setCanvasColorButton->setStyleSheet(QString::fromUtf8("background: rgb(255,255,255);\n"
"border:none;"));

        verticalLayout_2->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        groupBox_2->setMinimumSize(QSize(290, 280));
        groupBox_2->setMaximumSize(QSize(290, 261));
        groupBox_2->setStyleSheet(QString::fromUtf8("QGroupBox\n"
"{\n"
"	color: rgb(255, 255, 255);\n"
"}"));
        m_EditCanvasWidth_13 = new QWidget(groupBox_2);
        m_EditCanvasWidth_13->setObjectName(QString::fromUtf8("m_EditCanvasWidth_13"));
        m_EditCanvasWidth_13->setGeometry(QRect(10, 40, 130, 111));
        sizePolicy.setHeightForWidth(m_EditCanvasWidth_13->sizePolicy().hasHeightForWidth());
        m_EditCanvasWidth_13->setSizePolicy(sizePolicy);
        m_EditCanvasWidth_13->setStyleSheet(QString::fromUtf8("background-color: rgb(63, 63, 60);"));
        m_widthLabel_13 = new QLabel(m_EditCanvasWidth_13);
        m_widthLabel_13->setObjectName(QString::fromUtf8("m_widthLabel_13"));
        m_widthLabel_13->setGeometry(QRect(10, 10, 108, 24));
        m_widthLabel_13->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        m_widthLabel_13->setAlignment(Qt::AlignCenter);
        m_shapeBorderWidth = new QSpinBox(m_EditCanvasWidth_13);
        m_shapeBorderWidth->setObjectName(QString::fromUtf8("m_shapeBorderWidth"));
        m_shapeBorderWidth->setEnabled(false);
        m_shapeBorderWidth->setGeometry(QRect(10, 40, 111, 71));
        m_shapeBorderWidth->setFont(font1);
        m_shapeBorderWidth->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 255);\n"
"border-width:0;\n"
"border-style:outset"));
        m_shapeBorderWidth->setAlignment(Qt::AlignCenter);
        m_shapeBorderWidth->setMinimum(1);
        m_shapeBorderWidth->setMaximum(10);
        m_shapeBorderWidth->setSingleStep(1);
        m_shapeBorderWidth->setValue(2);
        m_EditCanvasWidth_14 = new QWidget(groupBox_2);
        m_EditCanvasWidth_14->setObjectName(QString::fromUtf8("m_EditCanvasWidth_14"));
        m_EditCanvasWidth_14->setGeometry(QRect(150, 40, 130, 111));
        sizePolicy.setHeightForWidth(m_EditCanvasWidth_14->sizePolicy().hasHeightForWidth());
        m_EditCanvasWidth_14->setSizePolicy(sizePolicy);
        m_EditCanvasWidth_14->setStyleSheet(QString::fromUtf8("background-color: rgb(63, 63, 60);"));
        m_widthLabel_14 = new QLabel(m_EditCanvasWidth_14);
        m_widthLabel_14->setObjectName(QString::fromUtf8("m_widthLabel_14"));
        m_widthLabel_14->setGeometry(QRect(10, 10, 108, 24));
        m_widthLabel_14->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        m_widthLabel_14->setAlignment(Qt::AlignCenter);
        m_shapeBorderStyle = new KBorderStyleButton(m_EditCanvasWidth_14);
        m_shapeBorderStyle->setObjectName(QString::fromUtf8("m_shapeBorderStyle"));
        m_shapeBorderStyle->setEnabled(false);
        m_shapeBorderStyle->setGeometry(QRect(10, 40, 111, 61));
        m_shapeBorderStyle->setStyleSheet(QString::fromUtf8(""));
        m_EditCanvasWidth_15 = new QWidget(groupBox_2);
        m_EditCanvasWidth_15->setObjectName(QString::fromUtf8("m_EditCanvasWidth_15"));
        m_EditCanvasWidth_15->setGeometry(QRect(10, 160, 130, 111));
        sizePolicy.setHeightForWidth(m_EditCanvasWidth_15->sizePolicy().hasHeightForWidth());
        m_EditCanvasWidth_15->setSizePolicy(sizePolicy);
        m_EditCanvasWidth_15->setStyleSheet(QString::fromUtf8("background-color: rgb(63, 63, 60);"));
        m_widthLabel_15 = new QLabel(m_EditCanvasWidth_15);
        m_widthLabel_15->setObjectName(QString::fromUtf8("m_widthLabel_15"));
        m_widthLabel_15->setGeometry(QRect(10, 10, 108, 24));
        m_widthLabel_15->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        m_widthLabel_15->setAlignment(Qt::AlignCenter);
        m_setShapeBorderColorButton = new QPushButton(m_EditCanvasWidth_15);
        m_setShapeBorderColorButton->setObjectName(QString::fromUtf8("m_setShapeBorderColorButton"));
        m_setShapeBorderColorButton->setGeometry(QRect(10, 50, 111, 46));
        m_setShapeBorderColorButton->setStyleSheet(QString::fromUtf8("background: rgb(0,0,0);\n"
"border:none;"));
        m_EditCanvasWidth_16 = new QWidget(groupBox_2);
        m_EditCanvasWidth_16->setObjectName(QString::fromUtf8("m_EditCanvasWidth_16"));
        m_EditCanvasWidth_16->setGeometry(QRect(150, 160, 130, 111));
        sizePolicy.setHeightForWidth(m_EditCanvasWidth_16->sizePolicy().hasHeightForWidth());
        m_EditCanvasWidth_16->setSizePolicy(sizePolicy);
        m_EditCanvasWidth_16->setStyleSheet(QString::fromUtf8("background-color: rgb(63, 63, 60);"));
        m_widthLabel_16 = new QLabel(m_EditCanvasWidth_16);
        m_widthLabel_16->setObjectName(QString::fromUtf8("m_widthLabel_16"));
        m_widthLabel_16->setGeometry(QRect(10, 10, 108, 24));
        m_widthLabel_16->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        m_widthLabel_16->setAlignment(Qt::AlignCenter);
        m_setShapeColorButton = new QPushButton(m_EditCanvasWidth_16);
        m_setShapeColorButton->setObjectName(QString::fromUtf8("m_setShapeColorButton"));
        m_setShapeColorButton->setGeometry(QRect(10, 50, 111, 46));
        m_setShapeColorButton->setStyleSheet(QString::fromUtf8("background: rgb(255,255,255);\n"
"border:none;"));

        verticalLayout_2->addWidget(groupBox_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        gridLayout->addLayout(verticalLayout_2, 1, 2, 1, 1);

        KSVGEditorClass->setCentralWidget(centralWidget);

        retranslateUi(KSVGEditorClass);

        QMetaObject::connectSlotsByName(KSVGEditorClass);
    } // setupUi

    void retranslateUi(QMainWindow *KSVGEditorClass)
    {
        KSVGEditorClass->setWindowTitle(QCoreApplication::translate("KSVGEditorClass", "SVG\347\274\226\350\276\221\345\231\250", nullptr));
        m_cleanCanvasBtn->setText(QCoreApplication::translate("KSVGEditorClass", "\346\270\205\347\251\272\347\224\273\345\270\203", nullptr));
#if QT_CONFIG(shortcut)
        m_cleanCanvasBtn->setShortcut(QCoreApplication::translate("KSVGEditorClass", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        m_exportPNGBtn->setText(QCoreApplication::translate("KSVGEditorClass", "\345\257\274\345\207\272PNG", nullptr));
#if QT_CONFIG(shortcut)
        m_exportPNGBtn->setShortcut(QCoreApplication::translate("KSVGEditorClass", "Ctrl+E", nullptr));
#endif // QT_CONFIG(shortcut)
        m_saveSVGBtn->setText(QCoreApplication::translate("KSVGEditorClass", "\344\277\235\345\255\230SVG", nullptr));
#if QT_CONFIG(shortcut)
        m_saveSVGBtn->setShortcut(QCoreApplication::translate("KSVGEditorClass", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        m_openSVGBtn->setText(QCoreApplication::translate("KSVGEditorClass", "\346\211\223\345\274\200SVG", nullptr));
#if QT_CONFIG(shortcut)
        m_openSVGBtn->setShortcut(QCoreApplication::translate("KSVGEditorClass", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        m_selectButton->setText(QString());
        m_lineButton->setText(QString());
        m_circleButton->setText(QString());
        m_rectButton->setText(QString());
        m_pentagonButton->setText(QString());
        m_hexagonButton->setText(QString());
        m_pentagramButton->setText(QString());
        groupBox->setTitle(QCoreApplication::translate("KSVGEditorClass", "\347\224\273\345\270\203\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        m_widthLabel->setText(QCoreApplication::translate("KSVGEditorClass", "\347\224\273\345\270\203\345\256\275\345\272\246", nullptr));
        m_canvasWidth->setSpecialValueText(QString());
        m_widthLabel_2->setText(QCoreApplication::translate("KSVGEditorClass", "\347\224\273\345\270\203\351\253\230\345\272\246", nullptr));
        m_canvasHeight->setSpecialValueText(QString());
        m_widthLabel_3->setText(QCoreApplication::translate("KSVGEditorClass", "\347\274\251\346\224\276\346\257\224\344\276\213", nullptr));
        m_widthLabel_4->setText(QCoreApplication::translate("KSVGEditorClass", "\347\224\273\345\270\203\351\242\234\350\211\262", nullptr));
        m_setCanvasColorButton->setText(QString());
        groupBox_2->setTitle(QCoreApplication::translate("KSVGEditorClass", "\347\273\230\345\233\276\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        m_widthLabel_13->setText(QCoreApplication::translate("KSVGEditorClass", "\350\276\271\346\241\206\345\256\275\345\272\246", nullptr));
        m_shapeBorderWidth->setSpecialValueText(QString());
        m_widthLabel_14->setText(QCoreApplication::translate("KSVGEditorClass", "\350\276\271\346\241\206\346\240\267\345\274\217", nullptr));
        m_widthLabel_15->setText(QCoreApplication::translate("KSVGEditorClass", "\350\276\271\346\241\206\351\242\234\350\211\262", nullptr));
        m_setShapeBorderColorButton->setText(QString());
        m_widthLabel_16->setText(QCoreApplication::translate("KSVGEditorClass", "\345\241\253\345\205\205\351\242\234\350\211\262", nullptr));
        m_setShapeColorButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class KSVGEditorClass: public Ui_KSVGEditorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KSVGEDITOR_H
