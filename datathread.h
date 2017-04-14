#ifndef DATATHREAD_H
#define DATATHREAD_H
#include <QThread>

#include <QAxObject>
#include <QFileDialog>
#include "qfiledialog.h"

#ifdef __cplusplus
  #ifndef EXTERN_C
    #define EXTERN_C extern "C"
  #endif
#else
  #ifndef EXTERN_C
    #define EXTERN_C extern
  #endif
#endif


class DataThread : public QThread
{
public:
    DataThread();
    void run();
    void stop();
    bool stopped;
};

class PrintThread : public QThread
{
public:
    PrintThread();
    void run();
    void stop();
    bool exited;
};

EXTERN_C PrintThread    *printthread;
EXTERN_C DataThread     *datathread;

#endif // DATATHREAD_H
