#include "hismainwin.h"
#include "ui_hismainwin.h"
#include "mainwindow.h"
//#include "curvwidget.h"
#include "datathread.h"
#include "QMessageBox"
#include "QProgressDialog"
HisMainWin::HisMainWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HisMainWin)
{
    ui->setupUi(this);

    this->setWindowTitle("历史数据查询窗口");

    model = new QSqlTableModel(this);
    model->setTable("table_information");
    model->select();

    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    model->setHeaderData(0,Qt::Horizontal,tr("电阻抗"));
    model->setHeaderData(1,Qt::Horizontal,tr("相位"));
//    model->setHeaderData(2,Qt::Horizontal,tr(" "));
//    model->setHeaderData(3,Qt::Horizontal,tr(" "));
//    model->setHeaderData(4,Qt::Horizontal,tr(" "));
//    model->setHeaderData(5,Qt::Horizontal,tr(" "));
//    model->setHeaderData(6,Qt::Horizontal,tr(" "));
//    model->setHeaderData(7,Qt::Horizontal,tr(" "));
//    model->setHeaderData(8,Qt::Horizontal,tr(" "));

    ui->tableView->setModel(model);

    ui->tableView->verticalHeader();
    ui->tableView->horizontalHeader();
    ui->tableView->resizeColumnsToContents();

    ui->tableView->setAlternatingRowColors(true);
    ui->tableView->setStyleSheet( "QTableView{background-color: rgb(250, 250, 115);"
        "alternate-background-color: rgb(141, 163, 215);}" );
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->horizontalHeader()->setHighlightSections(false);
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->setShowGrid(false);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionMode(QAbstractItemView::ExtendedSelection);

    QFont serifFont;
    serifFont.setBold(true);
    ui->tableView->setFont(serifFont);

    status = new QLabel;//设置状态条
    ui->statusbar->addWidget(status);

}

HisMainWin::~HisMainWin()
{
    delete ui;
}
/***********************************************************************
*   函 数 名: on_btnReturn_his_clicked
*   功能说明: 返回主界面函数，返回时，开启保存数据库提交线程
*   注    意：
***********************************************************************/
void HisMainWin::on_btnReturn_his_clicked()//有数据库界面返回至主界面，启动一次数据保存
{
    this->hide();
    mainwin->show();
    datathread->stopped = true;//开启submit提交数据库线程
    datathread->start();
}

/***********************************************************************
*   函 数 名: on_btnPrint_his_clicked
*   功能说明: 以下为保存成excel数据代码，是否加入断开串口连接功能需要进一步考虑
*   注    意：此部分保存成excel语句耗时较大
***********************************************************************/
void HisMainWin::on_btnPrint_his_clicked()//
{
    QString filepath = QFileDialog::getSaveFileName(this, tr("Save File"),".",tr("Microsoft Office Excel (*.xls *.xlsx)"));
    if(!filepath.isEmpty()){
        //界面弹出进度条
        QProgressDialog dialog(tr("Excel数据保存进度"), tr("取消"), 0, model->rowCount(), this);
        dialog.setWindowTitle(tr("进度条"));
        dialog.setWindowModality(Qt::WindowModal);
        dialog.show();
        //开启excel保存功能
        QAxObject *excel = new QAxObject(this);
        excel->setControl("Excel.Application");//连接Excel控件
        excel->dynamicCall("SetVisible (bool Visible)","false");//不显示窗体
        excel->setProperty("DisplayAlerts", false);//不显示任何警告信息。如果为true那么在关闭是会出现类似“文件已修改，是否保存”的提示

        QAxObject *workbooks = excel->querySubObject("WorkBooks");//获取工作簿集合
        workbooks->dynamicCall("Add");//新建一个工作簿
        QAxObject *workbook = excel->querySubObject("ActiveWorkBook");//获取当前工作簿
        QAxObject *worksheets = workbook->querySubObject("Sheets");//获取工作表集合
        QAxObject *worksheet = worksheets->querySubObject("Item(int)",1);//获取工作表集合的工作表1，即sheet1
        QAxObject *cellX,*cellY;

        for(int i=0;i<model->rowCount();i++)
        {
            //以下为进度条显示
            dialog.setValue(i);
            QCoreApplication::processEvents();
            if(dialog.wasCanceled())
                break;
            //以下为实际保存语句
            QString X="A"+QString::number(i+1);//设置要操作的单元格，如A1
            QString Y="B"+QString::number(i+1);
            cellX = worksheet->querySubObject("Range(QVariant, QVariant)",X);//获取单元格
            cellY = worksheet->querySubObject("Range(QVariant, QVariant)",Y);
            cellX->dynamicCall("SetValue(const QVariant&)",QVariant(model->data(model->index(i,0))));//设置单元格的值
            cellY->dynamicCall("SetValue(const QVariant&)",QVariant(model->data(model->index(i,1))));

        }
        dialog.setValue(model->rowCount());//设置进度条为满值

        workbook->dynamicCall("SaveAs(const QString&)",QDir::toNativeSeparators(filepath));//保存至filepath，注意一定要用QDir::toNativeSeparators将路径中的"/"转换为"\"，不然一定保存不了。
        workbook->dynamicCall("Close()");//关闭工作簿
        excel->dynamicCall("Quit()");//关闭excel
        delete excel;
        excel=NULL;
    }

}

/***********************************************************************
*   函 数 名: insAndupdatetblview
*   功能说明: 相应mainwindow窗体中processrevdata函数发出的notifyhiswin信号
*   注    意：
***********************************************************************/
static qint64 countrev;
void HisMainWin::insAndupdatetblview()
{

    QSqlRecord record;

    QDateTime dt;
    QTime time;
    QDate date;
    dt.setTime(time.currentTime());
    dt.setDate(date.currentDate());
    QString currentDate = dt.toString("yyyy:MM:dd:hh:mm:ss"); //采用一定的格式保存时间日期

    QSqlField f1("ch1", QVariant::Int);
//    QSqlField f2("ch2", QVariant::Int);
//    QSqlField f9("datetime", QVariant::DateTime);

    f1.setValue(mainwin->realResValue);
//    f2.setValue(mainwin->ImofRecv);
//    f9.setValue(QVariant(currentDate));

    record.append(f1);
//    record.append(f2);
//    record.append(f9);

    this->model->insertRecord(-1, record);
    ui->tableView->scrollToBottom();//tableview自动滚动到表底部

    countrev++;
//    if(countrev % 30 == 0)//每收到30个数据，30秒，保存一次数据库
//        datathread->stopped = true;//
//    qDebug()<<"in here!";

    showStatusMessage(tr("共计接收到: %1 个数据").arg(countrev));
}

void HisMainWin::showStatusMessage(const QString &message)
{
    status->setText(message);
}

void HisMainWin::on_btnClear_his_clicked()
{
    model->removeRows(0,model->rowCount());
    ui->tableView->reset();
    ui->tableView->setModel(model);
}
/***********************************************************************
*   函 数 名: on_btnSave_clicked
*   功能说明: 以文本csv的形式保存数据
*   注    意：
***********************************************************************/
void HisMainWin::on_btnSave_clicked()
{
    QString savefilepath = QFileDialog::getSaveFileName(this, tr("文件另存为"),"./demo.csv",tr("Txt File (*.csv)"));
    if(savefilepath.isEmpty())
        return;

    QProgressDialog dialog(tr("数据正在保存，请等待！"), tr("取消"), 0, model->rowCount(), this);
    dialog.setWindowTitle(tr("保存进度"));
    dialog.setWindowModality(Qt::WindowModal);
    dialog.show();

    QFile tofile(savefilepath);
    tofile.open(QIODevice::WriteOnly | QIODevice::Truncate);
    QTextStream out(&tofile);

    for(int i=0;i<model->rowCount();i++)
    {
        //以下为进度条显示
        dialog.setValue(i);
        QCoreApplication::processEvents();
        if(dialog.wasCanceled())
            break;
        //以下为实际保存语句
        out <<model->data(model->index(i,0)).toString()<<","<<endl;
    }
    dialog.setValue(model->rowCount());//设置进度条为满值
}
