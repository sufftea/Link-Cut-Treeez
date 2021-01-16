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
    QFrame *framePopUpDialog;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_7;
    QFrame *frame_1234;
    QGridLayout *gridLayout_3;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_7;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonReset;
    QFrame *line;
    QPushButton *pushButtonOpenPresets;
    QPushButton *pushButtonSwitchTree;
    QSpacerItem *horizontalSpacer;
    QFrame *frame_2;
    QGridLayout *gridLayout_4;
    QPushButton *pushButtonPathMin;
    QPushButton *pushButtonPathMax;
    QPushButton *pushButtonPathSum;
    QFrame *frameOperationsButtons;
    QGridLayout *gridLayout;
    QPushButton *pushButtonExpose;
    QPushButton *pushButtonLink;
    QPushButton *pushButtonCut;
    QPushButton *pushButtonLCA;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QSlider *horizontalSliderAnimationSpeed;
    QPushButton *pushButtonAutoStep;
    QPushButton *pushButtonEndOperation;
    QPushButton *pushButtonMakeStep;

    void setupUi(QFrame *FrameUiComponetns)
    {
        if (FrameUiComponetns->objectName().isEmpty())
            FrameUiComponetns->setObjectName(QString::fromUtf8("FrameUiComponetns"));
        FrameUiComponetns->resize(1725, 670);
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
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 450, 203));
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

        verticalLayout_3->addWidget(frame_1234);

        verticalSpacer_6 = new QSpacerItem(20, 74, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_6);


        gridLayoutPopUpDialog->addWidget(framePopUpDialog, 1, 1, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayoutPopUpDialog->addItem(verticalSpacer_5, 0, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayoutPopUpDialog->addItem(horizontalSpacer_6, 1, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayoutPopUpDialog->addItem(verticalSpacer_4, 2, 1, 1, 1);

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
        horizontalLayout->setSpacing(7);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonReset = new QPushButton(frame);
        pushButtonReset->setObjectName(QString::fromUtf8("pushButtonReset"));
        sizePolicy.setHeightForWidth(pushButtonReset->sizePolicy().hasHeightForWidth());
        pushButtonReset->setSizePolicy(sizePolicy);
        pushButtonReset->setMinimumSize(QSize(100, 0));
        pushButtonReset->setMaximumSize(QSize(100, 16777215));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Microsoft YaHei Light"));
        font3.setPointSize(14);
        pushButtonReset->setFont(font3);
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
        pushButtonOpenPresets->setFont(font3);
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

        pushButtonSwitchTree = new QPushButton(frame);
        pushButtonSwitchTree->setObjectName(QString::fromUtf8("pushButtonSwitchTree"));
        sizePolicy.setHeightForWidth(pushButtonSwitchTree->sizePolicy().hasHeightForWidth());
        pushButtonSwitchTree->setSizePolicy(sizePolicy);
        pushButtonSwitchTree->setMinimumSize(QSize(170, 0));
        pushButtonSwitchTree->setMaximumSize(QSize(170, 16777215));
        pushButtonSwitchTree->setFont(font3);
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

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setMaximumSize(QSize(230, 16777215));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(frame_2);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        pushButtonPathMin = new QPushButton(frame_2);
        pushButtonPathMin->setObjectName(QString::fromUtf8("pushButtonPathMin"));
        sizePolicy.setHeightForWidth(pushButtonPathMin->sizePolicy().hasHeightForWidth());
        pushButtonPathMin->setSizePolicy(sizePolicy);
        pushButtonPathMin->setMinimumSize(QSize(110, 0));
        pushButtonPathMin->setMaximumSize(QSize(100, 16777215));
        pushButtonPathMin->setFont(font3);
        pushButtonPathMin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        gridLayout_4->addWidget(pushButtonPathMin, 0, 1, 1, 1);

        pushButtonPathMax = new QPushButton(frame_2);
        pushButtonPathMax->setObjectName(QString::fromUtf8("pushButtonPathMax"));
        sizePolicy.setHeightForWidth(pushButtonPathMax->sizePolicy().hasHeightForWidth());
        pushButtonPathMax->setSizePolicy(sizePolicy);
        pushButtonPathMax->setMinimumSize(QSize(110, 0));
        pushButtonPathMax->setMaximumSize(QSize(100, 16777215));
        pushButtonPathMax->setFont(font3);
        pushButtonPathMax->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        gridLayout_4->addWidget(pushButtonPathMax, 1, 1, 1, 1);

        pushButtonPathSum = new QPushButton(frame_2);
        pushButtonPathSum->setObjectName(QString::fromUtf8("pushButtonPathSum"));
        sizePolicy.setHeightForWidth(pushButtonPathSum->sizePolicy().hasHeightForWidth());
        pushButtonPathSum->setSizePolicy(sizePolicy);
        pushButtonPathSum->setMinimumSize(QSize(110, 0));
        pushButtonPathSum->setMaximumSize(QSize(100, 16777215));
        pushButtonPathSum->setFont(font3);
        pushButtonPathSum->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        gridLayout_4->addWidget(pushButtonPathSum, 0, 0, 2, 1);


        horizontalLayout->addWidget(frame_2);

        frameOperationsButtons = new QFrame(frame);
        frameOperationsButtons->setObjectName(QString::fromUtf8("frameOperationsButtons"));
        frameOperationsButtons->setMaximumSize(QSize(314, 16777215));
        frameOperationsButtons->setFrameShape(QFrame::StyledPanel);
        frameOperationsButtons->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frameOperationsButtons);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonExpose = new QPushButton(frameOperationsButtons);
        pushButtonExpose->setObjectName(QString::fromUtf8("pushButtonExpose"));
        sizePolicy.setHeightForWidth(pushButtonExpose->sizePolicy().hasHeightForWidth());
        pushButtonExpose->setSizePolicy(sizePolicy);
        pushButtonExpose->setMinimumSize(QSize(100, 0));
        pushButtonExpose->setMaximumSize(QSize(100, 16777215));
        pushButtonExpose->setFont(font3);
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

        gridLayout->addWidget(pushButtonExpose, 0, 1, 2, 1);

        pushButtonLink = new QPushButton(frameOperationsButtons);
        pushButtonLink->setObjectName(QString::fromUtf8("pushButtonLink"));
        sizePolicy.setHeightForWidth(pushButtonLink->sizePolicy().hasHeightForWidth());
        pushButtonLink->setSizePolicy(sizePolicy);
        pushButtonLink->setMinimumSize(QSize(100, 0));
        pushButtonLink->setMaximumSize(QSize(100, 16777215));
        pushButtonLink->setFont(font3);
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

        gridLayout->addWidget(pushButtonLink, 0, 2, 1, 1);

        pushButtonCut = new QPushButton(frameOperationsButtons);
        pushButtonCut->setObjectName(QString::fromUtf8("pushButtonCut"));
        sizePolicy.setHeightForWidth(pushButtonCut->sizePolicy().hasHeightForWidth());
        pushButtonCut->setSizePolicy(sizePolicy);
        pushButtonCut->setMinimumSize(QSize(100, 0));
        pushButtonCut->setMaximumSize(QSize(100, 16777215));
        pushButtonCut->setFont(font3);
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

        gridLayout->addWidget(pushButtonCut, 1, 2, 1, 1);

        pushButtonLCA = new QPushButton(frameOperationsButtons);
        pushButtonLCA->setObjectName(QString::fromUtf8("pushButtonLCA"));
        sizePolicy.setHeightForWidth(pushButtonLCA->sizePolicy().hasHeightForWidth());
        pushButtonLCA->setSizePolicy(sizePolicy);
        pushButtonLCA->setMinimumSize(QSize(100, 0));
        pushButtonLCA->setMaximumSize(QSize(100, 16777215));
        pushButtonLCA->setFont(font3);
        pushButtonLCA->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        gridLayout->addWidget(pushButtonLCA, 0, 0, 2, 1);


        horizontalLayout->addWidget(frameOperationsButtons);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Microsoft YaHei Light"));
        font4.setPointSize(10);
        label->setFont(font4);
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

        pushButtonAutoStep = new QPushButton(frame);
        pushButtonAutoStep->setObjectName(QString::fromUtf8("pushButtonAutoStep"));
        sizePolicy.setHeightForWidth(pushButtonAutoStep->sizePolicy().hasHeightForWidth());
        pushButtonAutoStep->setSizePolicy(sizePolicy);
        pushButtonAutoStep->setMinimumSize(QSize(100, 0));
        pushButtonAutoStep->setMaximumSize(QSize(100, 16777215));
        pushButtonAutoStep->setFont(font3);
        pushButtonAutoStep->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        horizontalLayout->addWidget(pushButtonAutoStep);

        pushButtonEndOperation = new QPushButton(frame);
        pushButtonEndOperation->setObjectName(QString::fromUtf8("pushButtonEndOperation"));
        sizePolicy.setHeightForWidth(pushButtonEndOperation->sizePolicy().hasHeightForWidth());
        pushButtonEndOperation->setSizePolicy(sizePolicy);
        pushButtonEndOperation->setMinimumSize(QSize(100, 0));
        pushButtonEndOperation->setMaximumSize(QSize(100, 16777215));
        pushButtonEndOperation->setFont(font3);
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
        pushButtonMakeStep->setFont(font3);
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
        pushButtonPreset6->setText(QCoreApplication::translate("FrameUiComponetns", "6 - HUGE", nullptr));
        pushButtonPreset5->setText(QCoreApplication::translate("FrameUiComponetns", "5 - expose", nullptr));
        pushButtonPreset4->setText(QCoreApplication::translate("FrameUiComponetns", "4 - simple", nullptr));
        pushButtonPreset3->setText(QCoreApplication::translate("FrameUiComponetns", "3 - octopus", nullptr));
        pushButtonPreset2->setText(QCoreApplication::translate("FrameUiComponetns", "2 - fork", nullptr));
        pushButtonPreset1->setText(QCoreApplication::translate("FrameUiComponetns", "1 - stairway", nullptr));
        pushButtonReset->setText(QCoreApplication::translate("FrameUiComponetns", "Reset", nullptr));
        pushButtonOpenPresets->setText(QCoreApplication::translate("FrameUiComponetns", "Presets", nullptr));
        pushButtonSwitchTree->setText(QCoreApplication::translate("FrameUiComponetns", "Concrete tree", nullptr));
        pushButtonPathMin->setText(QCoreApplication::translate("FrameUiComponetns", "Min", nullptr));
        pushButtonPathMax->setText(QCoreApplication::translate("FrameUiComponetns", "Max", nullptr));
        pushButtonPathSum->setText(QCoreApplication::translate("FrameUiComponetns", "Sum", nullptr));
        pushButtonExpose->setText(QCoreApplication::translate("FrameUiComponetns", "Expose", nullptr));
        pushButtonLink->setText(QCoreApplication::translate("FrameUiComponetns", "Link", nullptr));
        pushButtonCut->setText(QCoreApplication::translate("FrameUiComponetns", "Cut", nullptr));
        pushButtonLCA->setText(QCoreApplication::translate("FrameUiComponetns", "LCA", nullptr));
        label->setText(QCoreApplication::translate("FrameUiComponetns", "animation speed", nullptr));
        pushButtonAutoStep->setText(QCoreApplication::translate("FrameUiComponetns", "Auto", nullptr));
        pushButtonEndOperation->setText(QCoreApplication::translate("FrameUiComponetns", "End", nullptr));
        pushButtonMakeStep->setText(QCoreApplication::translate("FrameUiComponetns", "Step", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FrameUiComponetns: public Ui_FrameUiComponetns {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRAMEUICOMPONETNS_H
