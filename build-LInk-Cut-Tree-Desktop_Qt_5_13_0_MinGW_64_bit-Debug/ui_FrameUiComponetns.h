/********************************************************************************
** Form generated from reading UI file 'FrameUiComponetns.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRAMEUICOMPONETNS_H
#define UI_FRAMEUICOMPONETNS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FrameUiComponetns
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayoutTopPart;
    QHBoxLayout *horizontalLayoutForScrollArea;
    QScrollArea *scrollAreaLog;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_2;
    QLabel *labelSequence;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButtonHideLog;
    QPushButton *pushButtonClearLog;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_4;
    QGridLayout *gridLayoutPopUpMenu;
    QFrame *framePresetsList;
    QGridLayout *gridLayout_2;
    QPushButton *pushButtonPreset7;
    QPushButton *pushButtonPreset6;
    QPushButton *pushButtonPreset5;
    QPushButton *pushButtonPreset4;
    QPushButton *pushButtonPreset3;
    QPushButton *pushButtonPreset2;
    QPushButton *pushButtonPreset1;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_3;
    QGridLayout *gridLayoutPopUpDialog;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_5;
    QFrame *framePopUpDialog;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_7;
    QFrame *frame_1234;
    QGridLayout *gridLayout_3;
    QSpinBox *spinBoxAddValue;
    QPushButton *pushButtonAdd;
    QLabel *label_3;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_7;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonReset;
    QFrame *line;
    QPushButton *pushButtonOpenPresets;
    QPushButton *pushButtonShowDelta;
    QPushButton *pushButtonSwitchTree;
    QFrame *frameOperationsButtons;
    QGridLayout *gridLayout;
    QPushButton *pushButtonFindLCA;
    QPushButton *pushButtonLink;
    QPushButton *pushButtonOpenAddDialog;
    QPushButton *pushButtonCut;
    QPushButton *pushButtonExpose;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QSlider *horizontalSliderAnimationSpeed;
    QPushButton *pushButtonEndOperation;
    QPushButton *pushButtonMakeStep;

    void setupUi(QFrame *FrameUiComponetns)
    {
        if (FrameUiComponetns->objectName().isEmpty())
            FrameUiComponetns->setObjectName(QString::fromUtf8("FrameUiComponetns"));
        FrameUiComponetns->resize(1478, 650);
        verticalLayout = new QVBoxLayout(FrameUiComponetns);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayoutTopPart = new QGridLayout();
        gridLayoutTopPart->setObjectName(QString::fromUtf8("gridLayoutTopPart"));
        horizontalLayoutForScrollArea = new QHBoxLayout();
        horizontalLayoutForScrollArea->setObjectName(QString::fromUtf8("horizontalLayoutForScrollArea"));
        scrollAreaLog = new QScrollArea(FrameUiComponetns);
        scrollAreaLog->setObjectName(QString::fromUtf8("scrollAreaLog"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollAreaLog->sizePolicy().hasHeightForWidth());
        scrollAreaLog->setSizePolicy(sizePolicy);
        scrollAreaLog->setMaximumSize(QSize(450, 16777215));
        scrollAreaLog->setStyleSheet(QString::fromUtf8("background-color: rgba(0,0,0,0);\n"
"border: 0;"));
        scrollAreaLog->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollAreaLog->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollAreaLog->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 450, 190));
        verticalLayout_4 = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(scrollAreaWidgetContents_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(100, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("MS Reference Sans Serif"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(243, 234, 226);"));

        verticalLayout_4->addWidget(label_2);

        labelSequence = new QLabel(scrollAreaWidgetContents_2);
        labelSequence->setObjectName(QString::fromUtf8("labelSequence"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labelSequence->sizePolicy().hasHeightForWidth());
        labelSequence->setSizePolicy(sizePolicy1);
        labelSequence->setMinimumSize(QSize(300, 0));
        labelSequence->setMaximumSize(QSize(16777215, 16777215));
        QFont font1;
        font1.setFamily(QString::fromUtf8("MS Reference Sans Serif"));
        font1.setPointSize(10);
        labelSequence->setFont(font1);
        labelSequence->setStyleSheet(QString::fromUtf8("QLabel {\n"
"color: rgba(243, 234, 226, 210);\n"
"}\n"
"QLabel::hover {\n"
"background-color: rgba(255,255,255,20);\n"
"}"));
        labelSequence->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout_4->addWidget(labelSequence);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, -1, -1, 0);
        pushButtonHideLog = new QPushButton(scrollAreaWidgetContents_2);
        pushButtonHideLog->setObjectName(QString::fromUtf8("pushButtonHideLog"));
        sizePolicy.setHeightForWidth(pushButtonHideLog->sizePolicy().hasHeightForWidth());
        pushButtonHideLog->setSizePolicy(sizePolicy);
        pushButtonHideLog->setMinimumSize(QSize(100, 30));
        pushButtonHideLog->setMaximumSize(QSize(100, 30));
        QFont font2;
        font2.setPointSize(10);
        pushButtonHideLog->setFont(font2);
        pushButtonHideLog->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: rgb(243, 234, 226);\n"
"background-color: transparent;\n"
"\n"
"border-radius: 5px;\n"
"border: 2px solid;\n"
"border-color: rgb(243, 234, 226);\n"
"}\n"
"QPushButton:enabled:hover {\n"
"background-color: rgb(0, 125, 176);\n"
"}\n"
"QPushButton:enabled:pressed {\n"
"background-color:  rgb(0, 105, 156);\n"
"}\n"
"QPushButton:disabled {\n"
"border-color: rgba(243, 234, 226, 100);\n"
"color:  rgba(243, 234, 226, 100);\n"
"background-color: rgba(255, 255, 255, 20);\n"
"}"));

        horizontalLayout_2->addWidget(pushButtonHideLog);

        pushButtonClearLog = new QPushButton(scrollAreaWidgetContents_2);
        pushButtonClearLog->setObjectName(QString::fromUtf8("pushButtonClearLog"));
        sizePolicy.setHeightForWidth(pushButtonClearLog->sizePolicy().hasHeightForWidth());
        pushButtonClearLog->setSizePolicy(sizePolicy);
        pushButtonClearLog->setMinimumSize(QSize(100, 30));
        pushButtonClearLog->setMaximumSize(QSize(100, 30));
        pushButtonClearLog->setFont(font2);
        pushButtonClearLog->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: rgb(243, 234, 226);\n"
"background-color: transparent;\n"
"\n"
"border-radius: 5px;\n"
"border: 2px solid;\n"
"border-color: rgb(243, 234, 226);\n"
"}\n"
"QPushButton:enabled:hover {\n"
"background-color:  rgb(182, 47, 68);\n"
"}\n"
"QPushButton:enabled:pressed {\n"
"background-color:  rgb(152, 27, 48);\n"
"}"));

        horizontalLayout_2->addWidget(pushButtonClearLog);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);


        verticalLayout_4->addLayout(horizontalLayout_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_4->addItem(verticalSpacer_3);

        verticalSpacer_2 = new QSpacerItem(20, 336, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);

        scrollAreaLog->setWidget(scrollAreaWidgetContents_2);

        horizontalLayoutForScrollArea->addWidget(scrollAreaLog);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayoutForScrollArea->addItem(horizontalSpacer_4);


        gridLayoutTopPart->addLayout(horizontalLayoutForScrollArea, 0, 0, 2, 1);

        gridLayoutPopUpMenu = new QGridLayout();
        gridLayoutPopUpMenu->setSpacing(0);
        gridLayoutPopUpMenu->setObjectName(QString::fromUtf8("gridLayoutPopUpMenu"));
        framePresetsList = new QFrame(FrameUiComponetns);
        framePresetsList->setObjectName(QString::fromUtf8("framePresetsList"));
        sizePolicy.setHeightForWidth(framePresetsList->sizePolicy().hasHeightForWidth());
        framePresetsList->setSizePolicy(sizePolicy);
        framePresetsList->setMaximumSize(QSize(220, 170));
        framePresetsList->setFrameShape(QFrame::StyledPanel);
        framePresetsList->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(framePresetsList);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButtonPreset7 = new QPushButton(framePresetsList);
        pushButtonPreset7->setObjectName(QString::fromUtf8("pushButtonPreset7"));
        sizePolicy.setHeightForWidth(pushButtonPreset7->sizePolicy().hasHeightForWidth());
        pushButtonPreset7->setSizePolicy(sizePolicy);
        pushButtonPreset7->setMinimumSize(QSize(100, 35));
        pushButtonPreset7->setMaximumSize(QSize(100, 35));
        pushButtonPreset7->setFont(font2);
        pushButtonPreset7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: rgb(243, 234, 226);\n"
"background-color: transparent;\n"
"\n"
"border-radius: 5px;\n"
"border: 2px solid;\n"
"border-color: rgb(243, 234, 226);\n"
"}\n"
"QPushButton:enabled:hover {\n"
"background-color: rgb(0, 125, 176);\n"
"}\n"
"QPushButton:enabled:pressed {\n"
"background-color:  rgb(0, 105, 156);\n"
"}\n"
"QPushButton:disabled {\n"
"border-color: rgba(243, 234, 226, 100);\n"
"color:  rgba(243, 234, 226, 100);\n"
"background-color: rgba(255, 255, 255, 20);\n"
"}"));

        gridLayout_2->addWidget(pushButtonPreset7, 5, 0, 1, 1);

        pushButtonPreset6 = new QPushButton(framePresetsList);
        pushButtonPreset6->setObjectName(QString::fromUtf8("pushButtonPreset6"));
        sizePolicy.setHeightForWidth(pushButtonPreset6->sizePolicy().hasHeightForWidth());
        pushButtonPreset6->setSizePolicy(sizePolicy);
        pushButtonPreset6->setMinimumSize(QSize(100, 35));
        pushButtonPreset6->setMaximumSize(QSize(100, 35));
        pushButtonPreset6->setFont(font2);
        pushButtonPreset6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: rgb(243, 234, 226);\n"
"background-color: transparent;\n"
"\n"
"border-radius: 5px;\n"
"border: 2px solid;\n"
"border-color: rgb(243, 234, 226);\n"
"}\n"
"QPushButton:enabled:hover {\n"
"background-color: rgb(0, 125, 176);\n"
"}\n"
"QPushButton:enabled:pressed {\n"
"background-color:  rgb(0, 105, 156);\n"
"}\n"
"QPushButton:disabled {\n"
"border-color: rgba(243, 234, 226, 100);\n"
"color:  rgba(243, 234, 226, 100);\n"
"background-color: rgba(255, 255, 255, 20);\n"
"}"));

        gridLayout_2->addWidget(pushButtonPreset6, 4, 2, 1, 1);

        pushButtonPreset5 = new QPushButton(framePresetsList);
        pushButtonPreset5->setObjectName(QString::fromUtf8("pushButtonPreset5"));
        sizePolicy.setHeightForWidth(pushButtonPreset5->sizePolicy().hasHeightForWidth());
        pushButtonPreset5->setSizePolicy(sizePolicy);
        pushButtonPreset5->setMinimumSize(QSize(100, 35));
        pushButtonPreset5->setMaximumSize(QSize(100, 35));
        pushButtonPreset5->setFont(font2);
        pushButtonPreset5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: rgb(243, 234, 226);\n"
"background-color: transparent;\n"
"\n"
"border-radius: 5px;\n"
"border: 2px solid;\n"
"border-color: rgb(243, 234, 226);\n"
"}\n"
"QPushButton:enabled:hover {\n"
"background-color: rgb(0, 125, 176);\n"
"}\n"
"QPushButton:enabled:pressed {\n"
"background-color:  rgb(0, 105, 156);\n"
"}\n"
"QPushButton:disabled {\n"
"border-color: rgba(243, 234, 226, 100);\n"
"color:  rgba(243, 234, 226, 100);\n"
"background-color: rgba(255, 255, 255, 20);\n"
"}"));

        gridLayout_2->addWidget(pushButtonPreset5, 4, 0, 1, 1);

        pushButtonPreset4 = new QPushButton(framePresetsList);
        pushButtonPreset4->setObjectName(QString::fromUtf8("pushButtonPreset4"));
        sizePolicy.setHeightForWidth(pushButtonPreset4->sizePolicy().hasHeightForWidth());
        pushButtonPreset4->setSizePolicy(sizePolicy);
        pushButtonPreset4->setMinimumSize(QSize(100, 35));
        pushButtonPreset4->setMaximumSize(QSize(100, 35));
        pushButtonPreset4->setFont(font2);
        pushButtonPreset4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: rgb(243, 234, 226);\n"
"background-color: transparent;\n"
"\n"
"border-radius: 5px;\n"
"border: 2px solid;\n"
"border-color: rgb(243, 234, 226);\n"
"}\n"
"QPushButton:enabled:hover {\n"
"background-color: rgb(0, 125, 176);\n"
"}\n"
"QPushButton:enabled:pressed {\n"
"background-color:  rgb(0, 105, 156);\n"
"}\n"
"QPushButton:disabled {\n"
"border-color: rgba(243, 234, 226, 100);\n"
"color:  rgba(243, 234, 226, 100);\n"
"background-color: rgba(255, 255, 255, 20);\n"
"}"));

        gridLayout_2->addWidget(pushButtonPreset4, 3, 2, 1, 1);

        pushButtonPreset3 = new QPushButton(framePresetsList);
        pushButtonPreset3->setObjectName(QString::fromUtf8("pushButtonPreset3"));
        sizePolicy.setHeightForWidth(pushButtonPreset3->sizePolicy().hasHeightForWidth());
        pushButtonPreset3->setSizePolicy(sizePolicy);
        pushButtonPreset3->setMinimumSize(QSize(100, 35));
        pushButtonPreset3->setMaximumSize(QSize(100, 35));
        pushButtonPreset3->setFont(font2);
        pushButtonPreset3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: rgb(243, 234, 226);\n"
"background-color: transparent;\n"
"\n"
"border-radius: 5px;\n"
"border: 2px solid;\n"
"border-color: rgb(243, 234, 226);\n"
"}\n"
"QPushButton:enabled:hover {\n"
"background-color: rgb(0, 125, 176);\n"
"}\n"
"QPushButton:enabled:pressed {\n"
"background-color:  rgb(0, 105, 156);\n"
"}\n"
"QPushButton:disabled {\n"
"border-color: rgba(243, 234, 226, 100);\n"
"color:  rgba(243, 234, 226, 100);\n"
"background-color: rgba(255, 255, 255, 20);\n"
"}"));

        gridLayout_2->addWidget(pushButtonPreset3, 3, 0, 1, 1);

        pushButtonPreset2 = new QPushButton(framePresetsList);
        pushButtonPreset2->setObjectName(QString::fromUtf8("pushButtonPreset2"));
        sizePolicy.setHeightForWidth(pushButtonPreset2->sizePolicy().hasHeightForWidth());
        pushButtonPreset2->setSizePolicy(sizePolicy);
        pushButtonPreset2->setMinimumSize(QSize(100, 35));
        pushButtonPreset2->setMaximumSize(QSize(100, 35));
        pushButtonPreset2->setFont(font2);
        pushButtonPreset2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: rgb(243, 234, 226);\n"
"background-color: transparent;\n"
"\n"
"border-radius: 5px;\n"
"border: 2px solid;\n"
"border-color: rgb(243, 234, 226);\n"
"}\n"
"QPushButton:enabled:hover {\n"
"background-color: rgb(0, 125, 176);\n"
"}\n"
"QPushButton:enabled:pressed {\n"
"background-color:  rgb(0, 105, 156);\n"
"}\n"
"QPushButton:disabled {\n"
"border-color: rgba(243, 234, 226, 100);\n"
"color:  rgba(243, 234, 226, 100);\n"
"background-color: rgba(255, 255, 255, 20);\n"
"}"));

        gridLayout_2->addWidget(pushButtonPreset2, 2, 2, 1, 1);

        pushButtonPreset1 = new QPushButton(framePresetsList);
        pushButtonPreset1->setObjectName(QString::fromUtf8("pushButtonPreset1"));
        sizePolicy.setHeightForWidth(pushButtonPreset1->sizePolicy().hasHeightForWidth());
        pushButtonPreset1->setSizePolicy(sizePolicy);
        pushButtonPreset1->setMinimumSize(QSize(100, 35));
        pushButtonPreset1->setMaximumSize(QSize(100, 35));
        pushButtonPreset1->setFont(font2);
        pushButtonPreset1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: rgb(243, 234, 226);\n"
"background-color: transparent;\n"
"\n"
"border-radius: 5px;\n"
"border: 2px solid;\n"
"border-color: rgb(243, 234, 226);\n"
"}\n"
"QPushButton:enabled:hover {\n"
"background-color: rgb(0, 125, 176);\n"
"}\n"
"QPushButton:enabled:pressed {\n"
"background-color:  rgb(0, 105, 156);\n"
"}\n"
"QPushButton:disabled {\n"
"border-color: rgba(243, 234, 226, 100);\n"
"color:  rgba(243, 234, 226, 100);\n"
"background-color: rgba(255, 255, 255, 20);\n"
"}"));

        gridLayout_2->addWidget(pushButtonPreset1, 2, 0, 1, 1);


        gridLayoutPopUpMenu->addWidget(framePresetsList, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayoutPopUpMenu->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayoutPopUpMenu->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(120, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayoutPopUpMenu->addItem(horizontalSpacer_3, 1, 0, 1, 1);


        gridLayoutTopPart->addLayout(gridLayoutPopUpMenu, 3, 0, 1, 1);

        gridLayoutPopUpDialog = new QGridLayout();
        gridLayoutPopUpDialog->setObjectName(QString::fromUtf8("gridLayoutPopUpDialog"));
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayoutPopUpDialog->addItem(verticalSpacer_4, 2, 1, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayoutPopUpDialog->addItem(verticalSpacer_5, 0, 1, 1, 1);

        framePopUpDialog = new QFrame(FrameUiComponetns);
        framePopUpDialog->setObjectName(QString::fromUtf8("framePopUpDialog"));
        framePopUpDialog->setMinimumSize(QSize(300, 0));
        framePopUpDialog->setMaximumSize(QSize(300, 200));
        framePopUpDialog->setStyleSheet(QString::fromUtf8("border: 0;"));
        framePopUpDialog->setFrameShape(QFrame::StyledPanel);
        framePopUpDialog->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(framePopUpDialog);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalSpacer_7 = new QSpacerItem(20, 74, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_7);

        frame_1234 = new QFrame(framePopUpDialog);
        frame_1234->setObjectName(QString::fromUtf8("frame_1234"));
        sizePolicy.setHeightForWidth(frame_1234->sizePolicy().hasHeightForWidth());
        frame_1234->setSizePolicy(sizePolicy);
        frame_1234->setFrameShape(QFrame::StyledPanel);
        frame_1234->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame_1234);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        spinBoxAddValue = new QSpinBox(frame_1234);
        spinBoxAddValue->setObjectName(QString::fromUtf8("spinBoxAddValue"));
        spinBoxAddValue->setMinimumSize(QSize(0, 50));
        QFont font3;
        font3.setPointSize(14);
        spinBoxAddValue->setFont(font3);
        spinBoxAddValue->setStyleSheet(QString::fromUtf8("border-radius: 4px;\n"
"background-color: white;\n"
"border: 0;"));
        spinBoxAddValue->setMinimum(-100);
        spinBoxAddValue->setMaximum(100);
        spinBoxAddValue->setValue(1);

        gridLayout_3->addWidget(spinBoxAddValue, 1, 0, 1, 1);

        pushButtonAdd = new QPushButton(frame_1234);
        pushButtonAdd->setObjectName(QString::fromUtf8("pushButtonAdd"));
        sizePolicy.setHeightForWidth(pushButtonAdd->sizePolicy().hasHeightForWidth());
        pushButtonAdd->setSizePolicy(sizePolicy);
        pushButtonAdd->setMinimumSize(QSize(100, 50));
        pushButtonAdd->setMaximumSize(QSize(100, 16777215));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Microsoft YaHei Light"));
        font4.setPointSize(14);
        font4.setBold(true);
        font4.setWeight(75);
        pushButtonAdd->setFont(font4);
        pushButtonAdd->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: rgb(243, 234, 226);\n"
"background-color: rgb(0, 125, 176);\n"
"border-radius: 5px;\n"
"}\n"
"QPushButton:hover {\n"
"border: 2px solid;\n"
"border-color: rgb(243, 234, 226);\n"
"}\n"
"QPushButton:pressed {\n"
"background-color:  rgb(0, 105, 156);\n"
"}"));

        gridLayout_3->addWidget(pushButtonAdd, 1, 1, 1, 1);

        label_3 = new QLabel(frame_1234);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font3);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(243, 234, 226);"));

        gridLayout_3->addWidget(label_3, 0, 0, 1, 2);


        verticalLayout_3->addWidget(frame_1234);

        verticalSpacer_6 = new QSpacerItem(20, 74, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_6);


        gridLayoutPopUpDialog->addWidget(framePopUpDialog, 1, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayoutPopUpDialog->addItem(horizontalSpacer_6, 1, 0, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayoutPopUpDialog->addItem(horizontalSpacer_7, 1, 2, 1, 1);


        gridLayoutTopPart->addLayout(gridLayoutPopUpDialog, 2, 0, 1, 1);


        verticalLayout->addLayout(gridLayoutTopPart);

        frame = new QFrame(FrameUiComponetns);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(0, 70));
        frame->setMaximumSize(QSize(16777215, 70));
        frame->setSizeIncrement(QSize(0, 0));
        frame->setStyleSheet(QString::fromUtf8("background-color:  rgba(243, 234, 226, 0);\n"
"border: 0;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setSpacing(12);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonReset = new QPushButton(frame);
        pushButtonReset->setObjectName(QString::fromUtf8("pushButtonReset"));
        sizePolicy.setHeightForWidth(pushButtonReset->sizePolicy().hasHeightForWidth());
        pushButtonReset->setSizePolicy(sizePolicy);
        pushButtonReset->setMinimumSize(QSize(100, 0));
        pushButtonReset->setMaximumSize(QSize(100, 16777215));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Microsoft YaHei Light"));
        font5.setPointSize(14);
        pushButtonReset->setFont(font5);
        pushButtonReset->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: rgb(243, 234, 226);\n"
"background-color: rgb(182, 47, 68);\n"
"border-radius: 5px;\n"
"}\n"
"QPushButton:hover {\n"
"border: 2px solid;\n"
"border-color: rgb(243, 234, 226);\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: rgb(152, 27, 48);\n"
"}"));

        horizontalLayout->addWidget(pushButtonReset);

        line = new QFrame(frame);
        line->setObjectName(QString::fromUtf8("line"));
        line->setMaximumSize(QSize(1, 16777215));
        line->setStyleSheet(QString::fromUtf8("border: 0;\n"
"background-color: rgb(243, 234, 226);"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        pushButtonOpenPresets = new QPushButton(frame);
        pushButtonOpenPresets->setObjectName(QString::fromUtf8("pushButtonOpenPresets"));
        sizePolicy.setHeightForWidth(pushButtonOpenPresets->sizePolicy().hasHeightForWidth());
        pushButtonOpenPresets->setSizePolicy(sizePolicy);
        pushButtonOpenPresets->setMinimumSize(QSize(150, 0));
        pushButtonOpenPresets->setMaximumSize(QSize(150, 16777215));
        pushButtonOpenPresets->setFont(font5);
        pushButtonOpenPresets->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: rgb(243, 234, 226);\n"
"background-color: rgb(0, 125, 176);\n"
"border-radius: 5px;\n"
"}\n"
"QPushButton:hover {\n"
"border: 2px solid;\n"
"border-color: rgb(243, 234, 226);\n"
"}\n"
"QPushButton:pressed {\n"
"background-color:  rgb(0, 105, 156);\n"
"}"));

        horizontalLayout->addWidget(pushButtonOpenPresets);

        pushButtonShowDelta = new QPushButton(frame);
        pushButtonShowDelta->setObjectName(QString::fromUtf8("pushButtonShowDelta"));
        sizePolicy.setHeightForWidth(pushButtonShowDelta->sizePolicy().hasHeightForWidth());
        pushButtonShowDelta->setSizePolicy(sizePolicy);
        pushButtonShowDelta->setMinimumSize(QSize(150, 0));
        pushButtonShowDelta->setMaximumSize(QSize(150, 16777215));
        pushButtonShowDelta->setFont(font5);
        pushButtonShowDelta->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: rgb(243, 234, 226);\n"
"background-color: rgb(0, 125, 176);\n"
"border-radius: 5px;\n"
"border: 2px solid;\n"
"border-color: rgb(243, 234, 226);\n"
"}\n"
"QPushButton:hover {\n"
"background-color: rgba(0, 125, 176, 220);\n"
"}"));

        horizontalLayout->addWidget(pushButtonShowDelta);

        pushButtonSwitchTree = new QPushButton(frame);
        pushButtonSwitchTree->setObjectName(QString::fromUtf8("pushButtonSwitchTree"));
        sizePolicy.setHeightForWidth(pushButtonSwitchTree->sizePolicy().hasHeightForWidth());
        pushButtonSwitchTree->setSizePolicy(sizePolicy);
        pushButtonSwitchTree->setMinimumSize(QSize(170, 0));
        pushButtonSwitchTree->setMaximumSize(QSize(170, 16777215));
        pushButtonSwitchTree->setFont(font5);
        pushButtonSwitchTree->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: rgb(243, 234, 226);\n"
"background-color: transparent;\n"
"\n"
"border-radius: 5px;\n"
"border: 2px solid;\n"
"border-color: rgb(243, 234, 226);\n"
"}\n"
"QPushButton:enabled:hover {\n"
"background-color: rgb(0, 125, 176);\n"
"}\n"
"QPushButton:enabled:pressed {\n"
"background-color:  rgb(0, 105, 156);\n"
"}"));

        horizontalLayout->addWidget(pushButtonSwitchTree);

        frameOperationsButtons = new QFrame(frame);
        frameOperationsButtons->setObjectName(QString::fromUtf8("frameOperationsButtons"));
        frameOperationsButtons->setFrameShape(QFrame::StyledPanel);
        frameOperationsButtons->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frameOperationsButtons);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonFindLCA = new QPushButton(frameOperationsButtons);
        pushButtonFindLCA->setObjectName(QString::fromUtf8("pushButtonFindLCA"));
        sizePolicy.setHeightForWidth(pushButtonFindLCA->sizePolicy().hasHeightForWidth());
        pushButtonFindLCA->setSizePolicy(sizePolicy);
        pushButtonFindLCA->setMinimumSize(QSize(100, 0));
        pushButtonFindLCA->setMaximumSize(QSize(100, 16777215));
        pushButtonFindLCA->setFont(font5);
        pushButtonFindLCA->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: rgb(243, 234, 226);\n"
"background-color: transparent;\n"
"\n"
"border-radius: 5px;\n"
"border: 2px solid;\n"
"border-color: rgb(243, 234, 226);\n"
"}\n"
"QPushButton:enabled:hover {\n"
"background-color: rgb(0, 125, 176);\n"
"}\n"
"QPushButton:enabled:pressed {\n"
"background-color:  rgb(0, 105, 156);\n"
"}\n"
"QPushButton:disabled {\n"
"border-color: rgba(243, 234, 226, 100);\n"
"color:  rgba(243, 234, 226, 100);\n"
"background-color: rgba(255, 255, 255, 20);\n"
"}"));

        gridLayout->addWidget(pushButtonFindLCA, 0, 1, 1, 1);

        pushButtonLink = new QPushButton(frameOperationsButtons);
        pushButtonLink->setObjectName(QString::fromUtf8("pushButtonLink"));
        sizePolicy.setHeightForWidth(pushButtonLink->sizePolicy().hasHeightForWidth());
        pushButtonLink->setSizePolicy(sizePolicy);
        pushButtonLink->setMinimumSize(QSize(100, 0));
        pushButtonLink->setMaximumSize(QSize(100, 16777215));
        pushButtonLink->setFont(font5);
        pushButtonLink->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: rgb(243, 234, 226);\n"
"background-color: transparent;\n"
"\n"
"border-radius: 5px;\n"
"border: 2px solid;\n"
"border-color: rgb(243, 234, 226);\n"
"}\n"
"QPushButton:enabled:hover {\n"
"background-color: rgb(0, 125, 176);\n"
"}\n"
"QPushButton:enabled:pressed {\n"
"background-color:  rgb(0, 105, 156);\n"
"}\n"
"QPushButton:disabled {\n"
"border-color: rgba(243, 234, 226, 100);\n"
"color:  rgba(243, 234, 226, 100);\n"
"background-color: rgba(255, 255, 255, 20);\n"
"}"));

        gridLayout->addWidget(pushButtonLink, 0, 3, 1, 1);

        pushButtonOpenAddDialog = new QPushButton(frameOperationsButtons);
        pushButtonOpenAddDialog->setObjectName(QString::fromUtf8("pushButtonOpenAddDialog"));
        sizePolicy.setHeightForWidth(pushButtonOpenAddDialog->sizePolicy().hasHeightForWidth());
        pushButtonOpenAddDialog->setSizePolicy(sizePolicy);
        pushButtonOpenAddDialog->setMinimumSize(QSize(100, 0));
        pushButtonOpenAddDialog->setMaximumSize(QSize(100, 16777215));
        pushButtonOpenAddDialog->setFont(font5);
        pushButtonOpenAddDialog->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: rgb(243, 234, 226);\n"
"background-color: transparent;\n"
"\n"
"border-radius: 5px;\n"
"border: 2px solid;\n"
"border-color: rgb(243, 234, 226);\n"
"}\n"
"QPushButton:enabled:hover {\n"
"background-color: rgb(0, 125, 176);\n"
"}\n"
"QPushButton:enabled:pressed {\n"
"background-color:  rgb(0, 105, 156);\n"
"}\n"
"QPushButton:disabled {\n"
"border-color: rgba(243, 234, 226, 100);\n"
"color:  rgba(243, 234, 226, 100);\n"
"background-color: rgba(255, 255, 255, 20);\n"
"}"));

        gridLayout->addWidget(pushButtonOpenAddDialog, 1, 1, 1, 1);

        pushButtonCut = new QPushButton(frameOperationsButtons);
        pushButtonCut->setObjectName(QString::fromUtf8("pushButtonCut"));
        sizePolicy.setHeightForWidth(pushButtonCut->sizePolicy().hasHeightForWidth());
        pushButtonCut->setSizePolicy(sizePolicy);
        pushButtonCut->setMinimumSize(QSize(100, 0));
        pushButtonCut->setMaximumSize(QSize(100, 16777215));
        pushButtonCut->setFont(font5);
        pushButtonCut->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: rgb(243, 234, 226);\n"
"background-color: transparent;\n"
"\n"
"border-radius: 5px;\n"
"border: 2px solid;\n"
"border-color: rgb(243, 234, 226);\n"
"}\n"
"QPushButton:enabled:hover {\n"
"background-color: rgb(0, 125, 176);\n"
"}\n"
"QPushButton:enabled:pressed {\n"
"background-color:  rgb(0, 105, 156);\n"
"}\n"
"QPushButton:disabled {\n"
"border-color: rgba(243, 234, 226, 100);\n"
"color:  rgba(243, 234, 226, 100);\n"
"background-color: rgba(255, 255, 255, 20);\n"
"}"));

        gridLayout->addWidget(pushButtonCut, 1, 3, 1, 1);

        pushButtonExpose = new QPushButton(frameOperationsButtons);
        pushButtonExpose->setObjectName(QString::fromUtf8("pushButtonExpose"));
        sizePolicy.setHeightForWidth(pushButtonExpose->sizePolicy().hasHeightForWidth());
        pushButtonExpose->setSizePolicy(sizePolicy);
        pushButtonExpose->setMinimumSize(QSize(100, 0));
        pushButtonExpose->setMaximumSize(QSize(100, 16777215));
        pushButtonExpose->setFont(font5);
        pushButtonExpose->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: rgb(243, 234, 226);\n"
"background-color: transparent;\n"
"\n"
"border-radius: 5px;\n"
"border: 2px solid;\n"
"border-color: rgb(243, 234, 226);\n"
"}\n"
"QPushButton:enabled:hover {\n"
"background-color: rgb(0, 125, 176);\n"
"}\n"
"QPushButton:enabled:pressed {\n"
"background-color:  rgb(0, 105, 156);\n"
"}\n"
"QPushButton:disabled {\n"
"border-color: rgba(243, 234, 226, 100);\n"
"color:  rgba(243, 234, 226, 100);\n"
"background-color: rgba(255, 255, 255, 20);\n"
"}"));

        gridLayout->addWidget(pushButtonExpose, 0, 2, 2, 1);

        horizontalSpacer = new QSpacerItem(482, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);


        horizontalLayout->addWidget(frameOperationsButtons);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font6;
        font6.setFamily(QString::fromUtf8("Microsoft YaHei Light"));
        font6.setPointSize(10);
        label->setFont(font6);
        label->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: rgb(243, 234, 226);"));

        verticalLayout_2->addWidget(label);

        horizontalSliderAnimationSpeed = new QSlider(frame);
        horizontalSliderAnimationSpeed->setObjectName(QString::fromUtf8("horizontalSliderAnimationSpeed"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(horizontalSliderAnimationSpeed->sizePolicy().hasHeightForWidth());
        horizontalSliderAnimationSpeed->setSizePolicy(sizePolicy2);
        horizontalSliderAnimationSpeed->setMinimumSize(QSize(200, 30));
        horizontalSliderAnimationSpeed->setMaximumSize(QSize(200, 16777215));
        horizontalSliderAnimationSpeed->setStyleSheet(QString::fromUtf8("QSlider {\n"
"background-color: transparent;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"background-color: rgb(0, 125, 176);\n"
"width: 20px;\n"
"border-radius: 3px;\n"
"margin: -15px 0;\n"
"}\n"
"QSlider::handle:horizontal:hover {\n"
"background-color: rgb(20, 145, 186);\n"
"}\n"
"\n"
"QSlider::groove:horizontal {\n"
"background-color: rgb(243, 234, 226);\n"
"height: 5px;\n"
"border-radius: 2px;\n"
"}"));
        horizontalSliderAnimationSpeed->setMinimum(1);
        horizontalSliderAnimationSpeed->setMaximum(100);
        horizontalSliderAnimationSpeed->setValue(50);
        horizontalSliderAnimationSpeed->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(horizontalSliderAnimationSpeed);


        horizontalLayout->addLayout(verticalLayout_2);

        pushButtonEndOperation = new QPushButton(frame);
        pushButtonEndOperation->setObjectName(QString::fromUtf8("pushButtonEndOperation"));
        sizePolicy.setHeightForWidth(pushButtonEndOperation->sizePolicy().hasHeightForWidth());
        pushButtonEndOperation->setSizePolicy(sizePolicy);
        pushButtonEndOperation->setMinimumSize(QSize(100, 0));
        pushButtonEndOperation->setMaximumSize(QSize(100, 16777215));
        pushButtonEndOperation->setFont(font5);
        pushButtonEndOperation->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: rgb(243, 234, 226);\n"
"background-color: rgb(0, 125, 176);\n"
"border-radius: 5px;\n"
"}\n"
"QPushButton:hover {\n"
"border: 2px solid;\n"
"border-color: rgb(243, 234, 226);\n"
"}\n"
"QPushButton:pressed {\n"
"background-color:  rgb(0, 105, 156);\n"
"}"));

        horizontalLayout->addWidget(pushButtonEndOperation);

        pushButtonMakeStep = new QPushButton(frame);
        pushButtonMakeStep->setObjectName(QString::fromUtf8("pushButtonMakeStep"));
        sizePolicy.setHeightForWidth(pushButtonMakeStep->sizePolicy().hasHeightForWidth());
        pushButtonMakeStep->setSizePolicy(sizePolicy);
        pushButtonMakeStep->setMinimumSize(QSize(100, 0));
        pushButtonMakeStep->setMaximumSize(QSize(100, 16777215));
        pushButtonMakeStep->setFont(font5);
        pushButtonMakeStep->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: rgb(243, 234, 226);\n"
"background-color: rgb(0, 125, 176);\n"
"border-radius: 5px;\n"
"}\n"
"QPushButton:hover {\n"
"border: 2px solid;\n"
"border-color: rgb(243, 234, 226);\n"
"}\n"
"QPushButton:pressed {\n"
"background-color:  rgb(0, 105, 156);\n"
"}"));

        horizontalLayout->addWidget(pushButtonMakeStep);


        verticalLayout->addWidget(frame);


        retranslateUi(FrameUiComponetns);

        QMetaObject::connectSlotsByName(FrameUiComponetns);
    } // setupUi

    void retranslateUi(QFrame *FrameUiComponetns)
    {
        FrameUiComponetns->setWindowTitle(QCoreApplication::translate("FrameUiComponetns", "Frame", nullptr));
        label_2->setText(QCoreApplication::translate("FrameUiComponetns", "Log", nullptr));
        labelSequence->setText(QString());
        pushButtonHideLog->setText(QCoreApplication::translate("FrameUiComponetns", "Hide Log", nullptr));
        pushButtonClearLog->setText(QCoreApplication::translate("FrameUiComponetns", "Clear", nullptr));
        pushButtonPreset7->setText(QCoreApplication::translate("FrameUiComponetns", "7", nullptr));
        pushButtonPreset6->setText(QCoreApplication::translate("FrameUiComponetns", "6", nullptr));
        pushButtonPreset5->setText(QCoreApplication::translate("FrameUiComponetns", "5", nullptr));
        pushButtonPreset4->setText(QCoreApplication::translate("FrameUiComponetns", "4", nullptr));
        pushButtonPreset3->setText(QCoreApplication::translate("FrameUiComponetns", "3", nullptr));
        pushButtonPreset2->setText(QCoreApplication::translate("FrameUiComponetns", "2 - fork", nullptr));
        pushButtonPreset1->setText(QCoreApplication::translate("FrameUiComponetns", "1 - stairway", nullptr));
        pushButtonAdd->setText(QCoreApplication::translate("FrameUiComponetns", "Add", nullptr));
        label_3->setText(QCoreApplication::translate("FrameUiComponetns", "Add constant to path", nullptr));
        pushButtonReset->setText(QCoreApplication::translate("FrameUiComponetns", "Reset", nullptr));
        pushButtonOpenPresets->setText(QCoreApplication::translate("FrameUiComponetns", "Presets", nullptr));
        pushButtonShowDelta->setText(QCoreApplication::translate("FrameUiComponetns", "Show delta", nullptr));
        pushButtonSwitchTree->setText(QCoreApplication::translate("FrameUiComponetns", "Concrete tree", nullptr));
        pushButtonFindLCA->setText(QCoreApplication::translate("FrameUiComponetns", "LCA", nullptr));
        pushButtonLink->setText(QCoreApplication::translate("FrameUiComponetns", "Link", nullptr));
        pushButtonOpenAddDialog->setText(QCoreApplication::translate("FrameUiComponetns", "Add 1", nullptr));
        pushButtonCut->setText(QCoreApplication::translate("FrameUiComponetns", "Cut", nullptr));
        pushButtonExpose->setText(QCoreApplication::translate("FrameUiComponetns", "Expose", nullptr));
        label->setText(QCoreApplication::translate("FrameUiComponetns", "animation speed", nullptr));
        pushButtonEndOperation->setText(QCoreApplication::translate("FrameUiComponetns", "End", nullptr));
        pushButtonMakeStep->setText(QCoreApplication::translate("FrameUiComponetns", "Step", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FrameUiComponetns: public Ui_FrameUiComponetns {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRAMEUICOMPONETNS_H
