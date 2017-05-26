#ifndef HISMAINWIN_H
#define HISMAINWIN_H

#include <QMainWindow>

#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtSql>
#include "QLabel"



#ifdef __cplusplus
  #ifndef EXTERN_C
    #define EXTERN_C extern "C"
  #endif
#else
  #ifndef EXTERN_C
    #define EXTERN_C extern
  #endif
#endif

namespace Ui {
class HisMainWin;
}

class HisMainWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit HisMainWin(QWidget *parent = 0);
    ~HisMainWin();
    QSqlTableModel *model;

private slots:
    void on_btnReturn_his_clicked();

//    void on_btnCurve_his_clicked();

    void on_btnPrint_his_clicked();

//    void on_btnExit_his_clicked();

    void on_btnClear_his_clicked();

    void on_btnSave_clicked();

public slots:
    void insAndupdatetblview();

private:
    Ui::HisMainWin *ui;

    void showStatusMessage(const QString &message);
    QLabel *status;


};
EXTERN_C HisMainWin *historywin;
#endif // HISMAINWIN_H
