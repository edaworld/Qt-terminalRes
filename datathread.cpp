#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "datathread.h"
#include "mastermsg.h"
#include "hismainwin.h"

#include "QMessageBox"

DataThread::DataThread()
{

}
void DataThread::run()
{

    if(this->stopped == true)
    {
        if (historywin->model->submitAll()) {   //提交所有被修改的数据，然后修改的数据被保存在数据库中
            historywin->model->database().commit(); //提交
        } else {
            historywin->model->database().rollback(); //回滚
            qDebug()<<"submit is wrong!";
        }
        this->stopped = false;
    }

}
void DataThread::stop()
{

}

PrintThread::PrintThread()
{

}
void PrintThread::run()
{
    if(this->exited == true)
    {
        this->exited = false;
    }

}
void PrintThread::stop()
{

}
