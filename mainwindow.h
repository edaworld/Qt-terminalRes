/****************************************************************************
**
** Copyright (C) 2012 Denis Shienkov <denis.shienkov@gmail.com>
** Copyright (C) 2012 Laszlo Papp <lpapp@kde.org>
** Contact: http://www.qt.io/licensing/
**
** This file is part of the QtSerialPort module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL21$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 or version 3 as published by the Free
** Software Foundation and appearing in the file LICENSE.LGPLv21 and
** LICENSE.LGPLv3 included in the packaging of this file. Please review the
** following information to ensure the GNU Lesser General Public License
** requirements will be met: https://www.gnu.org/licenses/lgpl.html and
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** As a special exception, The Qt Company gives you certain additional
** rights. These rights are described in The Qt Company LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore/QtGlobal>

#include <QMainWindow>

#include <QtSerialPort/QSerialPort>
#include <QTimer>
#include <QTest>
#include "QProgressDialog"
//#include <QTime>

#include "mastermsg.h"
#include "settingsdialog.h"
#include "mastermsg.h"
//#include "curvwidget.h"
#include "hismainwin.h"
#include "datathread.h"


#include <qwt_plot.h>
#include <qwt_plot_layout.h>
#include <qwt_plot_canvas.h>
#include <qwt_plot_renderer.h>
#include <qwt_plot_grid.h>
#include <qwt_plot_histogram.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_zoomer.h>
#include <qwt_plot_panner.h>
#include <qwt_plot_magnifier.h>
#include <qwt_legend.h>
#include <qwt_legend_label.h>
#include <qwt_column_symbol.h>
#include <qwt_series_data.h>
#include <qpen.h>
#include <qwt_symbol.h>
#include <qwt_picker_machine.h>




#ifdef __cplusplus
  #ifndef EXTERN_C
    #define EXTERN_C extern "C"
  #endif
#else
  #ifndef EXTERN_C
    #define EXTERN_C extern
  #endif
#endif

QT_BEGIN_NAMESPACE

class QLabel;

namespace Ui {
class MainWindow;
}

QT_END_NAMESPACE


class SettingsDialog;//设置串口对话框

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    DATAPACKGE dataReadBuffer[8];//存储数据缓冲区
    quint8 ReofRes[4];//电阻抗实部
    quint8 ImofRes[4];//电阻抗虚部


    QByteArray temp;//暂存串口接收到的数据，凑足12个字节
    quint32 ReofRecv;//接收数据的实部
    quint32 ImofRecv;//接收数据的虚部

    double gainFactor;//增益系数
    double realtimeRange;//实施计算的幅度
    quint8 displayCurveFlag;//是否显示曲线的标志位

    double realResValue;//真实计算出的阻值

    STATUSFLAG statusFlag;
    Ui::MainWindow *ui;

private slots:
    void openSerialPort();
    void closeSerialPort();
    void about();
    void writeData(const QByteArray &data);
    void readData();
    void timeoutdisplay();
    void processrevdata();
    void updatecurve();
    void calibrateProcess();//校准槽函数



    void btnConfigProcess();

    void handleError(QSerialPort::SerialPortError error);

    void on_btnHistory_clicked();

//    void on_btnCurve_clicked();

    void on_btnExit_clicked();

    void on_btnConnect_clicked();

    void on_btnDisconnect_clicked();

    void on_btnSet_clicked();

//    void on_btnHelp_clicked();

    void on_btnCalibra_clicked();//校准按钮槽函数

signals:
    void isReceiveData(void);
    void notifyhiswin(void);//测试信号，通知hismainwin的槽函数
    void notifycurwin(void);//信号，通知curvewgt的槽函数
    void notifywinUpdatecurv(void);
    void startCalibrate(void);//开始校准，获得增益系数信号，与calibrateProcess连接

private:
    void initActionsConnections();
    void initLcdNumbers();
    void initThermoBPs();
    void initThermoHPs();

private:
    void showStatusMessage(const QString &message);


    QLabel *status;

    SettingsDialog *settings;//串口设置窗口

    QSerialPort *serial;

    DATAPACKGE *dataReadPackge;
    RESPACKGE *resReadPackge;

    QwtPlotCurve *p_curve;
    QwtInterval *p_interval;
    QwtPlotGrid *p_grid;
    QwtPlotCanvas *p_canvas;



    QTimer *timer;//测试是否断线，超时的定时器
//    QTime *time;
};

EXTERN_C MainWindow *mainwin;

#endif // MAINWINDOW_H
