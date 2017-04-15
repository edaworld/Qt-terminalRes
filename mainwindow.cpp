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

#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QMessageBox>
#include <QLabel>
#include <QtSerialPort/QSerialPort>

#define TIMELENGTH 300
double times[TIMELENGTH];//坐标x轴数组
double valofRe[TIMELENGTH];//节点1坐标y轴数组
double valofIM[TIMELENGTH];//节点2坐标y轴数组


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
//初始化控件
    this->initLcdNumbers();
    this->initThermoBPs();
    this->initThermoHPs();

    serial = new QSerialPort(this);
    settings = new SettingsDialog;

//以下为设置按钮状态
    ui->actionConnect->setEnabled(true);
    ui->btnConnect->setEnabled(true);
    ui->actionDisconnect->setEnabled(false);
    ui->btnDisconnect->setEnabled(false);
    ui->actionQuit->setEnabled(true);
    ui->actionConfigure->setEnabled(true);

    status = new QLabel;
    ui->statusBar->addWidget(status);
//    ui->menuBar->clear();//标题栏
    ui->mainToolBar->clear();//工具栏

    timer = new QTimer();
//    time = new QTime();
    timer->setInterval(3000);
    timer->start();

    initActionsConnections();//设置menu菜单的各个按钮的响应槽函数

    connect(serial, static_cast<void (QSerialPort::*)(QSerialPort::SerialPortError)>(&QSerialPort::error),
            this, &MainWindow::handleError);
    connect(serial, &QSerialPort::readyRead, this, &MainWindow::readData);//有数据到来时候，响应槽函数

    connect(timer,SIGNAL(timeout()),this,SLOT(timeoutdisplay()));//timoutdisplay函数为定时器检测函数，每隔3秒钟进入，查看是否接收数据个数有变化，如果无变化，说明停止，则tableview显示
    connect(this,&MainWindow::isReceiveData,this,&MainWindow::processrevdata);//串口接收到数据后发射信号，触发processrevdata槽函数

    for (int i = 0; i < TIMELENGTH;i++)//设置curve图的横坐标
    {
        times[i] = i;
    }


    //设置标题
    p_interval = new QwtInterval(0,TIMELENGTH);
    ui->qwtPlot_mainwin->setAxisTitle( QwtPlot::xBottom, "Time" );
    ui->qwtPlot_mainwin->setAxisTitle(QwtPlot::yLeft,"Value");
    ui->qwtPlot_mainwin->setAxisScale( QwtPlot::xBottom, p_interval->minValue(), p_interval->maxValue() );
    ui->qwtPlot_mainwin->setAxisScale( QwtPlot::yLeft, 0, 10000);

    //设置画布
    p_canvas = new QwtPlotCanvas();
    p_canvas->setFrameStyle( QFrame::Box | QFrame::Raised );
    p_canvas->setLineWidth( 1 );
//    p_canvas->setPalette( Qt::blue );//设置画布颜色
//    p_canvas->setBorderRadius(2);//设置图像为圆角
    ui->qwtPlot_mainwin->setCanvas(p_canvas);


    //设置网格
    p_grid = new QwtPlotGrid();
    p_grid->setPen( Qt::gray, 1.0, Qt::DotLine );
    p_grid->enableX( true );
    p_grid->enableXMin( true );
    p_grid->enableY( true );
    p_grid->enableYMin( false );
    p_grid->attach(ui->qwtPlot_mainwin);
    p_grid->setMajorPen( Qt::black, 0, Qt::DotLine );

    //设置曲线
    p_curve = new QwtPlotCurve( "电阻抗" );
    p_curve->setPen(Qt::blue,1);//设置曲线颜色 粗细
    p_curve->setRenderHint(QwtPlotItem::RenderAntialiased,true);//线条光滑化
    p_curve->setLegendAttribute(QwtPlotCurve::LegendShowLine);
    p_curve->attach( ui->qwtPlot_mainwin );


    QwtLegend *legend = new QwtLegend;
    legend->setDefaultItemMode( QwtLegendData::Checkable );//图例可被点击

    ui->qwtPlot_mainwin->insertLegend(legend, QwtPlot::TopLegend);//曲线对应图标的位置

//    connect( legend, SIGNAL( checked( const QVariant &, bool, int ) ),SLOT( showItem( const QVariant &, bool ) ) );//点击图例操作

    QwtPlotItemList items = ui->qwtPlot_mainwin->itemList( QwtPlotItem::Rtti_PlotCurve );//获取画了多少条曲线,如果为获取其他形状，注意改变参数
    for ( int i = 0; i < items.size(); i++ )
    {
        if ( i == 0 )
        {
            const QVariant itemInfo = ui->qwtPlot_mainwin->itemToInfo( items[i] );
            QwtLegendLabel *legendLabel = qobject_cast<QwtLegendLabel *>( legend->legendWidget( itemInfo ) );
            if ( legendLabel )
                legendLabel->setChecked( true );//
            items[i]->setVisible( true );
        }
        else
        {
            items[i]->setVisible( false );
        }
    }
    ui->qwtPlot_mainwin->replot();
    ui->qwtPlot_mainwin->setAutoReplot( true );//设置自动重画，相当于更新

}

void MainWindow::btnConfigProcess()
{
    this->settings->show();
}

MainWindow::~MainWindow()
{
    delete settings;
    delete ui;
}
//打开串口响应槽函数
void MainWindow::openSerialPort()
{
    SettingsDialog::Settings p = settings->settings();
    serial->setPortName(p.name);
    serial->setBaudRate(p.baudRate);
    serial->setDataBits(p.dataBits);
    serial->setParity(p.parity);
    serial->setStopBits(p.stopBits);
    serial->setFlowControl(p.flowControl);
    if (serial->open(QIODevice::ReadWrite)) {

        ui->actionConnect->setEnabled(false);
        ui->btnConnect->setEnabled(false);
        ui->actionDisconnect->setEnabled(true);
        ui->btnDisconnect->setEnabled(true);
        ui->actionConfigure->setEnabled(false);
        ui->btnSet->setEnabled(false);
        showStatusMessage(tr("连接到%1:波特率:%2,数据位:%3,检验方式:%4,停止位:%5,流控制:%6")
                          .arg(p.name).arg(p.stringBaudRate).arg(p.stringDataBits)
                          .arg(p.stringParity).arg(p.stringStopBits).arg(p.stringFlowControl));
    } else {
        QMessageBox::critical(this, tr("Error"), serial->errorString());

        showStatusMessage(tr("打开错误"));
    }
    connect(mainwin,&MainWindow::notifyhiswin,historywin,&HisMainWin::insAndupdatetblview);//建立串口notify信号和HisMainWin串口的tableview数据库槽函数连接
//    connect(mainwin,&MainWindow::notifycurwin,curvewgt,&CurvWidget::insAndupdatecurve);//建立串口notify信号和curvewgt的曲线图的连接
    connect(mainwin,&MainWindow::notifywinUpdatecurv,mainwin,&MainWindow::updatecurve);//建立串口notify信号和mainwin上面的曲线图的连接
}
//关闭串口响应槽函数
void MainWindow::closeSerialPort()
{
    if (serial->isOpen())
        serial->close();
    ui->actionConnect->setEnabled(true);
    ui->btnConnect->setEnabled(true);
    ui->actionDisconnect->setEnabled(false);
    ui->btnDisconnect->setEnabled(false);
    ui->actionConfigure->setEnabled(true);
    ui->btnSet->setEnabled(true);
    showStatusMessage(tr("断开"));
}
//帮助按钮响应槽函数
void MainWindow::about()
{
    QMessageBox::about(this, tr("程序功能"),tr("<b>本程序从心率带主机接收数据，然后进行显示</b>"));
}
//将数据写入串口
void MainWindow::writeData(const QByteArray &data)
{
    serial->write(data);
}
//读取串口数据，这里仅仅实现数据的拷贝，为了节省时间，显示任务放到processrevdata槽函数中
static quint64 yaxis[10];
static quint8 countofYaxis;
static quint64 sum;
void MainWindow::readData()
{
    quint32 rcvtemp;//暂存实部数据
    quint32 imtemp;//暂存虚部数据
    QByteArray dataReadAll = serial->readAll();
    quint32 sumofRe;
    quint32 sumofIm;

//    qDebug("read data size is %d,count is %d",dataReadAll.size(),dataReadAll.count());
    char temp0[1],temp1[1],temp2[1],temp3[1],temp4[1],temp5[1],temp6[1],temp7[1];
     if(dataReadAll.at(0) == '$')
     {
         temp.clear();
     }
     temp.append(dataReadAll.data(),dataReadAll.size());
     if(temp.size() == 14)
     {

//         qDebug("temp2 is %c",(quint8)temp.at(2));
//         qDebug("temp3 is %c",(quint8)temp.at(3));
//         qDebug("temp4 is %c",(quint8)temp.at(4));
//         qDebug("temp5 is %c",(quint8)temp.at(5));
//         qDebug("temp4 is %c",(quint8)temp.at(7));
//         qDebug("temp4 is %c",(quint8)temp.at(8));
//         qDebug("temp4 is %c",(quint8)temp.at(9));
//         qDebug("temp4 is %c",(quint8)temp.at(10));

         sumofRe=0;
         temp0[0]=(quint8)temp.at(2);
         rcvtemp = strtol(temp0,NULL,16);
         sumofRe+= rcvtemp*4096;

         temp1[0]=(quint8)temp.at(3);
         rcvtemp = strtol(temp1,NULL,16);
         sumofRe+= rcvtemp*256;



         temp2[0]=(quint8)temp.at(4);
         rcvtemp = strtol(temp2,NULL,16);
         sumofRe+= rcvtemp*16;

         temp3[0]=(quint8)temp.at(5);
         rcvtemp = strtol(temp3,NULL,16);
         sumofRe+= rcvtemp;
         ReofRecv = sumofRe;
//         qDebug("%d",ReofRecv);
         qDebug("Re is %X",ReofRecv);


         yaxis[countofYaxis]=ReofRecv;
         countofYaxis++;
         if(countofYaxis == 5)
         {
             for(int i=0;i<5;i++)
                 sum +=yaxis[i];
             sum = sum/5;
             ui->qwtPlot_mainwin->setAxisScale( QwtPlot::yLeft, 0, sum*2);
             countofYaxis = 0;
             sum = 0;
         }

         sumofIm=0;
         temp4[0]=(quint8)temp.at(7);
         rcvtemp = strtol(temp4,NULL,16);
         sumofIm+= rcvtemp*4096;

         temp5[0]=(quint8)temp.at(8);
         rcvtemp = strtol(temp5,NULL,16);
         sumofIm+= rcvtemp*256;

         temp6[0]=(quint8)temp.at(9);
         rcvtemp = strtol(temp6,NULL,16);
         sumofIm+= rcvtemp*16;

         temp7[0]=(quint8)temp.at(10);
         rcvtemp = strtol(temp7,NULL,16);
         sumofIm+= rcvtemp;
         ImofRecv = sumofIm;
//         qDebug("Im is %d",ImofRecv);
         qDebug("Im is %X",ImofRecv);

     }
     emit isReceiveData();//发送信号，通知processrevdata槽函数处理数据
}
static qint64 count1;//统计第1通道接收数据个数变量
static qint64 count2;//统计第2通道接收数据个数变量
static qint64 count3;//统计第3通道接收数据个数变量
void MainWindow::processrevdata()//响应isReceiveData信号的处理数据槽函数
{

    ui->lcdNumber1->display((double)this->ReofRecv/1000);
    count1++;

    ImofRecv = ImofRecv * (-1);
    ui->lcdNumber2->display((double)ImofRecv/1000);
    count2++;

//    ui->lcdNumber3->display(dataReadBuffer[2].Heartdata);
    count3++;

    emit notifyhiswin();//通知tableview更新数据
//    emit notifycurwin();//通知curve更新数据
    emit notifywinUpdatecurv();//通知mainwin更新曲线数据
}
static qint32 count;//串口接收到数据的计数器
void MainWindow::updatecurve()
{
    volatile int i;
    if(count == TIMELENGTH)
    {
        count = TIMELENGTH-1;
        for (i = 0; i < TIMELENGTH;i++)
        {
            valofRe[i] = valofRe[i+1];//将曲线1的心率数据数组前移一位
//            val2[i] = val2[i+1];//将曲线2的心率数据数组前移一位
        }
    }
    valofRe[count] = mainwin->ReofRecv;//设置心率1的数据
//    val2[count] = mainwin->dataReadBuffer[1].Heartdata;//设置心率2的数据
    count++;

    p_curve->setSamples(times,valofRe,count);
//    p_curve->setSamples(time,val2,count);

    ui->qwtPlot_mainwin->replot();//重绘数据
}

void MainWindow::timeoutdisplay()//超时检测槽函数
{
    static qint64 no1oldnum,no1newnum;
    static qint64 no2oldnum,no2newnum;
    static qint64 no3oldnum,no3newnum;

    //计算是否掉线
    no1oldnum = no1newnum;
    no1newnum = count1;
    if(no1oldnum == no1newnum)  //
    {
        ui->lcdNumber1->display(tr("------"));
    }
    //计算是否掉线
    no2oldnum = no2newnum;
    no2newnum = count2;
    if(no2oldnum == no2newnum)
    {
        ui->lcdNumber2->display(tr("------"));
    }
    //计算是否掉线
    no3oldnum = no3newnum;
    no3newnum = count3;
    if(no3oldnum == no3newnum)
    {
//        ui->lcdNumber3->display(tr("------"));
//        ui->ThermoBP3->setValue(0);
//        ui->ThermoHP3->setValue(0);
    }
}

void MainWindow::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError) {
        QMessageBox::critical(this, tr("Critical Error"), serial->errorString());
        closeSerialPort();
    }
}
//设置按键的信号和槽
void MainWindow::initActionsConnections()
{
    connect(ui->actionConnect, &QAction::triggered, this, &MainWindow::openSerialPort);
    connect(ui->actionDisconnect, &QAction::triggered, this, &MainWindow::closeSerialPort);
    connect(ui->actionQuit, &QAction::triggered, this, &MainWindow::close);
    connect(ui->actionConfigure, &QAction::triggered, settings, &MainWindow::show);
    connect(ui->actionAbout, &QAction::triggered, this, &MainWindow::about);
    connect(ui->actionAboutQt, &QAction::triggered, qApp, &QApplication::aboutQt);
}
//初始化LCD控件的属性
void MainWindow::initLcdNumbers()
{
    QPalette pal( Qt::black );
    pal.setColor( QPalette::WindowText, Qt::green );


    ui->lcdNumber1->setSegmentStyle( QLCDNumber::Filled );
    ui->lcdNumber1->setAutoFillBackground( true );
//    ui->lcdNumber1->setFixedHeight( ui->lcdNumber1->sizeHint().height() * 2 );
//    ui->lcdNumber1->setFocusPolicy( Qt::WheelFocus );
    ui->lcdNumber1->setPalette( pal );
    ui->lcdNumber1->display(tr("------"));

    ui->lcdNumber2->setSegmentStyle( QLCDNumber::Filled );
    ui->lcdNumber2->setAutoFillBackground( true );
//    ui->lcdNumber2->setFixedHeight( ui->lcdNumber2->sizeHint().height() * 2 );
//    ui->lcdNumber2->setFocusPolicy( Qt::WheelFocus );
    ui->lcdNumber2->setPalette( pal );
    ui->lcdNumber2->display(tr("------"));

}
//设置电池电量控件方向
void MainWindow::initThermoBPs()
{

}
//设置心率带电量控件方向
void MainWindow::initThermoHPs()
{

}
void MainWindow::showStatusMessage(const QString &message)
{
    status->setText(message);
}

void MainWindow::on_btnHistory_clicked()
{
    this->hide();
    historywin->show();
}

void MainWindow::on_btnCurve_clicked()
{
//    this->hide();
//    curvewgt->show();
}

void MainWindow::on_btnExit_clicked()
{
    if(this->serial->isOpen() == true)
    {
        this->closeSerialPort();
    }
    datathread->stopped = true;


    QTest::qSleep(1000);

    QProgressDialog dialog(tr("正在更新数据库"), tr("取消"), 0, 20000, this);
    dialog.setWindowTitle(tr("进度条"));
    dialog.setWindowModality(Qt::WindowModal);
    dialog.show();

    for(int i=0;i<20000;i++)
    {
        //以下为进度条显示
        dialog.setValue(i);
    }
    dialog.setValue(20000);//设置进度条为满值
    this->close();
}

void MainWindow::on_btnConnect_clicked()
{
    this->openSerialPort();
}

void MainWindow::on_btnDisconnect_clicked()
{
    this->closeSerialPort();
}

void MainWindow::on_btnSet_clicked()
{
    this->btnConfigProcess();
}

//void MainWindow::on_btnHelp_clicked()
//{

//}
