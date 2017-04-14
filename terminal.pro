QT += widgets serialport sql core gui axcontainer testlib svg

TARGET = terminal
TEMPLATE = app

#DEFINES += QT_DLL QWT_DLL

#LIBS += -L"C:\Qt\Qt5.6.0\5.6\mingw49_32\lib" -lqwtd
#LIBS += -L"C:\Qt\Qt5.6.0\5.6\mingw49_32\lib" -lqwt

#LIBS += -L"C:\Qt\5.6.0_MinGW_static\lib" -lqwtd
#LIBS += -L"C:\Qt\5.6.0_MinGW_static\lib" -lqwt
LIBS += C:\Qt\5.6.0_MinGW_static\lib\libqwt.a
LIBS += C:\Qt\5.6.0_MinGW_static\lib\libqwtd.a



#INCLUDEPATH += C:\Qt\Qt5.6.0\5.6\mingw49_32\include\qwt
INCLUDEPATH += C:\Qt\5.6.0_MinGW_static\include\QWT

RC_FILE  += resource/RCFile.rc

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    settingsdialog.cpp \
    hismainwin.cpp \
    datathread.cpp


HEADERS += \
    connectdb.h \
    hismainwin.h \
    mainwindow.h \
    mastermsg.h \
    datathread.h \
    pointerapp.h \
    settingsdialog.h

FORMS += \
    mainwindow.ui \
    settingsdialog.ui \
    hismainwin.ui

RESOURCES += \
    terminal.qrc
