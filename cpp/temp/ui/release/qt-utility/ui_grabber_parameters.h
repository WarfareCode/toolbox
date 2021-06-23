/********************************************************************************
** Form generated from reading UI file 'grabber_parameters.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRABBER_PARAMETERS_H
#define UI_GRABBER_PARAMETERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GrabberParametersUI
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *twParameters;
    QWidget *tConnection;
    QVBoxLayout *verticalLayout_6;
    QFrame *gbConnection;
    QGridLayout *gridLayout_4;
    QFrame *frame_3;
    QGridLayout *gridLayout_13;
    QFrame *line_10;
    QFrame *frame_16;
    QHBoxLayout *horizontalLayout_6;
    QLabel *laPort;
    QLabel *laR;
    QSpinBox *sbReadingPort;
    QLabel *laW;
    QSpinBox *sbWritingPort;
    QSpacerItem *horizontalSpacer_6;
    QFrame *fStateR;
    QHBoxLayout *horizontalLayout_10;
    QLabel *laR_2;
    QPushButton *pbConnect;
    QFrame *frame_17;
    QHBoxLayout *horizontalLayout_7;
    QLabel *laIp;
    QLineEdit *leWAddress;
    QLabel *laInterface;
    QSpinBox *sbInterface;
    QSpacerItem *horizontalSpacer_19;
    QFrame *fStateW;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_63;
    QPushButton *pbDisconnect;
    QFrame *fPacketsAndTime;
    QGridLayout *gridLayout_5;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_23;
    QFrame *line_12;
    QLabel *laPR;
    QFrame *line;
    QLabel *laPTot;
    QLabel *label_32;
    QFrame *line_6;
    QFrame *line_2;
    QFrame *line_8;
    QFrame *line_9;
    QLabel *label_21;
    QLabel *label_35;
    QLabel *laPL;
    QLabel *label_61;
    QLabel *laTTotal;
    QFrame *line_11;
    QLabel *laFR;
    QLabel *laFL;
    QLabel *laFT;
    QLabel *label_29;
    QFrame *frame_10;
    QVBoxLayout *verticalLayout_7;
    QFrame *fNetworkInfo;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_51;
    QTextEdit *teNetworkInfo;
    QSpacerItem *verticalSpacer_6;
    QWidget *tCamera;
    QGridLayout *gridLayout_11;
    QFrame *frame_15;
    QHBoxLayout *horizontalLayout_8;
    QRadioButton *rbDoNothing;
    QRadioButton *rbGetData;
    QSpacerItem *horizontalSpacer_14;
    QFrame *frame_14;
    QGridLayout *gridLayout_15;
    QLabel *label_2;
    QSpinBox *sbFPS;
    QCheckBox *cbDisplayData;
    QLabel *label_41;
    QSpacerItem *horizontalSpacer_13;
    QFrame *fStateCam;
    QComboBox *cbDataType;
    QSpacerItem *verticalSpacer_4;
    QFrame *frame_13;
    QGridLayout *gridLayout_14;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pbOpen;
    QSpacerItem *horizontalSpacer_12;
    QPushButton *pbClose;
    QWidget *tModel;
    QVBoxLayout *verticalLayout_5;
    QFrame *gbCloudSettings;
    QVBoxLayout *verticalLayout_4;
    QFrame *frame_7;
    QGridLayout *gridLayout_8;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_47;
    QLabel *label_49;
    QLabel *label_48;
    QDoubleSpinBox *dsbT00;
    QDoubleSpinBox *dsbT10;
    QDoubleSpinBox *dsbT01;
    QDoubleSpinBox *dsbT02;
    QDoubleSpinBox *dsbT20;
    QDoubleSpinBox *dsbT12;
    QDoubleSpinBox *dsbT11;
    QDoubleSpinBox *dsbT23;
    QDoubleSpinBox *dsbT13;
    QDoubleSpinBox *dsbT21;
    QDoubleSpinBox *dsbT22;
    QLabel *label_43;
    QLabel *label_46;
    QLabel *label_44;
    QDoubleSpinBox *dsbT03;
    QSpacerItem *horizontalSpacer_11;
    QLabel *label_42;
    QLabel *label_45;
    QFrame *line_4;
    QFrame *frame_5;
    QGridLayout *gridLayout_6;
    QDoubleSpinBox *dsbRx;
    QLabel *label_13;
    QLabel *label_8;
    QDoubleSpinBox *dsbRy;
    QLabel *label_22;
    QDoubleSpinBox *dsbRz;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *horizontalSpacer_8;
    QLabel *label_16;
    QDoubleSpinBox *dsbSx;
    QDoubleSpinBox *dsbSy;
    QDoubleSpinBox *dsbSz;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_57;
    QDoubleSpinBox *dsbTx;
    QDoubleSpinBox *dsbTy;
    QDoubleSpinBox *dsbTz;
    QLabel *label_58;
    QLabel *label_59;
    QLabel *label_60;
    QSpacerItem *verticalSpacer_3;
    QWidget *tFilters;
    QGridLayout *gridLayout_3;
    QLabel *label_5;
    QFrame *line_7;
    QFrame *line_14;
    QFrame *fDepthMinMax;
    QGridLayout *gridLayout;
    QLabel *label_19;
    QLabel *label_4;
    QLabel *label_18;
    QDoubleSpinBox *dsbMaxDepth;
    QDoubleSpinBox *dsbMinDepth;
    QSpacerItem *horizontalSpacer_15;
    QFrame *frame_4;
    QGridLayout *gridLayout_16;
    QLabel *label_17;
    QSpinBox *sbMaxDiffB;
    QSpinBox *sbGFiltered;
    QDoubleSpinBox *dsbUF;
    QLabel *label_40;
    QSpinBox *sbMaxDiffR;
    QLabel *label_39;
    QDoubleSpinBox *dsbYF;
    QSpinBox *sbBFiltered;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_9;
    QCheckBox *cbFilterDepthWithColor;
    QSpinBox *sbMaxDiffG;
    QDoubleSpinBox *dsbVF;
    QSpinBox *sbRFiltered;
    QSpinBox *sbJpegCompressionRate;
    QLabel *label_62;
    QFrame *fInfrared;
    QGridLayout *gridLayout_10;
    QLabel *label_55;
    QLabel *label_20;
    QCheckBox *cbInfraInvert;
    QSpinBox *sbInfraMinRange;
    QSpinBox *sbInfraMaxRange;
    QCheckBox *cbInfraBinary;
    QSpinBox *sbMinInfra;
    QLabel *label_38;
    QSpacerItem *horizontalSpacer_3;
    QSpinBox *sbMaxInfra;
    QLabel *label_36;
    QFrame *line_3;
    QLabel *label_37;
    QFrame *fSize;
    QGridLayout *gridLayout_12;
    QLabel *label_53;
    QSpinBox *sbMaxW;
    QLabel *label_25;
    QLabel *label_52;
    QLabel *label_24;
    QSpinBox *sbMinW;
    QSpinBox *sbMaxH;
    QSpinBox *sbMinH;
    QSpacerItem *horizontalSpacer_16;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QLabel *label_27;
    QLabel *label_7;
    QCheckBox *cbEnableSmoothing;
    QSpinBox *sbSmoothingKernelSize;
    QFrame *frame_11;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_28;
    QSpinBox *sbMinNeighboursNb;
    QLabel *label_54;
    QSpinBox *sbMinNeighboursLoops;
    QSpacerItem *horizontalSpacer_17;
    QCheckBox *cbErosion;
    QSpinBox *sbMinErosionValue;
    QFrame *frame_12;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *cbTemporal;
    QLabel *label_11;
    QDoubleSpinBox *dsbVMax;
    QLabel *label_12;
    QDoubleSpinBox *dsbGMin;
    QSpacerItem *horizontalSpacer_18;
    QComboBox *cbErosionType;
    QSpinBox *sbSizeKernelErode;
    QLabel *label_30;
    QLabel *label_26;
    QLabel *label_31;
    QSpacerItem *horizontalSpacer_4;
    QFrame *frame_2;
    QGridLayout *gridLayout_17;
    QDoubleSpinBox *dsbOffsetAfterMin;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer;
    QLabel *label_10;
    QDoubleSpinBox *dsbVMin;
    QComboBox *cbSmoothingMethod;
    QDoubleSpinBox *dsbLocalDiff;
    QSpacerItem *verticalSpacer_5;
    QWidget *widget_2;
    QWidget *tDisplay;
    QGridLayout *gridLayout_9;
    QFrame *frame_6;
    QGridLayout *gridLayout_7;
    QFrame *line_5;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_33;
    QCheckBox *cbDisplayCloud;
    QLabel *label_56;
    QLabel *laSizeCloud;
    QLabel *label;
    QSpacerItem *verticalSpacer_2;
    QDoubleSpinBox *dsbSizePts;
    QCheckBox *cbForceCloudColor;
    QFrame *frame_8;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_50;
    QSpinBox *sbCloudColorR;
    QSpinBox *sbCloudColorG;
    QSpinBox *sbCloudColorB;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *GrabberParametersUI)
    {
        if (GrabberParametersUI->objectName().isEmpty())
            GrabberParametersUI->setObjectName(QString::fromUtf8("GrabberParametersUI"));
        GrabberParametersUI->resize(489, 757);
        verticalLayout = new QVBoxLayout(GrabberParametersUI);
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        twParameters = new QTabWidget(GrabberParametersUI);
        twParameters->setObjectName(QString::fromUtf8("twParameters"));
        tConnection = new QWidget();
        tConnection->setObjectName(QString::fromUtf8("tConnection"));
        verticalLayout_6 = new QVBoxLayout(tConnection);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        gbConnection = new QFrame(tConnection);
        gbConnection->setObjectName(QString::fromUtf8("gbConnection"));
        gbConnection->setMaximumSize(QSize(16777215, 16777215));
        gbConnection->setFrameShape(QFrame::Box);
        gbConnection->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(gbConnection);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(-1, 5, -1, 4);
        frame_3 = new QFrame(gbConnection);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setMinimumSize(QSize(0, 0));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayout_13 = new QGridLayout(frame_3);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        gridLayout_13->setContentsMargins(0, -1, 0, -1);
        line_10 = new QFrame(frame_3);
        line_10->setObjectName(QString::fromUtf8("line_10"));
        line_10->setFrameShape(QFrame::VLine);
        line_10->setFrameShadow(QFrame::Sunken);

        gridLayout_13->addWidget(line_10, 0, 1, 3, 1);

        frame_16 = new QFrame(frame_3);
        frame_16->setObjectName(QString::fromUtf8("frame_16"));
        frame_16->setFrameShape(QFrame::StyledPanel);
        frame_16->setFrameShadow(QFrame::Raised);
        horizontalLayout_6 = new QHBoxLayout(frame_16);
        horizontalLayout_6->setSpacing(3);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(1, 1, 1, 1);
        laPort = new QLabel(frame_16);
        laPort->setObjectName(QString::fromUtf8("laPort"));

        horizontalLayout_6->addWidget(laPort);

        laR = new QLabel(frame_16);
        laR->setObjectName(QString::fromUtf8("laR"));

        horizontalLayout_6->addWidget(laR);

        sbReadingPort = new QSpinBox(frame_16);
        sbReadingPort->setObjectName(QString::fromUtf8("sbReadingPort"));
        sbReadingPort->setMaximum(10000);
        sbReadingPort->setValue(0);

        horizontalLayout_6->addWidget(sbReadingPort);

        laW = new QLabel(frame_16);
        laW->setObjectName(QString::fromUtf8("laW"));

        horizontalLayout_6->addWidget(laW);

        sbWritingPort = new QSpinBox(frame_16);
        sbWritingPort->setObjectName(QString::fromUtf8("sbWritingPort"));
        sbWritingPort->setMaximum(10000);
        sbWritingPort->setValue(0);

        horizontalLayout_6->addWidget(sbWritingPort);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);

        fStateR = new QFrame(frame_16);
        fStateR->setObjectName(QString::fromUtf8("fStateR"));
        fStateR->setMinimumSize(QSize(25, 25));
        fStateR->setMaximumSize(QSize(16777215, 25));
        fStateR->setFrameShape(QFrame::StyledPanel);
        fStateR->setFrameShadow(QFrame::Raised);
        horizontalLayout_10 = new QHBoxLayout(fStateR);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        laR_2 = new QLabel(fStateR);
        laR_2->setObjectName(QString::fromUtf8("laR_2"));

        horizontalLayout_10->addWidget(laR_2, 0, Qt::AlignHCenter);


        horizontalLayout_6->addWidget(fStateR, 0, Qt::AlignHCenter);


        gridLayout_13->addWidget(frame_16, 1, 3, 1, 1);

        pbConnect = new QPushButton(frame_3);
        pbConnect->setObjectName(QString::fromUtf8("pbConnect"));

        gridLayout_13->addWidget(pbConnect, 1, 0, 1, 1);

        frame_17 = new QFrame(frame_3);
        frame_17->setObjectName(QString::fromUtf8("frame_17"));
        frame_17->setFrameShape(QFrame::StyledPanel);
        frame_17->setFrameShadow(QFrame::Raised);
        horizontalLayout_7 = new QHBoxLayout(frame_17);
        horizontalLayout_7->setSpacing(3);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(1, 1, 1, 1);
        laIp = new QLabel(frame_17);
        laIp->setObjectName(QString::fromUtf8("laIp"));

        horizontalLayout_7->addWidget(laIp);

        leWAddress = new QLineEdit(frame_17);
        leWAddress->setObjectName(QString::fromUtf8("leWAddress"));

        horizontalLayout_7->addWidget(leWAddress);

        laInterface = new QLabel(frame_17);
        laInterface->setObjectName(QString::fromUtf8("laInterface"));

        horizontalLayout_7->addWidget(laInterface);

        sbInterface = new QSpinBox(frame_17);
        sbInterface->setObjectName(QString::fromUtf8("sbInterface"));

        horizontalLayout_7->addWidget(sbInterface);

        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_19);

        fStateW = new QFrame(frame_17);
        fStateW->setObjectName(QString::fromUtf8("fStateW"));
        fStateW->setMinimumSize(QSize(25, 25));
        fStateW->setMaximumSize(QSize(16777215, 25));
        fStateW->setFrameShape(QFrame::StyledPanel);
        fStateW->setFrameShadow(QFrame::Raised);
        horizontalLayout_9 = new QHBoxLayout(fStateW);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_63 = new QLabel(fStateW);
        label_63->setObjectName(QString::fromUtf8("label_63"));

        horizontalLayout_9->addWidget(label_63);


        horizontalLayout_7->addWidget(fStateW, 0, Qt::AlignHCenter);


        gridLayout_13->addWidget(frame_17, 2, 3, 1, 1);

        pbDisconnect = new QPushButton(frame_3);
        pbDisconnect->setObjectName(QString::fromUtf8("pbDisconnect"));

        gridLayout_13->addWidget(pbDisconnect, 2, 0, 1, 1);


        gridLayout_4->addWidget(frame_3, 2, 0, 1, 4);

        fPacketsAndTime = new QFrame(gbConnection);
        fPacketsAndTime->setObjectName(QString::fromUtf8("fPacketsAndTime"));
        fPacketsAndTime->setMinimumSize(QSize(0, 0));
        fPacketsAndTime->setFrameShape(QFrame::StyledPanel);
        fPacketsAndTime->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(fPacketsAndTime);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_5, 0, 10, 1, 1);

        label_23 = new QLabel(fPacketsAndTime);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setMinimumSize(QSize(30, 0));

        gridLayout_5->addWidget(label_23, 0, 2, 1, 1, Qt::AlignHCenter);

        line_12 = new QFrame(fPacketsAndTime);
        line_12->setObjectName(QString::fromUtf8("line_12"));
        line_12->setFrameShape(QFrame::HLine);
        line_12->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_12, 2, 0, 1, 1);

        laPR = new QLabel(fPacketsAndTime);
        laPR->setObjectName(QString::fromUtf8("laPR"));

        gridLayout_5->addWidget(laPR, 1, 2, 1, 1, Qt::AlignHCenter);

        line = new QFrame(fPacketsAndTime);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line, 2, 2, 1, 3);

        laPTot = new QLabel(fPacketsAndTime);
        laPTot->setObjectName(QString::fromUtf8("laPTot"));

        gridLayout_5->addWidget(laPTot, 1, 4, 1, 1, Qt::AlignHCenter);

        label_32 = new QLabel(fPacketsAndTime);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setMinimumSize(QSize(30, 0));

        gridLayout_5->addWidget(label_32, 0, 3, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);

        line_6 = new QFrame(fPacketsAndTime);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShape(QFrame::VLine);
        line_6->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_6, 0, 5, 5, 1);

        line_2 = new QFrame(fPacketsAndTime);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_2, 0, 1, 5, 1);

        line_8 = new QFrame(fPacketsAndTime);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_8, 2, 7, 1, 1);

        line_9 = new QFrame(fPacketsAndTime);
        line_9->setObjectName(QString::fromUtf8("line_9"));
        line_9->setFrameShape(QFrame::VLine);
        line_9->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_9, 0, 8, 5, 1);

        label_21 = new QLabel(fPacketsAndTime);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        gridLayout_5->addWidget(label_21, 0, 0, 2, 1);

        label_35 = new QLabel(fPacketsAndTime);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setMinimumSize(QSize(30, 0));

        gridLayout_5->addWidget(label_35, 0, 4, 1, 1, Qt::AlignHCenter);

        laPL = new QLabel(fPacketsAndTime);
        laPL->setObjectName(QString::fromUtf8("laPL"));

        gridLayout_5->addWidget(laPL, 1, 3, 1, 1, Qt::AlignHCenter);

        label_61 = new QLabel(fPacketsAndTime);
        label_61->setObjectName(QString::fromUtf8("label_61"));

        gridLayout_5->addWidget(label_61, 3, 0, 2, 1);

        laTTotal = new QLabel(fPacketsAndTime);
        laTTotal->setObjectName(QString::fromUtf8("laTTotal"));

        gridLayout_5->addWidget(laTTotal, 4, 6, 1, 1, Qt::AlignHCenter);

        line_11 = new QFrame(fPacketsAndTime);
        line_11->setObjectName(QString::fromUtf8("line_11"));
        line_11->setFrameShape(QFrame::HLine);
        line_11->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_11, 2, 6, 1, 1);

        laFR = new QLabel(fPacketsAndTime);
        laFR->setObjectName(QString::fromUtf8("laFR"));

        gridLayout_5->addWidget(laFR, 3, 2, 2, 1, Qt::AlignHCenter);

        laFL = new QLabel(fPacketsAndTime);
        laFL->setObjectName(QString::fromUtf8("laFL"));

        gridLayout_5->addWidget(laFL, 3, 3, 2, 1, Qt::AlignHCenter);

        laFT = new QLabel(fPacketsAndTime);
        laFT->setObjectName(QString::fromUtf8("laFT"));

        gridLayout_5->addWidget(laFT, 3, 4, 2, 1, Qt::AlignHCenter);

        label_29 = new QLabel(fPacketsAndTime);
        label_29->setObjectName(QString::fromUtf8("label_29"));

        gridLayout_5->addWidget(label_29, 0, 6, 2, 1);


        gridLayout_4->addWidget(fPacketsAndTime, 4, 0, 1, 4);

        frame_10 = new QFrame(gbConnection);
        frame_10->setObjectName(QString::fromUtf8("frame_10"));
        frame_10->setMinimumSize(QSize(0, 30));
        frame_10->setMaximumSize(QSize(16777215, 16777215));
        frame_10->setFrameShape(QFrame::StyledPanel);
        frame_10->setFrameShadow(QFrame::Raised);
        verticalLayout_7 = new QVBoxLayout(frame_10);
        verticalLayout_7->setSpacing(1);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        fNetworkInfo = new QFrame(frame_10);
        fNetworkInfo->setObjectName(QString::fromUtf8("fNetworkInfo"));
        fNetworkInfo->setMinimumSize(QSize(0, 50));
        fNetworkInfo->setFrameShape(QFrame::StyledPanel);
        fNetworkInfo->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(fNetworkInfo);
        verticalLayout_3->setSpacing(2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_51 = new QLabel(fNetworkInfo);
        label_51->setObjectName(QString::fromUtf8("label_51"));

        verticalLayout_3->addWidget(label_51, 0, Qt::AlignHCenter);

        teNetworkInfo = new QTextEdit(fNetworkInfo);
        teNetworkInfo->setObjectName(QString::fromUtf8("teNetworkInfo"));
        teNetworkInfo->setReadOnly(true);

        verticalLayout_3->addWidget(teNetworkInfo);


        verticalLayout_7->addWidget(fNetworkInfo);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_6);

        verticalLayout_7->setStretch(0, 10);
        verticalLayout_7->setStretch(1, 1);

        gridLayout_4->addWidget(frame_10, 5, 0, 1, 4);


        verticalLayout_6->addWidget(gbConnection);

        twParameters->addTab(tConnection, QString());
        tCamera = new QWidget();
        tCamera->setObjectName(QString::fromUtf8("tCamera"));
        gridLayout_11 = new QGridLayout(tCamera);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        frame_15 = new QFrame(tCamera);
        frame_15->setObjectName(QString::fromUtf8("frame_15"));
        frame_15->setFrameShape(QFrame::StyledPanel);
        frame_15->setFrameShadow(QFrame::Raised);
        horizontalLayout_8 = new QHBoxLayout(frame_15);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        rbDoNothing = new QRadioButton(frame_15);
        rbDoNothing->setObjectName(QString::fromUtf8("rbDoNothing"));
        rbDoNothing->setChecked(true);

        horizontalLayout_8->addWidget(rbDoNothing);

        rbGetData = new QRadioButton(frame_15);
        rbGetData->setObjectName(QString::fromUtf8("rbGetData"));

        horizontalLayout_8->addWidget(rbGetData);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_14);


        gridLayout_11->addWidget(frame_15, 4, 0, 1, 1);

        frame_14 = new QFrame(tCamera);
        frame_14->setObjectName(QString::fromUtf8("frame_14"));
        frame_14->setFrameShape(QFrame::StyledPanel);
        frame_14->setFrameShadow(QFrame::Raised);
        gridLayout_15 = new QGridLayout(frame_14);
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        label_2 = new QLabel(frame_14);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_15->addWidget(label_2, 1, 0, 1, 1);

        sbFPS = new QSpinBox(frame_14);
        sbFPS->setObjectName(QString::fromUtf8("sbFPS"));
        sbFPS->setMinimum(1);
        sbFPS->setMaximum(90);
        sbFPS->setValue(30);

        gridLayout_15->addWidget(sbFPS, 1, 3, 1, 1);

        cbDisplayData = new QCheckBox(frame_14);
        cbDisplayData->setObjectName(QString::fromUtf8("cbDisplayData"));
        cbDisplayData->setChecked(true);

        gridLayout_15->addWidget(cbDisplayData, 1, 4, 1, 1);

        label_41 = new QLabel(frame_14);
        label_41->setObjectName(QString::fromUtf8("label_41"));

        gridLayout_15->addWidget(label_41, 1, 2, 1, 1);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_15->addItem(horizontalSpacer_13, 1, 5, 1, 1);

        fStateCam = new QFrame(frame_14);
        fStateCam->setObjectName(QString::fromUtf8("fStateCam"));
        fStateCam->setMinimumSize(QSize(25, 25));
        fStateCam->setMaximumSize(QSize(16777215, 25));
        fStateCam->setFrameShape(QFrame::StyledPanel);
        fStateCam->setFrameShadow(QFrame::Raised);

        gridLayout_15->addWidget(fStateCam, 1, 1, 1, 1);

        cbDataType = new QComboBox(frame_14);
        cbDataType->setObjectName(QString::fromUtf8("cbDataType"));

        gridLayout_15->addWidget(cbDataType, 0, 0, 1, 5);


        gridLayout_11->addWidget(frame_14, 2, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_11->addItem(verticalSpacer_4, 6, 0, 1, 1);

        frame_13 = new QFrame(tCamera);
        frame_13->setObjectName(QString::fromUtf8("frame_13"));
        frame_13->setFrameShape(QFrame::StyledPanel);
        frame_13->setFrameShadow(QFrame::Raised);
        gridLayout_14 = new QGridLayout(frame_13);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        widget = new QWidget(frame_13);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 2, 0, 2);
        pbOpen = new QPushButton(widget);
        pbOpen->setObjectName(QString::fromUtf8("pbOpen"));

        verticalLayout_2->addWidget(pbOpen);


        gridLayout_14->addWidget(widget, 0, 1, 1, 1);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_14->addItem(horizontalSpacer_12, 0, 7, 1, 1);

        pbClose = new QPushButton(frame_13);
        pbClose->setObjectName(QString::fromUtf8("pbClose"));

        gridLayout_14->addWidget(pbClose, 0, 2, 1, 1);


        gridLayout_11->addWidget(frame_13, 3, 0, 1, 1);

        twParameters->addTab(tCamera, QString());
        tModel = new QWidget();
        tModel->setObjectName(QString::fromUtf8("tModel"));
        verticalLayout_5 = new QVBoxLayout(tModel);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        gbCloudSettings = new QFrame(tModel);
        gbCloudSettings->setObjectName(QString::fromUtf8("gbCloudSettings"));
        gbCloudSettings->setMaximumSize(QSize(16777215, 16777215));
        gbCloudSettings->setFrameShape(QFrame::Box);
        gbCloudSettings->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(gbCloudSettings);
        verticalLayout_4->setSpacing(2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(2, 2, 2, 2);
        frame_7 = new QFrame(gbCloudSettings);
        frame_7->setObjectName(QString::fromUtf8("frame_7"));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        gridLayout_8 = new QGridLayout(frame_7);
        gridLayout_8->setSpacing(2);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer_7, 2, 6, 1, 1);

        label_47 = new QLabel(frame_7);
        label_47->setObjectName(QString::fromUtf8("label_47"));

        gridLayout_8->addWidget(label_47, 1, 3, 1, 1, Qt::AlignHCenter);

        label_49 = new QLabel(frame_7);
        label_49->setObjectName(QString::fromUtf8("label_49"));

        gridLayout_8->addWidget(label_49, 1, 5, 1, 1, Qt::AlignHCenter);

        label_48 = new QLabel(frame_7);
        label_48->setObjectName(QString::fromUtf8("label_48"));

        gridLayout_8->addWidget(label_48, 1, 4, 1, 1, Qt::AlignHCenter);

        dsbT00 = new QDoubleSpinBox(frame_7);
        dsbT00->setObjectName(QString::fromUtf8("dsbT00"));
        dsbT00->setDecimals(4);
        dsbT00->setMinimum(-1000.000000000000000);
        dsbT00->setMaximum(1000.000000000000000);
        dsbT00->setSingleStep(0.100000000000000);
        dsbT00->setValue(1.000000000000000);

        gridLayout_8->addWidget(dsbT00, 2, 2, 1, 1);

        dsbT10 = new QDoubleSpinBox(frame_7);
        dsbT10->setObjectName(QString::fromUtf8("dsbT10"));
        dsbT10->setDecimals(4);
        dsbT10->setMinimum(-1000.000000000000000);
        dsbT10->setMaximum(1000.000000000000000);
        dsbT10->setSingleStep(0.100000000000000);

        gridLayout_8->addWidget(dsbT10, 3, 2, 1, 1);

        dsbT01 = new QDoubleSpinBox(frame_7);
        dsbT01->setObjectName(QString::fromUtf8("dsbT01"));
        dsbT01->setDecimals(4);
        dsbT01->setMinimum(-1000.000000000000000);
        dsbT01->setMaximum(1000.000000000000000);
        dsbT01->setSingleStep(0.100000000000000);

        gridLayout_8->addWidget(dsbT01, 2, 3, 1, 1);

        dsbT02 = new QDoubleSpinBox(frame_7);
        dsbT02->setObjectName(QString::fromUtf8("dsbT02"));
        dsbT02->setDecimals(4);
        dsbT02->setMinimum(-1000.000000000000000);
        dsbT02->setMaximum(1000.000000000000000);
        dsbT02->setSingleStep(0.100000000000000);

        gridLayout_8->addWidget(dsbT02, 2, 4, 1, 1);

        dsbT20 = new QDoubleSpinBox(frame_7);
        dsbT20->setObjectName(QString::fromUtf8("dsbT20"));
        dsbT20->setDecimals(4);
        dsbT20->setMinimum(-1000.000000000000000);
        dsbT20->setMaximum(1000.000000000000000);
        dsbT20->setSingleStep(0.100000000000000);

        gridLayout_8->addWidget(dsbT20, 4, 2, 1, 1);

        dsbT12 = new QDoubleSpinBox(frame_7);
        dsbT12->setObjectName(QString::fromUtf8("dsbT12"));
        dsbT12->setDecimals(4);
        dsbT12->setMinimum(-1000.000000000000000);
        dsbT12->setMaximum(1000.000000000000000);
        dsbT12->setSingleStep(0.100000000000000);

        gridLayout_8->addWidget(dsbT12, 3, 4, 1, 1);

        dsbT11 = new QDoubleSpinBox(frame_7);
        dsbT11->setObjectName(QString::fromUtf8("dsbT11"));
        dsbT11->setDecimals(4);
        dsbT11->setMinimum(-1000.000000000000000);
        dsbT11->setMaximum(1000.000000000000000);
        dsbT11->setSingleStep(0.100000000000000);
        dsbT11->setValue(1.000000000000000);

        gridLayout_8->addWidget(dsbT11, 3, 3, 1, 1);

        dsbT23 = new QDoubleSpinBox(frame_7);
        dsbT23->setObjectName(QString::fromUtf8("dsbT23"));
        dsbT23->setDecimals(4);
        dsbT23->setMinimum(-1000.000000000000000);
        dsbT23->setMaximum(1000.000000000000000);
        dsbT23->setSingleStep(0.010000000000000);
        dsbT23->setValue(0.000000000000000);

        gridLayout_8->addWidget(dsbT23, 4, 5, 1, 1);

        dsbT13 = new QDoubleSpinBox(frame_7);
        dsbT13->setObjectName(QString::fromUtf8("dsbT13"));
        dsbT13->setDecimals(4);
        dsbT13->setMinimum(-1000.000000000000000);
        dsbT13->setMaximum(1000.000000000000000);
        dsbT13->setSingleStep(0.010000000000000);
        dsbT13->setValue(0.000000000000000);

        gridLayout_8->addWidget(dsbT13, 3, 5, 1, 1);

        dsbT21 = new QDoubleSpinBox(frame_7);
        dsbT21->setObjectName(QString::fromUtf8("dsbT21"));
        dsbT21->setDecimals(4);
        dsbT21->setMinimum(-1000.000000000000000);
        dsbT21->setMaximum(1000.000000000000000);
        dsbT21->setSingleStep(0.100000000000000);

        gridLayout_8->addWidget(dsbT21, 4, 3, 1, 1);

        dsbT22 = new QDoubleSpinBox(frame_7);
        dsbT22->setObjectName(QString::fromUtf8("dsbT22"));
        dsbT22->setDecimals(4);
        dsbT22->setMinimum(-1000.000000000000000);
        dsbT22->setMaximum(1000.000000000000000);
        dsbT22->setSingleStep(0.100000000000000);
        dsbT22->setValue(1.000000000000000);

        gridLayout_8->addWidget(dsbT22, 4, 4, 1, 1);

        label_43 = new QLabel(frame_7);
        label_43->setObjectName(QString::fromUtf8("label_43"));

        gridLayout_8->addWidget(label_43, 2, 1, 1, 1);

        label_46 = new QLabel(frame_7);
        label_46->setObjectName(QString::fromUtf8("label_46"));

        gridLayout_8->addWidget(label_46, 1, 2, 1, 1, Qt::AlignHCenter);

        label_44 = new QLabel(frame_7);
        label_44->setObjectName(QString::fromUtf8("label_44"));

        gridLayout_8->addWidget(label_44, 3, 1, 1, 1);

        dsbT03 = new QDoubleSpinBox(frame_7);
        dsbT03->setObjectName(QString::fromUtf8("dsbT03"));
        dsbT03->setDecimals(4);
        dsbT03->setMinimum(-1000.000000000000000);
        dsbT03->setMaximum(1000.000000000000000);
        dsbT03->setSingleStep(0.010000000000000);
        dsbT03->setValue(0.000000000000000);

        gridLayout_8->addWidget(dsbT03, 2, 5, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer_11, 2, 0, 1, 1);

        label_42 = new QLabel(frame_7);
        label_42->setObjectName(QString::fromUtf8("label_42"));

        gridLayout_8->addWidget(label_42, 0, 0, 1, 7, Qt::AlignHCenter);

        label_45 = new QLabel(frame_7);
        label_45->setObjectName(QString::fromUtf8("label_45"));

        gridLayout_8->addWidget(label_45, 4, 1, 1, 1);


        verticalLayout_4->addWidget(frame_7);

        line_4 = new QFrame(gbCloudSettings);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_4);

        frame_5 = new QFrame(gbCloudSettings);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setMinimumSize(QSize(0, 0));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        gridLayout_6 = new QGridLayout(frame_5);
        gridLayout_6->setSpacing(2);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        dsbRx = new QDoubleSpinBox(frame_5);
        dsbRx->setObjectName(QString::fromUtf8("dsbRx"));
        dsbRx->setEnabled(true);
        dsbRx->setDecimals(3);
        dsbRx->setMinimum(-10000.000000000000000);
        dsbRx->setMaximum(10000.000000000000000);
        dsbRx->setSingleStep(0.050000000000000);

        gridLayout_6->addWidget(dsbRx, 2, 3, 1, 1);

        label_13 = new QLabel(frame_5);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_6->addWidget(label_13, 2, 4, 1, 1);

        label_8 = new QLabel(frame_5);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_6->addWidget(label_8, 2, 2, 1, 1);

        dsbRy = new QDoubleSpinBox(frame_5);
        dsbRy->setObjectName(QString::fromUtf8("dsbRy"));
        dsbRy->setEnabled(true);
        dsbRy->setDecimals(3);
        dsbRy->setMinimum(-10000.000000000000000);
        dsbRy->setMaximum(10000.000000000000000);
        dsbRy->setSingleStep(0.050000000000000);
        dsbRy->setValue(0.000000000000000);

        gridLayout_6->addWidget(dsbRy, 2, 5, 1, 1);

        label_22 = new QLabel(frame_5);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        gridLayout_6->addWidget(label_22, 2, 6, 1, 1);

        dsbRz = new QDoubleSpinBox(frame_5);
        dsbRz->setObjectName(QString::fromUtf8("dsbRz"));
        dsbRz->setEnabled(true);
        dsbRz->setDecimals(3);
        dsbRz->setMinimum(-10000.000000000000000);
        dsbRz->setMaximum(10000.000000000000000);
        dsbRz->setSingleStep(0.050000000000000);

        gridLayout_6->addWidget(dsbRz, 2, 7, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_10, 2, 1, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_8, 2, 8, 1, 1);

        label_16 = new QLabel(frame_5);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setEnabled(true);

        gridLayout_6->addWidget(label_16, 0, 0, 1, 9, Qt::AlignHCenter);

        dsbSx = new QDoubleSpinBox(frame_5);
        dsbSx->setObjectName(QString::fromUtf8("dsbSx"));
        dsbSx->setDecimals(3);
        dsbSx->setMinimum(-10000.000000000000000);
        dsbSx->setMaximum(10000.000000000000000);
        dsbSx->setSingleStep(0.001000000000000);
        dsbSx->setValue(1.000000000000000);

        gridLayout_6->addWidget(dsbSx, 3, 3, 1, 1);

        dsbSy = new QDoubleSpinBox(frame_5);
        dsbSy->setObjectName(QString::fromUtf8("dsbSy"));
        dsbSy->setDecimals(3);
        dsbSy->setMinimum(-10000.000000000000000);
        dsbSy->setMaximum(10000.000000000000000);
        dsbSy->setSingleStep(0.001000000000000);
        dsbSy->setValue(1.000000000000000);

        gridLayout_6->addWidget(dsbSy, 3, 5, 1, 1);

        dsbSz = new QDoubleSpinBox(frame_5);
        dsbSz->setObjectName(QString::fromUtf8("dsbSz"));
        dsbSz->setDecimals(3);
        dsbSz->setMinimum(-10000.000000000000000);
        dsbSz->setMaximum(10000.000000000000000);
        dsbSz->setSingleStep(0.001000000000000);
        dsbSz->setValue(1.000000000000000);

        gridLayout_6->addWidget(dsbSz, 3, 7, 1, 1);

        label_14 = new QLabel(frame_5);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_6->addWidget(label_14, 3, 2, 1, 1);

        label_15 = new QLabel(frame_5);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_6->addWidget(label_15, 3, 4, 1, 1);

        label_57 = new QLabel(frame_5);
        label_57->setObjectName(QString::fromUtf8("label_57"));

        gridLayout_6->addWidget(label_57, 3, 6, 1, 1);

        dsbTx = new QDoubleSpinBox(frame_5);
        dsbTx->setObjectName(QString::fromUtf8("dsbTx"));
        dsbTx->setDecimals(3);
        dsbTx->setMinimum(-10000.000000000000000);
        dsbTx->setMaximum(10000.000000000000000);
        dsbTx->setSingleStep(0.001000000000000);

        gridLayout_6->addWidget(dsbTx, 1, 3, 1, 1);

        dsbTy = new QDoubleSpinBox(frame_5);
        dsbTy->setObjectName(QString::fromUtf8("dsbTy"));
        dsbTy->setDecimals(3);
        dsbTy->setMinimum(-10000.000000000000000);
        dsbTy->setMaximum(10000.000000000000000);
        dsbTy->setSingleStep(0.001000000000000);

        gridLayout_6->addWidget(dsbTy, 1, 5, 1, 1);

        dsbTz = new QDoubleSpinBox(frame_5);
        dsbTz->setObjectName(QString::fromUtf8("dsbTz"));
        dsbTz->setDecimals(3);
        dsbTz->setMinimum(-10000.000000000000000);
        dsbTz->setMaximum(10000.000000000000000);
        dsbTz->setSingleStep(0.001000000000000);

        gridLayout_6->addWidget(dsbTz, 1, 7, 1, 1);

        label_58 = new QLabel(frame_5);
        label_58->setObjectName(QString::fromUtf8("label_58"));

        gridLayout_6->addWidget(label_58, 1, 2, 1, 1);

        label_59 = new QLabel(frame_5);
        label_59->setObjectName(QString::fromUtf8("label_59"));

        gridLayout_6->addWidget(label_59, 1, 4, 1, 1);

        label_60 = new QLabel(frame_5);
        label_60->setObjectName(QString::fromUtf8("label_60"));

        gridLayout_6->addWidget(label_60, 1, 6, 1, 1);


        verticalLayout_4->addWidget(frame_5);


        verticalLayout_5->addWidget(gbCloudSettings);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_3);

        twParameters->addTab(tModel, QString());
        tFilters = new QWidget();
        tFilters->setObjectName(QString::fromUtf8("tFilters"));
        gridLayout_3 = new QGridLayout(tFilters);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_5 = new QLabel(tFilters);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_3->addWidget(label_5, 4, 0, 1, 1);

        line_7 = new QFrame(tFilters);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_7, 1, 0, 1, 1);

        line_14 = new QFrame(tFilters);
        line_14->setObjectName(QString::fromUtf8("line_14"));
        line_14->setFrameShape(QFrame::HLine);
        line_14->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_14, 3, 0, 1, 1);

        fDepthMinMax = new QFrame(tFilters);
        fDepthMinMax->setObjectName(QString::fromUtf8("fDepthMinMax"));
        fDepthMinMax->setMaximumSize(QSize(16777215, 16777215));
        fDepthMinMax->setFrameShape(QFrame::NoFrame);
        fDepthMinMax->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(fDepthMinMax);
        gridLayout->setSpacing(2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(2, 2, 2, 2);
        label_19 = new QLabel(fDepthMinMax);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        gridLayout->addWidget(label_19, 4, 2, 1, 1, Qt::AlignHCenter);

        label_4 = new QLabel(fDepthMinMax);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 5, 0, 2, 1);

        label_18 = new QLabel(fDepthMinMax);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout->addWidget(label_18, 4, 1, 1, 1, Qt::AlignHCenter);

        dsbMaxDepth = new QDoubleSpinBox(fDepthMinMax);
        dsbMaxDepth->setObjectName(QString::fromUtf8("dsbMaxDepth"));
        dsbMaxDepth->setMaximum(10.000000000000000);
        dsbMaxDepth->setSingleStep(0.100000000000000);
        dsbMaxDepth->setValue(3.500000000000000);

        gridLayout->addWidget(dsbMaxDepth, 5, 2, 1, 1);

        dsbMinDepth = new QDoubleSpinBox(fDepthMinMax);
        dsbMinDepth->setObjectName(QString::fromUtf8("dsbMinDepth"));
        dsbMinDepth->setMaximum(8.500000000000000);
        dsbMinDepth->setSingleStep(0.100000000000000);
        dsbMinDepth->setValue(0.300000000000000);

        gridLayout->addWidget(dsbMinDepth, 5, 1, 1, 1);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_15, 5, 3, 1, 1);


        gridLayout_3->addWidget(fDepthMinMax, 11, 0, 1, 1);

        frame_4 = new QFrame(tFilters);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setFrameShape(QFrame::NoFrame);
        frame_4->setFrameShadow(QFrame::Raised);
        gridLayout_16 = new QGridLayout(frame_4);
        gridLayout_16->setSpacing(2);
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        gridLayout_16->setContentsMargins(2, 2, 2, 2);
        label_17 = new QLabel(frame_4);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout_16->addWidget(label_17, 1, 0, 1, 3);

        sbMaxDiffB = new QSpinBox(frame_4);
        sbMaxDiffB->setObjectName(QString::fromUtf8("sbMaxDiffB"));
        sbMaxDiffB->setEnabled(false);
        sbMaxDiffB->setMaximum(255);
        sbMaxDiffB->setValue(40);

        gridLayout_16->addWidget(sbMaxDiffB, 5, 3, 1, 1);

        sbGFiltered = new QSpinBox(frame_4);
        sbGFiltered->setObjectName(QString::fromUtf8("sbGFiltered"));
        sbGFiltered->setMaximum(255);
        sbGFiltered->setValue(40);

        gridLayout_16->addWidget(sbGFiltered, 4, 2, 1, 1);

        dsbUF = new QDoubleSpinBox(frame_4);
        dsbUF->setObjectName(QString::fromUtf8("dsbUF"));
        dsbUF->setMaximum(5.000000000000000);
        dsbUF->setSingleStep(0.010000000000000);
        dsbUF->setValue(1.000000000000000);

        gridLayout_16->addWidget(dsbUF, 2, 2, 1, 1);

        label_40 = new QLabel(frame_4);
        label_40->setObjectName(QString::fromUtf8("label_40"));

        gridLayout_16->addWidget(label_40, 5, 0, 1, 1);

        sbMaxDiffR = new QSpinBox(frame_4);
        sbMaxDiffR->setObjectName(QString::fromUtf8("sbMaxDiffR"));
        sbMaxDiffR->setMaximum(255);
        sbMaxDiffR->setValue(40);

        gridLayout_16->addWidget(sbMaxDiffR, 5, 1, 1, 1);

        label_39 = new QLabel(frame_4);
        label_39->setObjectName(QString::fromUtf8("label_39"));

        gridLayout_16->addWidget(label_39, 4, 0, 1, 1);

        dsbYF = new QDoubleSpinBox(frame_4);
        dsbYF->setObjectName(QString::fromUtf8("dsbYF"));
        dsbYF->setMaximum(5.000000000000000);
        dsbYF->setSingleStep(0.010000000000000);
        dsbYF->setValue(1.000000000000000);

        gridLayout_16->addWidget(dsbYF, 2, 1, 1, 1);

        sbBFiltered = new QSpinBox(frame_4);
        sbBFiltered->setObjectName(QString::fromUtf8("sbBFiltered"));
        sbBFiltered->setMaximum(255);
        sbBFiltered->setValue(40);

        gridLayout_16->addWidget(sbBFiltered, 4, 3, 1, 1);

        label_6 = new QLabel(frame_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_16->addWidget(label_6, 2, 0, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_16->addItem(horizontalSpacer_9, 4, 4, 1, 1);

        cbFilterDepthWithColor = new QCheckBox(frame_4);
        cbFilterDepthWithColor->setObjectName(QString::fromUtf8("cbFilterDepthWithColor"));

        gridLayout_16->addWidget(cbFilterDepthWithColor, 3, 0, 1, 3);

        sbMaxDiffG = new QSpinBox(frame_4);
        sbMaxDiffG->setObjectName(QString::fromUtf8("sbMaxDiffG"));
        sbMaxDiffG->setEnabled(false);
        sbMaxDiffG->setMaximum(255);
        sbMaxDiffG->setValue(40);

        gridLayout_16->addWidget(sbMaxDiffG, 5, 2, 1, 1);

        dsbVF = new QDoubleSpinBox(frame_4);
        dsbVF->setObjectName(QString::fromUtf8("dsbVF"));
        dsbVF->setMaximum(5.000000000000000);
        dsbVF->setSingleStep(0.010000000000000);
        dsbVF->setValue(1.000000000000000);

        gridLayout_16->addWidget(dsbVF, 2, 3, 1, 1);

        sbRFiltered = new QSpinBox(frame_4);
        sbRFiltered->setObjectName(QString::fromUtf8("sbRFiltered"));
        sbRFiltered->setMaximum(255);
        sbRFiltered->setValue(246);

        gridLayout_16->addWidget(sbRFiltered, 4, 1, 1, 1);

        sbJpegCompressionRate = new QSpinBox(frame_4);
        sbJpegCompressionRate->setObjectName(QString::fromUtf8("sbJpegCompressionRate"));
        sbJpegCompressionRate->setMinimum(1);
        sbJpegCompressionRate->setMaximum(100);
        sbJpegCompressionRate->setValue(80);

        gridLayout_16->addWidget(sbJpegCompressionRate, 6, 1, 1, 1);

        label_62 = new QLabel(frame_4);
        label_62->setObjectName(QString::fromUtf8("label_62"));

        gridLayout_16->addWidget(label_62, 6, 0, 1, 1);


        gridLayout_3->addWidget(frame_4, 0, 0, 1, 1);

        fInfrared = new QFrame(tFilters);
        fInfrared->setObjectName(QString::fromUtf8("fInfrared"));
        fInfrared->setMinimumSize(QSize(0, 0));
        fInfrared->setFrameShape(QFrame::NoFrame);
        fInfrared->setFrameShadow(QFrame::Raised);
        gridLayout_10 = new QGridLayout(fInfrared);
        gridLayout_10->setSpacing(2);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_10->setContentsMargins(2, 2, 2, 2);
        label_55 = new QLabel(fInfrared);
        label_55->setObjectName(QString::fromUtf8("label_55"));

        gridLayout_10->addWidget(label_55, 2, 2, 1, 1, Qt::AlignHCenter);

        label_20 = new QLabel(fInfrared);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        gridLayout_10->addWidget(label_20, 4, 1, 1, 1);

        cbInfraInvert = new QCheckBox(fInfrared);
        cbInfraInvert->setObjectName(QString::fromUtf8("cbInfraInvert"));

        gridLayout_10->addWidget(cbInfraInvert, 4, 5, 1, 1);

        sbInfraMinRange = new QSpinBox(fInfrared);
        sbInfraMinRange->setObjectName(QString::fromUtf8("sbInfraMinRange"));
        sbInfraMinRange->setMaximum(65000);

        gridLayout_10->addWidget(sbInfraMinRange, 4, 2, 1, 1);

        sbInfraMaxRange = new QSpinBox(fInfrared);
        sbInfraMaxRange->setObjectName(QString::fromUtf8("sbInfraMaxRange"));
        sbInfraMaxRange->setMaximum(65000);
        sbInfraMaxRange->setValue(65000);

        gridLayout_10->addWidget(sbInfraMaxRange, 4, 3, 1, 1);

        cbInfraBinary = new QCheckBox(fInfrared);
        cbInfraBinary->setObjectName(QString::fromUtf8("cbInfraBinary"));

        gridLayout_10->addWidget(cbInfraBinary, 3, 5, 1, 1);

        sbMinInfra = new QSpinBox(fInfrared);
        sbMinInfra->setObjectName(QString::fromUtf8("sbMinInfra"));
        sbMinInfra->setMaximum(65000);
        sbMinInfra->setSingleStep(100);

        gridLayout_10->addWidget(sbMinInfra, 3, 2, 1, 1);

        label_38 = new QLabel(fInfrared);
        label_38->setObjectName(QString::fromUtf8("label_38"));

        gridLayout_10->addWidget(label_38, 3, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_10->addItem(horizontalSpacer_3, 3, 8, 1, 1);

        sbMaxInfra = new QSpinBox(fInfrared);
        sbMaxInfra->setObjectName(QString::fromUtf8("sbMaxInfra"));
        sbMaxInfra->setMaximum(65000);
        sbMaxInfra->setSingleStep(100);
        sbMaxInfra->setValue(65000);

        gridLayout_10->addWidget(sbMaxInfra, 3, 3, 1, 1);

        label_36 = new QLabel(fInfrared);
        label_36->setObjectName(QString::fromUtf8("label_36"));

        gridLayout_10->addWidget(label_36, 2, 3, 1, 1, Qt::AlignHCenter);

        line_3 = new QFrame(fInfrared);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout_10->addWidget(line_3, 3, 4, 2, 1);

        label_37 = new QLabel(fInfrared);
        label_37->setObjectName(QString::fromUtf8("label_37"));

        gridLayout_10->addWidget(label_37, 0, 1, 1, 8);


        gridLayout_3->addWidget(fInfrared, 2, 0, 1, 1);

        fSize = new QFrame(tFilters);
        fSize->setObjectName(QString::fromUtf8("fSize"));
        fSize->setFrameShape(QFrame::NoFrame);
        fSize->setFrameShadow(QFrame::Raised);
        gridLayout_12 = new QGridLayout(fSize);
        gridLayout_12->setSpacing(2);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        gridLayout_12->setContentsMargins(2, 2, 2, 2);
        label_53 = new QLabel(fSize);
        label_53->setObjectName(QString::fromUtf8("label_53"));

        gridLayout_12->addWidget(label_53, 0, 2, 1, 1, Qt::AlignHCenter);

        sbMaxW = new QSpinBox(fSize);
        sbMaxW->setObjectName(QString::fromUtf8("sbMaxW"));
        sbMaxW->setMaximum(10000);

        gridLayout_12->addWidget(sbMaxW, 1, 2, 1, 1);

        label_25 = new QLabel(fSize);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        gridLayout_12->addWidget(label_25, 2, 0, 1, 1);

        label_52 = new QLabel(fSize);
        label_52->setObjectName(QString::fromUtf8("label_52"));

        gridLayout_12->addWidget(label_52, 0, 1, 1, 1, Qt::AlignHCenter);

        label_24 = new QLabel(fSize);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        gridLayout_12->addWidget(label_24, 1, 0, 1, 1);

        sbMinW = new QSpinBox(fSize);
        sbMinW->setObjectName(QString::fromUtf8("sbMinW"));
        sbMinW->setMaximum(1000);

        gridLayout_12->addWidget(sbMinW, 1, 1, 1, 1);

        sbMaxH = new QSpinBox(fSize);
        sbMaxH->setObjectName(QString::fromUtf8("sbMaxH"));
        sbMaxH->setMaximum(1000);

        gridLayout_12->addWidget(sbMaxH, 2, 2, 1, 1);

        sbMinH = new QSpinBox(fSize);
        sbMinH->setObjectName(QString::fromUtf8("sbMinH"));
        sbMinH->setMaximum(1000);

        gridLayout_12->addWidget(sbMinH, 2, 1, 1, 1);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_12->addItem(horizontalSpacer_16, 1, 3, 1, 1);


        gridLayout_3->addWidget(fSize, 5, 0, 1, 1);

        frame = new QFrame(tFilters);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setSpacing(2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(2, 2, 2, 2);
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 6, 1, 1, 1);

        label_27 = new QLabel(frame);
        label_27->setObjectName(QString::fromUtf8("label_27"));

        gridLayout_2->addWidget(label_27, 4, 1, 1, 1);

        label_7 = new QLabel(frame);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_2->addWidget(label_7, 1, 0, 1, 1);

        cbEnableSmoothing = new QCheckBox(frame);
        cbEnableSmoothing->setObjectName(QString::fromUtf8("cbEnableSmoothing"));
        cbEnableSmoothing->setEnabled(false);

        gridLayout_2->addWidget(cbEnableSmoothing, 2, 0, 1, 1);

        sbSmoothingKernelSize = new QSpinBox(frame);
        sbSmoothingKernelSize->setObjectName(QString::fromUtf8("sbSmoothingKernelSize"));
        sbSmoothingKernelSize->setEnabled(false);
        sbSmoothingKernelSize->setValue(31);

        gridLayout_2->addWidget(sbSmoothingKernelSize, 3, 2, 1, 1);

        frame_11 = new QFrame(frame);
        frame_11->setObjectName(QString::fromUtf8("frame_11"));
        frame_11->setFrameShape(QFrame::StyledPanel);
        frame_11->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_11);
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(2, 2, 2, 2);
        label_28 = new QLabel(frame_11);
        label_28->setObjectName(QString::fromUtf8("label_28"));

        horizontalLayout_2->addWidget(label_28);

        sbMinNeighboursNb = new QSpinBox(frame_11);
        sbMinNeighboursNb->setObjectName(QString::fromUtf8("sbMinNeighboursNb"));
        sbMinNeighboursNb->setMinimum(1);
        sbMinNeighboursNb->setMaximum(5);

        horizontalLayout_2->addWidget(sbMinNeighboursNb);

        label_54 = new QLabel(frame_11);
        label_54->setObjectName(QString::fromUtf8("label_54"));

        horizontalLayout_2->addWidget(label_54);

        sbMinNeighboursLoops = new QSpinBox(frame_11);
        sbMinNeighboursLoops->setObjectName(QString::fromUtf8("sbMinNeighboursLoops"));
        sbMinNeighboursLoops->setMinimum(0);
        sbMinNeighboursLoops->setMaximum(10);
        sbMinNeighboursLoops->setValue(1);

        horizontalLayout_2->addWidget(sbMinNeighboursLoops);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_17);


        gridLayout_2->addWidget(frame_11, 7, 0, 1, 4);

        cbErosion = new QCheckBox(frame);
        cbErosion->setObjectName(QString::fromUtf8("cbErosion"));
        cbErosion->setChecked(true);

        gridLayout_2->addWidget(cbErosion, 4, 0, 1, 1);

        sbMinErosionValue = new QSpinBox(frame);
        sbMinErosionValue->setObjectName(QString::fromUtf8("sbMinErosionValue"));
        sbMinErosionValue->setMaximum(255);
        sbMinErosionValue->setValue(255);

        gridLayout_2->addWidget(sbMinErosionValue, 5, 2, 1, 1);

        frame_12 = new QFrame(frame);
        frame_12->setObjectName(QString::fromUtf8("frame_12"));
        frame_12->setFrameShape(QFrame::StyledPanel);
        frame_12->setFrameShadow(QFrame::Raised);
        horizontalLayout_5 = new QHBoxLayout(frame_12);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        cbTemporal = new QCheckBox(frame_12);
        cbTemporal->setObjectName(QString::fromUtf8("cbTemporal"));

        horizontalLayout_5->addWidget(cbTemporal);

        label_11 = new QLabel(frame_12);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setEnabled(false);

        horizontalLayout_5->addWidget(label_11);

        dsbVMax = new QDoubleSpinBox(frame_12);
        dsbVMax->setObjectName(QString::fromUtf8("dsbVMax"));
        dsbVMax->setEnabled(false);
        dsbVMax->setSingleStep(0.010000000000000);
        dsbVMax->setValue(1.000000000000000);

        horizontalLayout_5->addWidget(dsbVMax);

        label_12 = new QLabel(frame_12);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setEnabled(false);

        horizontalLayout_5->addWidget(label_12);

        dsbGMin = new QDoubleSpinBox(frame_12);
        dsbGMin->setObjectName(QString::fromUtf8("dsbGMin"));
        dsbGMin->setEnabled(false);
        dsbGMin->setSingleStep(0.010000000000000);
        dsbGMin->setValue(0.100000000000000);

        horizontalLayout_5->addWidget(dsbGMin);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_18);


        gridLayout_2->addWidget(frame_12, 10, 0, 1, 4);

        cbErosionType = new QComboBox(frame);
        cbErosionType->addItem(QString());
        cbErosionType->addItem(QString());
        cbErosionType->addItem(QString());
        cbErosionType->setObjectName(QString::fromUtf8("cbErosionType"));
        cbErosionType->setMinimumSize(QSize(75, 0));

        gridLayout_2->addWidget(cbErosionType, 4, 2, 1, 1);

        sbSizeKernelErode = new QSpinBox(frame);
        sbSizeKernelErode->setObjectName(QString::fromUtf8("sbSizeKernelErode"));
        sbSizeKernelErode->setMinimum(1);
        sbSizeKernelErode->setMaximum(10);
        sbSizeKernelErode->setSingleStep(1);
        sbSizeKernelErode->setValue(1);

        gridLayout_2->addWidget(sbSizeKernelErode, 6, 2, 1, 1);

        label_30 = new QLabel(frame);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setEnabled(false);

        gridLayout_2->addWidget(label_30, 2, 1, 1, 1);

        label_26 = new QLabel(frame);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        gridLayout_2->addWidget(label_26, 5, 1, 1, 1);

        label_31 = new QLabel(frame);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setEnabled(false);

        gridLayout_2->addWidget(label_31, 3, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 2, 3, 1, 1);

        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_17 = new QGridLayout(frame_2);
        gridLayout_17->setObjectName(QString::fromUtf8("gridLayout_17"));
        dsbOffsetAfterMin = new QDoubleSpinBox(frame_2);
        dsbOffsetAfterMin->setObjectName(QString::fromUtf8("dsbOffsetAfterMin"));
        dsbOffsetAfterMin->setMinimum(-1.000000000000000);
        dsbOffsetAfterMin->setMaximum(10.000000000000000);
        dsbOffsetAfterMin->setSingleStep(0.010000000000000);
        dsbOffsetAfterMin->setValue(-1.000000000000000);

        gridLayout_17->addWidget(dsbOffsetAfterMin, 0, 1, 1, 1);

        label_9 = new QLabel(frame_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_17->addWidget(label_9, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_17->addItem(horizontalSpacer, 0, 2, 1, 1);

        label_10 = new QLabel(frame_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_17->addWidget(label_10, 1, 0, 1, 1);

        dsbVMin = new QDoubleSpinBox(frame_2);
        dsbVMin->setObjectName(QString::fromUtf8("dsbVMin"));
        dsbVMin->setSingleStep(0.010000000000000);

        gridLayout_17->addWidget(dsbVMin, 1, 1, 1, 1);


        gridLayout_2->addWidget(frame_2, 8, 0, 1, 4);

        cbSmoothingMethod = new QComboBox(frame);
        cbSmoothingMethod->addItem(QString());
        cbSmoothingMethod->addItem(QString());
        cbSmoothingMethod->addItem(QString());
        cbSmoothingMethod->addItem(QString());
        cbSmoothingMethod->setObjectName(QString::fromUtf8("cbSmoothingMethod"));
        cbSmoothingMethod->setEnabled(false);
        cbSmoothingMethod->setMinimumSize(QSize(125, 0));

        gridLayout_2->addWidget(cbSmoothingMethod, 2, 2, 1, 1);

        dsbLocalDiff = new QDoubleSpinBox(frame);
        dsbLocalDiff->setObjectName(QString::fromUtf8("dsbLocalDiff"));
        dsbLocalDiff->setDecimals(3);
        dsbLocalDiff->setMinimum(-1.000000000000000);
        dsbLocalDiff->setMaximum(1000.000000000000000);
        dsbLocalDiff->setSingleStep(0.100000000000000);
        dsbLocalDiff->setValue(8.000000000000000);

        gridLayout_2->addWidget(dsbLocalDiff, 1, 1, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_5, 11, 2, 1, 1);

        widget_2 = new QWidget(frame);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));

        gridLayout_2->addWidget(widget_2, 9, 0, 1, 2);


        gridLayout_3->addWidget(frame, 12, 0, 1, 2);

        twParameters->addTab(tFilters, QString());
        tDisplay = new QWidget();
        tDisplay->setObjectName(QString::fromUtf8("tDisplay"));
        gridLayout_9 = new QGridLayout(tDisplay);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        frame_6 = new QFrame(tDisplay);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        gridLayout_7 = new QGridLayout(frame_6);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setHorizontalSpacing(2);
        gridLayout_7->setVerticalSpacing(3);
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        line_5 = new QFrame(frame_6);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        gridLayout_7->addWidget(line_5, 6, 0, 1, 3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_2, 4, 2, 1, 1);

        label_33 = new QLabel(frame_6);
        label_33->setObjectName(QString::fromUtf8("label_33"));

        gridLayout_7->addWidget(label_33, 4, 0, 1, 1);

        cbDisplayCloud = new QCheckBox(frame_6);
        cbDisplayCloud->setObjectName(QString::fromUtf8("cbDisplayCloud"));
        cbDisplayCloud->setChecked(true);

        gridLayout_7->addWidget(cbDisplayCloud, 1, 0, 1, 2);

        label_56 = new QLabel(frame_6);
        label_56->setObjectName(QString::fromUtf8("label_56"));

        gridLayout_7->addWidget(label_56, 5, 0, 1, 1);

        laSizeCloud = new QLabel(frame_6);
        laSizeCloud->setObjectName(QString::fromUtf8("laSizeCloud"));

        gridLayout_7->addWidget(laSizeCloud, 5, 1, 1, 1);

        label = new QLabel(frame_6);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_7->addWidget(label, 0, 0, 1, 3, Qt::AlignHCenter);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_7->addItem(verticalSpacer_2, 8, 0, 1, 1);

        dsbSizePts = new QDoubleSpinBox(frame_6);
        dsbSizePts->setObjectName(QString::fromUtf8("dsbSizePts"));
        dsbSizePts->setDecimals(2);
        dsbSizePts->setMinimum(0.010000000000000);
        dsbSizePts->setMaximum(250.000000000000000);
        dsbSizePts->setSingleStep(0.100000000000000);
        dsbSizePts->setValue(3.000000000000000);

        gridLayout_7->addWidget(dsbSizePts, 4, 1, 1, 1);

        cbForceCloudColor = new QCheckBox(frame_6);
        cbForceCloudColor->setObjectName(QString::fromUtf8("cbForceCloudColor"));

        gridLayout_7->addWidget(cbForceCloudColor, 2, 0, 1, 2);

        frame_8 = new QFrame(frame_6);
        frame_8->setObjectName(QString::fromUtf8("frame_8"));
        frame_8->setFrameShape(QFrame::StyledPanel);
        frame_8->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_8);
        horizontalLayout_3->setSpacing(2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 2, 0, 2);
        label_50 = new QLabel(frame_8);
        label_50->setObjectName(QString::fromUtf8("label_50"));

        horizontalLayout_3->addWidget(label_50);

        sbCloudColorR = new QSpinBox(frame_8);
        sbCloudColorR->setObjectName(QString::fromUtf8("sbCloudColorR"));
        sbCloudColorR->setMaximum(255);
        sbCloudColorR->setValue(255);

        horizontalLayout_3->addWidget(sbCloudColorR);

        sbCloudColorG = new QSpinBox(frame_8);
        sbCloudColorG->setObjectName(QString::fromUtf8("sbCloudColorG"));
        sbCloudColorG->setMaximum(255);

        horizontalLayout_3->addWidget(sbCloudColorG);

        sbCloudColorB = new QSpinBox(frame_8);
        sbCloudColorB->setObjectName(QString::fromUtf8("sbCloudColorB"));
        sbCloudColorB->setMaximum(255);

        horizontalLayout_3->addWidget(sbCloudColorB);


        gridLayout_7->addWidget(frame_8, 3, 0, 1, 2);


        gridLayout_9->addWidget(frame_6, 0, 0, 1, 1);

        twParameters->addTab(tDisplay, QString());

        verticalLayout->addWidget(twParameters);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(GrabberParametersUI);

        twParameters->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(GrabberParametersUI);
    } // setupUi

    void retranslateUi(QWidget *GrabberParametersUI)
    {
        GrabberParametersUI->setWindowTitle(QCoreApplication::translate("GrabberParametersUI", "Form", nullptr));
        laPort->setText(QCoreApplication::translate("GrabberParametersUI", "Port:", nullptr));
        laR->setText(QCoreApplication::translate("GrabberParametersUI", "[R]", nullptr));
        laW->setText(QCoreApplication::translate("GrabberParametersUI", "W", nullptr));
        laR_2->setText(QCoreApplication::translate("GrabberParametersUI", "R", nullptr));
        pbConnect->setText(QCoreApplication::translate("GrabberParametersUI", "Connect ", nullptr));
        laIp->setText(QCoreApplication::translate("GrabberParametersUI", "Address: [W]", nullptr));
        leWAddress->setText(QString());
        laInterface->setText(QCoreApplication::translate("GrabberParametersUI", "Interface:", nullptr));
        label_63->setText(QCoreApplication::translate("GrabberParametersUI", "W", nullptr));
        pbDisconnect->setText(QCoreApplication::translate("GrabberParametersUI", "Disconnect", nullptr));
        label_23->setText(QCoreApplication::translate("GrabberParametersUI", "Received", nullptr));
        laPR->setText(QCoreApplication::translate("GrabberParametersUI", "...", nullptr));
        laPTot->setText(QCoreApplication::translate("GrabberParametersUI", "...", nullptr));
        label_32->setText(QCoreApplication::translate("GrabberParametersUI", "   Lost", nullptr));
        label_21->setText(QCoreApplication::translate("GrabberParametersUI", "<b>Packets</b>", nullptr));
        label_35->setText(QCoreApplication::translate("GrabberParametersUI", "  Total", nullptr));
        laPL->setText(QCoreApplication::translate("GrabberParametersUI", "...", nullptr));
        label_61->setText(QCoreApplication::translate("GrabberParametersUI", "<b> Frames</b>", nullptr));
        laTTotal->setText(QCoreApplication::translate("GrabberParametersUI", "...", nullptr));
        laFR->setText(QCoreApplication::translate("GrabberParametersUI", "...", nullptr));
        laFL->setText(QCoreApplication::translate("GrabberParametersUI", "...", nullptr));
        laFT->setText(QCoreApplication::translate("GrabberParametersUI", "...", nullptr));
        label_29->setText(QCoreApplication::translate("GrabberParametersUI", "<html><head/><body><p><span style=\" font-weight:600;\">Time last frame</span></p></body></html>", nullptr));
        label_51->setText(QCoreApplication::translate("GrabberParametersUI", "<b> Network info</b>", nullptr));
        twParameters->setTabText(twParameters->indexOf(tConnection), QCoreApplication::translate("GrabberParametersUI", "Net.", nullptr));
        rbDoNothing->setText(QCoreApplication::translate("GrabberParametersUI", "Do nothing", nullptr));
        rbGetData->setText(QCoreApplication::translate("GrabberParametersUI", "Get Data", nullptr));
        label_2->setText(QCoreApplication::translate("GrabberParametersUI", "Is open?", nullptr));
        cbDisplayData->setText(QCoreApplication::translate("GrabberParametersUI", "Display", nullptr));
        label_41->setText(QCoreApplication::translate("GrabberParametersUI", "FPS", nullptr));
        pbOpen->setText(QCoreApplication::translate("GrabberParametersUI", "Open", nullptr));
        pbClose->setText(QCoreApplication::translate("GrabberParametersUI", "Close", nullptr));
        twParameters->setTabText(twParameters->indexOf(tCamera), QCoreApplication::translate("GrabberParametersUI", "Cam.", nullptr));
        label_47->setText(QCoreApplication::translate("GrabberParametersUI", "Rot c1", nullptr));
        label_49->setText(QCoreApplication::translate("GrabberParametersUI", "Tr", nullptr));
        label_48->setText(QCoreApplication::translate("GrabberParametersUI", "Rot c2", nullptr));
        label_43->setText(QCoreApplication::translate("GrabberParametersUI", "Rot r0", nullptr));
        label_46->setText(QCoreApplication::translate("GrabberParametersUI", "Rot c0", nullptr));
        label_44->setText(QCoreApplication::translate("GrabberParametersUI", "Rot r1", nullptr));
        label_42->setText(QCoreApplication::translate("GrabberParametersUI", "<b>Transformation matrix</b>", nullptr));
        label_45->setText(QCoreApplication::translate("GrabberParametersUI", "Rot r2", nullptr));
        label_13->setText(QCoreApplication::translate("GrabberParametersUI", "Ry", nullptr));
        label_8->setText(QCoreApplication::translate("GrabberParametersUI", "Rx", nullptr));
        label_22->setText(QCoreApplication::translate("GrabberParametersUI", "Rz", nullptr));
        label_16->setText(QCoreApplication::translate("GrabberParametersUI", "<b>Offset matrix</b>", nullptr));
        label_14->setText(QCoreApplication::translate("GrabberParametersUI", "Sx", nullptr));
        label_15->setText(QCoreApplication::translate("GrabberParametersUI", "Sy", nullptr));
        label_57->setText(QCoreApplication::translate("GrabberParametersUI", "Sz", nullptr));
        label_58->setText(QCoreApplication::translate("GrabberParametersUI", "Tx", nullptr));
        label_59->setText(QCoreApplication::translate("GrabberParametersUI", "Ty", nullptr));
        label_60->setText(QCoreApplication::translate("GrabberParametersUI", "Tz", nullptr));
        twParameters->setTabText(twParameters->indexOf(tModel), QCoreApplication::translate("GrabberParametersUI", "Model", nullptr));
        label_5->setText(QCoreApplication::translate("GrabberParametersUI", "<b>Depth</b>", nullptr));
        label_19->setText(QCoreApplication::translate("GrabberParametersUI", "Max", nullptr));
        label_4->setText(QCoreApplication::translate("GrabberParametersUI", "Value", nullptr));
        label_18->setText(QCoreApplication::translate("GrabberParametersUI", "Min", nullptr));
        label_17->setText(QCoreApplication::translate("GrabberParametersUI", "<b>Color</b>", nullptr));
        label_40->setText(QCoreApplication::translate("GrabberParametersUI", "Euclidian distance", nullptr));
        label_39->setText(QCoreApplication::translate("GrabberParametersUI", "RGB", nullptr));
        label_6->setText(QCoreApplication::translate("GrabberParametersUI", "Factors YUV", nullptr));
        cbFilterDepthWithColor->setText(QCoreApplication::translate("GrabberParametersUI", "Filter depth with color", nullptr));
        label_62->setText(QCoreApplication::translate("GrabberParametersUI", "JPEG compression rate", nullptr));
        label_55->setText(QCoreApplication::translate("GrabberParametersUI", "Min", nullptr));
        label_20->setText(QCoreApplication::translate("GrabberParametersUI", "Range", nullptr));
        cbInfraInvert->setText(QCoreApplication::translate("GrabberParametersUI", "Invert (only if binary)", nullptr));
        cbInfraBinary->setText(QCoreApplication::translate("GrabberParametersUI", "Binary (0 - 1)", nullptr));
        label_38->setText(QCoreApplication::translate("GrabberParametersUI", "Value ", nullptr));
        label_36->setText(QCoreApplication::translate("GrabberParametersUI", "Max", nullptr));
        label_37->setText(QCoreApplication::translate("GrabberParametersUI", "<b>Infrared</b>", nullptr));
        label_53->setText(QCoreApplication::translate("GrabberParametersUI", "Max", nullptr));
        label_25->setText(QCoreApplication::translate("GrabberParametersUI", "Height", nullptr));
        label_52->setText(QCoreApplication::translate("GrabberParametersUI", "Min", nullptr));
        label_24->setText(QCoreApplication::translate("GrabberParametersUI", "Width", nullptr));
        label_3->setText(QCoreApplication::translate("GrabberParametersUI", "Kernel size", nullptr));
        label_27->setText(QCoreApplication::translate("GrabberParametersUI", "Type", nullptr));
        label_7->setText(QCoreApplication::translate("GrabberParametersUI", "Max local diff", nullptr));
        cbEnableSmoothing->setText(QCoreApplication::translate("GrabberParametersUI", "enable smoothing", nullptr));
        label_28->setText(QCoreApplication::translate("GrabberParametersUI", "Min neighbours", nullptr));
        label_54->setText(QCoreApplication::translate("GrabberParametersUI", "Loops", nullptr));
        cbErosion->setText(QCoreApplication::translate("GrabberParametersUI", "enable erosion", nullptr));
        cbTemporal->setText(QCoreApplication::translate("GrabberParametersUI", "Temporal", nullptr));
        label_11->setText(QCoreApplication::translate("GrabberParametersUI", "inused2", nullptr));
        label_12->setText(QCoreApplication::translate("GrabberParametersUI", "inused3", nullptr));
        cbErosionType->setItemText(0, QCoreApplication::translate("GrabberParametersUI", "Rectangle", nullptr));
        cbErosionType->setItemText(1, QCoreApplication::translate("GrabberParametersUI", "Cross", nullptr));
        cbErosionType->setItemText(2, QCoreApplication::translate("GrabberParametersUI", "Ellipse", nullptr));

        label_30->setText(QCoreApplication::translate("GrabberParametersUI", "Method", nullptr));
        label_26->setText(QCoreApplication::translate("GrabberParametersUI", "Min value", nullptr));
        label_31->setText(QCoreApplication::translate("GrabberParametersUI", "Kernel size", nullptr));
        label_9->setText(QCoreApplication::translate("GrabberParametersUI", "Erase after min depth (if > 0), offset:", nullptr));
        label_10->setText(QCoreApplication::translate("GrabberParametersUI", "Distance from mean max (if > 0):", nullptr));
        cbSmoothingMethod->setItemText(0, QCoreApplication::translate("GrabberParametersUI", "Homogeneous blur", nullptr));
        cbSmoothingMethod->setItemText(1, QCoreApplication::translate("GrabberParametersUI", "Gaussian blur", nullptr));
        cbSmoothingMethod->setItemText(2, QCoreApplication::translate("GrabberParametersUI", "Median blur", nullptr));
        cbSmoothingMethod->setItemText(3, QCoreApplication::translate("GrabberParametersUI", "Bilateral filter", nullptr));

        twParameters->setTabText(twParameters->indexOf(tFilters), QCoreApplication::translate("GrabberParametersUI", "Filters", nullptr));
        label_33->setText(QCoreApplication::translate("GrabberParametersUI", "Size cloud pts", nullptr));
        cbDisplayCloud->setText(QCoreApplication::translate("GrabberParametersUI", "Display cloud", nullptr));
        label_56->setText(QCoreApplication::translate("GrabberParametersUI", "Size cloud:", nullptr));
        laSizeCloud->setText(QCoreApplication::translate("GrabberParametersUI", "0", nullptr));
        label->setText(QCoreApplication::translate("GrabberParametersUI", "<b>Cloud</b>", nullptr));
        cbForceCloudColor->setText(QCoreApplication::translate("GrabberParametersUI", "Force cloud color", nullptr));
        label_50->setText(QCoreApplication::translate("GrabberParametersUI", "Cloud color", nullptr));
        twParameters->setTabText(twParameters->indexOf(tDisplay), QCoreApplication::translate("GrabberParametersUI", "Display", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GrabberParametersUI: public Ui_GrabberParametersUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRABBER_PARAMETERS_H
