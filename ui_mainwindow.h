/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qwt_plot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout;
    QAction *actionAboutQt;
    QAction *actionConnect;
    QAction *actionDisconnect;
    QAction *actionConfigure;
    QAction *actionClear;
    QAction *actionQuit;
    QWidget *centralWidget2;
    QwtPlot *qwtPlot_mainwin;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *btnConnect;
    QPushButton *btnHistory;
    QPushButton *btnCalibra;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btnDisconnect;
    QPushButton *btnSet;
    QPushButton *btnExit;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_no1;
    QLCDNumber *lcdNumber1;
    QLabel *label_no2;
    QLCDNumber *lcdNumber2;
    QLabel *label_no1_2;
    QLineEdit *liEdt_Calbra;
    QMenuBar *menuBar;
    QMenu *menuCalls;
    QMenu *menuTools;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(829, 464);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QStringLiteral("Consolas"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        MainWindow->setFont(font);
        MainWindow->setAcceptDrops(false);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/heartbeat.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/help.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon1);
        actionAboutQt = new QAction(MainWindow);
        actionAboutQt->setObjectName(QStringLiteral("actionAboutQt"));
        actionAboutQt->setIcon(icon1);
        actionConnect = new QAction(MainWindow);
        actionConnect->setObjectName(QStringLiteral("actionConnect"));
        actionConnect->setEnabled(true);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/connected.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionConnect->setIcon(icon2);
        QFont font1;
        font1.setFamily(QStringLiteral("Microsoft YaHei UI"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        actionConnect->setFont(font1);
        actionDisconnect = new QAction(MainWindow);
        actionDisconnect->setObjectName(QStringLiteral("actionDisconnect"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/disconnected.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionDisconnect->setIcon(icon3);
        actionConfigure = new QAction(MainWindow);
        actionConfigure->setObjectName(QStringLiteral("actionConfigure"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/gear.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionConfigure->setIcon(icon4);
        actionClear = new QAction(MainWindow);
        actionClear->setObjectName(QStringLiteral("actionClear"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/broom.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionClear->setIcon(icon5);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/images/exit.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuit->setIcon(icon6);
        centralWidget2 = new QWidget(MainWindow);
        centralWidget2->setObjectName(QStringLiteral("centralWidget2"));
        qwtPlot_mainwin = new QwtPlot(centralWidget2);
        qwtPlot_mainwin->setObjectName(QStringLiteral("qwtPlot_mainwin"));
        qwtPlot_mainwin->setGeometry(QRect(10, 10, 691, 371));
        layoutWidget = new QWidget(centralWidget2);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(710, 240, 46, 134));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        btnConnect = new QPushButton(layoutWidget);
        btnConnect->setObjectName(QStringLiteral("btnConnect"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btnConnect->sizePolicy().hasHeightForWidth());
        btnConnect->setSizePolicy(sizePolicy1);
        btnConnect->setIcon(icon2);
        btnConnect->setIconSize(QSize(32, 32));

        verticalLayout->addWidget(btnConnect);

        btnHistory = new QPushButton(layoutWidget);
        btnHistory->setObjectName(QStringLiteral("btnHistory"));
        sizePolicy1.setHeightForWidth(btnHistory->sizePolicy().hasHeightForWidth());
        btnHistory->setSizePolicy(sizePolicy1);
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/images/history.ico"), QSize(), QIcon::Normal, QIcon::Off);
        btnHistory->setIcon(icon7);
        btnHistory->setIconSize(QSize(32, 32));

        verticalLayout->addWidget(btnHistory);

        btnCalibra = new QPushButton(layoutWidget);
        btnCalibra->setObjectName(QStringLiteral("btnCalibra"));
        sizePolicy1.setHeightForWidth(btnCalibra->sizePolicy().hasHeightForWidth());
        btnCalibra->setSizePolicy(sizePolicy1);
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/images/calibration.ico"), QSize(), QIcon::Normal, QIcon::Off);
        btnCalibra->setIcon(icon8);
        btnCalibra->setIconSize(QSize(32, 32));

        verticalLayout->addWidget(btnCalibra);

        layoutWidget1 = new QWidget(centralWidget2);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(760, 240, 46, 134));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        btnDisconnect = new QPushButton(layoutWidget1);
        btnDisconnect->setObjectName(QStringLiteral("btnDisconnect"));
        sizePolicy1.setHeightForWidth(btnDisconnect->sizePolicy().hasHeightForWidth());
        btnDisconnect->setSizePolicy(sizePolicy1);
        btnDisconnect->setIcon(icon3);
        btnDisconnect->setIconSize(QSize(32, 32));

        verticalLayout_2->addWidget(btnDisconnect);

        btnSet = new QPushButton(layoutWidget1);
        btnSet->setObjectName(QStringLiteral("btnSet"));
        sizePolicy1.setHeightForWidth(btnSet->sizePolicy().hasHeightForWidth());
        btnSet->setSizePolicy(sizePolicy1);
        btnSet->setIcon(icon4);
        btnSet->setIconSize(QSize(32, 32));

        verticalLayout_2->addWidget(btnSet);

        btnExit = new QPushButton(layoutWidget1);
        btnExit->setObjectName(QStringLiteral("btnExit"));
        sizePolicy1.setHeightForWidth(btnExit->sizePolicy().hasHeightForWidth());
        btnExit->setSizePolicy(sizePolicy1);
        btnExit->setIcon(icon6);
        btnExit->setIconSize(QSize(32, 32));

        verticalLayout_2->addWidget(btnExit);

        layoutWidget2 = new QWidget(centralWidget2);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(710, 10, 101, 191));
        verticalLayout_3 = new QVBoxLayout(layoutWidget2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_no1 = new QLabel(layoutWidget2);
        label_no1->setObjectName(QStringLiteral("label_no1"));
        sizePolicy.setHeightForWidth(label_no1->sizePolicy().hasHeightForWidth());
        label_no1->setSizePolicy(sizePolicy);
        label_no1->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_no1);

        lcdNumber1 = new QLCDNumber(layoutWidget2);
        lcdNumber1->setObjectName(QStringLiteral("lcdNumber1"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lcdNumber1->sizePolicy().hasHeightForWidth());
        lcdNumber1->setSizePolicy(sizePolicy2);
        lcdNumber1->setSmallDecimalPoint(false);

        verticalLayout_3->addWidget(lcdNumber1);

        label_no2 = new QLabel(layoutWidget2);
        label_no2->setObjectName(QStringLiteral("label_no2"));
        sizePolicy.setHeightForWidth(label_no2->sizePolicy().hasHeightForWidth());
        label_no2->setSizePolicy(sizePolicy);
        label_no2->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_no2);

        lcdNumber2 = new QLCDNumber(layoutWidget2);
        lcdNumber2->setObjectName(QStringLiteral("lcdNumber2"));
        sizePolicy2.setHeightForWidth(lcdNumber2->sizePolicy().hasHeightForWidth());
        lcdNumber2->setSizePolicy(sizePolicy2);

        verticalLayout_3->addWidget(lcdNumber2);

        label_no1_2 = new QLabel(layoutWidget2);
        label_no1_2->setObjectName(QStringLiteral("label_no1_2"));
        sizePolicy.setHeightForWidth(label_no1_2->sizePolicy().hasHeightForWidth());
        label_no1_2->setSizePolicy(sizePolicy);
        label_no1_2->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_no1_2);

        liEdt_Calbra = new QLineEdit(layoutWidget2);
        liEdt_Calbra->setObjectName(QStringLiteral("liEdt_Calbra"));

        verticalLayout_3->addWidget(liEdt_Calbra);

        MainWindow->setCentralWidget(centralWidget2);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 829, 23));
        menuCalls = new QMenu(menuBar);
        menuCalls->setObjectName(QStringLiteral("menuCalls"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QFont font2;
        font2.setFamily(QStringLiteral("Microsoft YaHei UI"));
        font2.setPointSize(9);
        font2.setBold(false);
        font2.setWeight(50);
        mainToolBar->setFont(font2);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuCalls->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuCalls->addAction(actionConnect);
        menuCalls->addAction(actionDisconnect);
        menuCalls->addSeparator();
        menuCalls->addAction(actionQuit);
        menuTools->addAction(actionConfigure);
        menuTools->addAction(actionClear);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionAboutQt);
        mainToolBar->addAction(actionConnect);
        mainToolBar->addAction(actionDisconnect);
        mainToolBar->addAction(actionConfigure);
        mainToolBar->addAction(actionClear);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\347\224\265\351\230\273\346\212\227\346\265\213\351\207\217\347\263\273\347\273\237", 0));
        actionAbout->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216", 0));
#ifndef QT_NO_TOOLTIP
        actionAbout->setToolTip(QApplication::translate("MainWindow", "\345\205\263\344\272\216\346\234\254\347\250\213\345\272\217", 0));
#endif // QT_NO_TOOLTIP
        actionAboutQt->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216Qt", 0));
        actionConnect->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245", 0));
#ifndef QT_NO_TOOLTIP
        actionConnect->setToolTip(QApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", 0));
#endif // QT_NO_TOOLTIP
        actionDisconnect->setText(QApplication::translate("MainWindow", "\346\226\255\345\274\200", 0));
#ifndef QT_NO_TOOLTIP
        actionDisconnect->setToolTip(QApplication::translate("MainWindow", "\345\205\263\351\227\255\344\270\262\345\217\243", 0));
#endif // QT_NO_TOOLTIP
        actionConfigure->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256", 0));
#ifndef QT_NO_TOOLTIP
        actionConfigure->setToolTip(QApplication::translate("MainWindow", "\350\256\276\347\275\256\344\270\262\345\217\243\345\217\202\346\225\260", 0));
#endif // QT_NO_TOOLTIP
        actionClear->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244", 0));
#ifndef QT_NO_TOOLTIP
        actionClear->setToolTip(QApplication::translate("MainWindow", "\346\270\205\351\231\244\346\216\245\346\224\266\345\214\272", 0));
#endif // QT_NO_TOOLTIP
        actionQuit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", 0));
        btnConnect->setText(QString());
        btnHistory->setText(QString());
        btnCalibra->setText(QString());
        btnCalibra->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0));
        btnDisconnect->setText(QString());
        btnSet->setText(QString());
        btnExit->setText(QString());
        label_no1->setText(QApplication::translate("MainWindow", "\347\224\265\351\230\273\346\212\227\357\274\210K\316\251\357\274\211", 0));
        label_no2->setText(QApplication::translate("MainWindow", "\347\233\270\344\275\215", 0));
        label_no1_2->setText(QApplication::translate("MainWindow", "\346\240\241\345\207\206\347\224\265\351\230\273\357\274\210\316\251\357\274\211", 0));
        menuCalls->setTitle(QApplication::translate("MainWindow", "\345\212\250\344\275\234", 0));
        menuTools->setTitle(QApplication::translate("MainWindow", "\350\256\276\347\275\256", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
