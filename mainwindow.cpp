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
#include <QMessageBox>


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
//    this->initThermoBPs();
//    this->initThermoHPs();

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

//    time = new QTime();
    timer = new QTimer();
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

    this->displayCurveFlag = 0;//默认不显示曲线

    //以下代码设置校准框显示
    ui->liEdt_Calbra->setStyleSheet("color: blue;"
                                    "background-color: yellow;"
                                    "selection-color: yellow;"
                                    "selection-background-color: blue;");
    ui->liEdt_Calbra->setAlignment(Qt::AlignHCenter);
    ui->liEdt_Calbra->setText("------");//设置默认值

    //校准后再开启下面两个按钮
    ui->btnConnect->setEnabled(false);
    ui->btnHistory->setEnabled(false);
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
/***********************************************************************
*   函 数 名: openSerialPort
*   功能说明: open串口响应的槽函数
*   注    意：连接了两个槽函数
*             一个是通知hisMainWin历史数据窗体更新tableview
*             一个是通知MainWindow窗体更新曲线
***********************************************************************/
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
    connect(mainwin,&MainWindow::notifyhiswin,historywin,&HisMainWin::insAndupdatetblview);//建立串口notify信号和HisMainWin窗体串口的tableview数据库槽函数连接
    connect(mainwin,&MainWindow::notifywinUpdatecurv,mainwin,&MainWindow::updatecurve);//建立串口notify信号和mainwin上面的曲线图的连接
}
/***********************************************************************
*   函 数 名: closeSerialPort
*   功能说明: 关闭串口响应槽函数
***********************************************************************/
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
/***********************************************************************
*   函 数 名: about
*   功能说明:帮助按钮响应槽函数
***********************************************************************/
void MainWindow::about()
{
    QMessageBox::about(this, tr("程序功能"),tr("<b>本程序从心率带主机接收数据，然后进行显示</b>"));
}
/***********************************************************************
*   函 数 名: writeData
*   功能说明: 写数据到串口，目前软件中尚未使用
*   注    意：
***********************************************************************/
void MainWindow::writeData(const QByteArray &data)
{
    serial->write(data);
}
/***********************************************************************
*   函 数 名:readData
*   功能说明:串口收到数据后的响应槽函数，对应信号是QSerialPort::readyRead
*   注    意:下位机发送的数据是10个字节，包头为$,2~5组成实部，6~9组成虚部，
*            在此函数中计算出Magnitude=sqrt(实部平方+虚部平方)
*            ReofRecv接收数据的实部
*            ImofRecv接收数据的虚部
*            realtimeRange计算的幅度=Magnitude
***********************************************************************/
//static quint64 yaxis[10];
//static quint8 countofYaxis;
//static quint64 sum;
//读取串口数据，这里仅仅实现数据的拷贝，为了节省时间，显示任务放到processrevdata槽函数中
qint16 sumofRe;//实部加和
qint16 sumofIm;//虚部加和
void MainWindow::readData()
{
    qint32 rcvtemp;//暂存实部数据
    qint32 imtemp;//暂存虚部数据

    QByteArray dataReadAll = serial->readAll();
//    qDebug("read data size is %d,count is %d",dataReadAll.size(),dataReadAll.count());
    char temp0[1],temp1[1],temp2[1],temp3[1],temp4[1],temp5[1],temp6[1],temp7[1];
    if(dataReadAll.at(0) == '$')//判断包头是否正确
    {
        temp.clear();
    }
    else
    {
        return;
    }
    temp.append(dataReadAll.data(),dataReadAll.size());//将数据添加至temp
    if(temp.size() == 10)//只有完整的10个字节的数据包才处理
    {

//        qDebug("temp1 is %c",(quint8)temp.at(1));
//        qDebug("temp2 is %c",(quint8)temp.at(2));
//        qDebug("temp3 is %c",(quint8)temp.at(3));
//        qDebug("temp4 is %c",(quint8)temp.at(4));
//        qDebug("temp5 is %c",(quint8)temp.at(5));
//        qDebug("temp6 is %c",(quint8)temp.at(6));
//        qDebug("temp7 is %c",(quint8)temp.at(7));
//        qDebug("temp8 is %c",(quint8)temp.at(8));

        //以下代码计算实部
        sumofRe=0;
        temp0[0]=(qint8)temp.at(1);
        rcvtemp = strtol(temp0,NULL,16);
        sumofRe |= ((rcvtemp<<12) & 0xF000);
//        sumofRe+= rcvtemp*4096;

        temp1[0]=(qint8)temp.at(2);
        rcvtemp = strtol(temp1,NULL,16);
        sumofRe |= ((rcvtemp<<8) & 0x0F00);
//        sumofRe+= rcvtemp*256;

        temp2[0]=(qint8)temp.at(3);
        rcvtemp = strtol(temp2,NULL,16);
        sumofRe |= ((rcvtemp<<4) & 0x00F0);
//        sumofRe+= rcvtemp*16;

        temp3[0]=(qint8)temp.at(4);
        rcvtemp = strtol(temp3,NULL,16);
        sumofRe |= ((rcvtemp<<0) & 0x000F);
//        sumofRe+= rcvtemp;
        this->ReofRecv = sumofRe;
        qDebug("%d",this->ReofRecv);
        qDebug("Re is %X",this->ReofRecv);

        //以下代码计算虚部
        sumofIm=0;
        temp4[0]=(qint8)temp.at(5);
        imtemp = strtol(temp4,NULL,16);
        sumofIm |= ((imtemp<<12) & 0xF000);
//        qDebug("sumofIm is %X",sumofIm);
//        sumofIm+= imtemp*4096;

        temp5[0]=(qint8)temp.at(6);
        imtemp = strtol(temp5,NULL,16);
        sumofIm |= ((imtemp<<8) & 0x0F00);
//        qDebug("sumofIm is %X",sumofIm);
//        sumofIm+= imtemp*256;

        temp6[0]=(qint8)temp.at(7);
        imtemp = strtol(temp6,NULL,16);
        sumofIm |= ((imtemp<<4) & 0x00F0);
//        qDebug("sumofIm is %X",sumofIm);
//        sumofIm+= imtemp*16;

        temp7[0]=(qint8)temp.at(8);
        imtemp = strtol(temp7,NULL,16);
        sumofIm |= ((imtemp<<0) & 0x000F);
//        qDebug("sumofIm is %X",sumofIm);
//        sumofIm+= imtemp;
        this->ImofRecv = sumofIm;
        qDebug("%d",this->ImofRecv);
        qDebug("Im is %X",this->ImofRecv);

        //以下代码计算模值，也就是magnitude
        this->magnitude = sqrt((double)ReofRecv*(double)ReofRecv+(double)ImofRecv*(double)ImofRecv);
        qDebug("realtimeRange is %f",magnitude);


        //以下代码是设置坐标轴y轴最大值的代码
//        yaxis[countofYaxis] = abs(this->ReofRecv);//实部是有符号数
//        countofYaxis++;
//        if(countofYaxis == 5)
//        {
//            for(int i=0;i<5;i++)
//                sum += yaxis[i];
//            sum = sum/5;
//            ui->qwtPlot_mainwin->setAxisScale( QwtPlot::yLeft, 0, sum*2);//设置y轴的最大值是5次平均值的2倍
//            countofYaxis = 0;
//            sum = 0;
//        }

    }
    if(this->displayCurveFlag == 1)//正常显示模式下，显示数据，此时已经校准完毕
    {
        emit isReceiveData();//发送信号，通知processrevdata槽函数处理数据
    }
    if(this->displayCurveFlag == 0)//校准模式下
    {
        emit startCalibrate();//发送开始校准信号，通知calibrateProcess槽函数处理数据
    }

}
/***********************************************************************
*   函 数 名: processrevdata
*   功能说明: 串口数据接收计算完后，处理实部和虚部的槽函数，对应信号是MainWindow::isReceiveData
*   注    意：本函数使用的gainFactor只是在校准后才有数值
*            通知hismainwin历史数据窗体更新tableview数值
*            通知mainwin更新窗体上面的曲线数据
***********************************************************************/
static qint64 count1;//实时统计第1通道接收数据个数变量
//static qint64 count2;//实时统计第2通道接收数据个数变量
//static qint64 count3;//实时统计第3通道接收数据个数变量

static quint64 yaxis[10];
static quint8 countofYaxis;
static quint64 sum;

void MainWindow::processrevdata()//响应isReceiveData信号的处理数据槽函数
{
    this->realResValue = this->gainFactor/this->magnitude;//计算后的数值


    yaxis[countofYaxis] = abs(this->realResValue);
    countofYaxis++;
    if(countofYaxis == 5)
    {
        for(int i=0;i<5;i++)
            sum += yaxis[i];
        sum = sum/5;
        ui->qwtPlot_mainwin->setAxisScale( QwtPlot::yLeft, 0, sum*2);//设置y轴的最大值是5次平均值的2倍
        countofYaxis = 0;
        sum = 0;
    }

    ui->lcdNumber1->display(this->realResValue/1000);
    count1++;

//    ImofRecv = ImofRecv * (-1);
//    ui->lcdNumber2->display((double)ImofRecv/1000);
//    count2++;

    emit notifyhiswin();//通知hismainwin窗体的tableview更新数据，并更新数据库
    emit notifywinUpdatecurv();//通知mainwin更新曲线数据
}
/***********************************************************************
*   函 数 名: timeoutdisplay
*   功能说明: 检测接收数据是否超时函数，对应信号为timer的SIGNAL(timeout())
*   注    意：和上面的count1要联动使用
***********************************************************************/
static qint64 no1oldnum,no1newnum;//暂存第1通道接收到的数据个数
//static qint64 no2oldnum,no2newnum;//暂存第2通道接收到的数据个数
//static qint64 no3oldnum,no3newnum;//暂存第3通道接收到的数据个数
void MainWindow::timeoutdisplay()//超时检测槽函数
{

    //计算是否掉线
    no1oldnum = no1newnum;
    no1newnum = count1;
    if(no1oldnum == no1newnum)  //如果数据个数没有增加，则超时
    {
        ui->lcdNumber1->display(tr("------"));
    }
//    计算是否掉线
//    no2oldnum = no2newnum;
//    no2newnum = count2;
//    if(no2oldnum == no2newnum)
//    {
//        ui->lcdNumber2->display(tr("------"));
//    }
//    计算是否掉线
//    no3oldnum = no3newnum;
//    no3newnum = count3;
//    if(no3oldnum == no3newnum)
//    {
//        ui->lcdNumber3->display(tr("------"));
//        ui->ThermoBP3->setValue(0);
//        ui->ThermoHP3->setValue(0);
//    }
}
/***********************************************************************
*   函 数 名: updatecurve
*   功能说明: Mainwindow窗体更新显示曲线的槽函数，对应信号为MainWindow::notifywinUpdatecurv
*   注    意：
***********************************************************************/
static qint32 count;//串口接收到数据的计数器
void MainWindow::updatecurve()
{
    volatile int i;
    if(count == TIMELENGTH)
    {
        count = TIMELENGTH-1;
        for (i = 0; i < TIMELENGTH;i++)
        {
            valofRe[i] = valofRe[i+1];//将曲线1的数据数组前移一位
        }
    }
    valofRe[count] = this->realResValue;//设置数据
    count++;

    p_curve->setSamples(times,valofRe,count);

    ui->qwtPlot_mainwin->replot();//重绘数据
}

/***********************************************************************
*   函 数 名: handleError
*   功能说明: 处理错误槽函数
*   注    意：
***********************************************************************/
void MainWindow::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError)
    {
        QMessageBox::critical(this, tr("Critical Error"), serial->errorString());
        closeSerialPort();
    }
}
/***********************************************************************
*   函 数 名: initActionsConnections
*   功能说明: 设置按键的信号和槽
*   注    意：
***********************************************************************/
void MainWindow::initActionsConnections()
{
    connect(ui->actionConnect, &QAction::triggered, this, &MainWindow::openSerialPort);
    connect(ui->actionDisconnect, &QAction::triggered, this, &MainWindow::closeSerialPort);
    connect(ui->actionQuit, &QAction::triggered, this, &MainWindow::close);
    connect(ui->actionConfigure, &QAction::triggered, settings, &MainWindow::show);
    connect(ui->actionAbout, &QAction::triggered, this, &MainWindow::about);
    connect(ui->actionAboutQt, &QAction::triggered, qApp, &QApplication::aboutQt);
}
/***********************************************************************
*   函 数 名: initLcdNumbers
*   功能说明: 初始化LCD控件的属性
*   注    意：
***********************************************************************/
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
/***********************************************************************
*   函 数 名: showStatusMessage
*   功能说明: 窗体下方状态栏显示
*   注    意：
***********************************************************************/
void MainWindow::showStatusMessage(const QString &message)
{
    status->setText(message);
}
/***********************************************************************
*   函 数 名: on_btnHistory_clicked
*   功能说明: 跳转到his历史数据窗体
*   注    意：
***********************************************************************/
void MainWindow::on_btnHistory_clicked()
{
    this->hide();
    historywin->show();
}
/***********************************************************************
*   函 数 名: on_btnExit_clicked
*   功能说明: 退出按钮响应参函数
*   注    意：关闭数据库线程，同时启动了一个进度条界面，界面时间暂定20000个循环
***********************************************************************/
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
/***********************************************************************
*   函 数 名: on_btnConnect_clicked
*   功能说明: 连接按钮槽函数，打开串口
*   注    意：
***********************************************************************/
void MainWindow::on_btnConnect_clicked()
{
    this->openSerialPort();
}
/***********************************************************************
*   函 数 名: on_btnDisconnect_clicked
*   功能说明: 断开按钮槽函数，关闭串口
*   注    意：
***********************************************************************/
void MainWindow::on_btnDisconnect_clicked()
{
    this->closeSerialPort();
}
/***********************************************************************
*   函 数 名: on_btnSet_clicked
*   功能说明: 设置按钮，打开设置串口界面
*   注    意：
***********************************************************************/
void MainWindow::on_btnSet_clicked()
{
    this->btnConfigProcess();
}

//校准按钮单机事件响应函数
void MainWindow::on_btnCalibra_clicked()
{
    if(ui->liEdt_Calbra->text() == "------")//用户没有输入校准电阻
    {
        QMessageBox::critical(this, tr("提醒"),tr("<b>请输入校准电阻值，再单击本按钮</b>"));
        return;
    }
    this->openSerialPort();
    connect(mainwin,&MainWindow::startCalibrate,mainwin,&MainWindow::calibrateProcess);//打开串口后，有数据接收，通知校准槽函数，接收校准数据

}
/***********************************************************************
*   函 数 名: calibrateProcess
*   功能说明:
*   注    意：
***********************************************************************/
static qint64 calibraReArray[100];//存储校准实部数据的数组
static quint8 cntRe=0;//实部数据个数
static qint64 sumofReCalibra;//实部数据总和
static qint64 avgRe;//实部数据均值

static qint64 calibraImArray[100];//存储校准虚部数据的数组
static quint8 cntIm=0;//虚部数据个数
static qint64 sumofImCalibra;//虚部数据总和
static qint64 avgIm;//虚部数据均值

void MainWindow::calibrateProcess()
{
    this->displayCurveFlag = 0;//一旦进入校准程序，曲线默认不显示

    calibraReArray[cntRe]=this->ReofRecv;
    cntRe++;
    if(cntRe == 100)
    {
        for(int i=0;i<100;i++)
            sumofReCalibra +=calibraReArray[i];
        avgRe = sumofReCalibra/100;
        sumofReCalibra = 0;
    }

    calibraImArray[cntIm]=this->ImofRecv;
    cntIm++;
    if(cntIm == 100)
    {
        for(int i=0;i<100;i++)
            sumofImCalibra +=calibraImArray[i];
        avgIm = sumofImCalibra/100;
        sumofImCalibra = 0;
    }

    if((cntRe == 100) && (cntIm == 100))
    {
        cntRe = 0;
        cntIm = 0;

        double retemp,imtemp;
        retemp=(double)avgRe;
        imtemp=(double)avgIm;

        qDebug("avgRe is %d",avgRe);
        qDebug("avgIm is %d",avgIm);


        //计算增益系数，即是gainFactor
        this->gainFactor = sqrt(retemp*retemp + imtemp*imtemp)*ui->liEdt_Calbra->text().toDouble();
        qDebug("gain factor is %f",this->gainFactor);

        //计算完增益系数后，断开startCalibrate信号和本函数的连接，并关闭串口
        disconnect(mainwin,&MainWindow::startCalibrate,mainwin,&MainWindow::calibrateProcess);
        this->closeSerialPort();

        this->displayCurveFlag = 1;//校准完毕，置位显示标志位
        ui->btnConnect->setEnabled(true);
        ui->btnHistory->setEnabled(true);

    }
}



//void MainWindow::on_btnHelp_clicked()
//{

//}

//void MainWindow::on_btnCurve_clicked()
//{
//    this->hide();
//    curvewgt->show();
//}
//设置电池电量控件方向
//void MainWindow::initThermoBPs()
//{

//}
////设置心率带电量控件方向
//void MainWindow::initThermoHPs()
//{

//}
