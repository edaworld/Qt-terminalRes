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
        if (historywin->model->submitAll()) {   //�ύ���б��޸ĵ����ݣ�Ȼ���޸ĵ����ݱ����������ݿ���
            historywin->model->database().commit(); //�ύ
        } else {
            historywin->model->database().rollback(); //�ع�
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
