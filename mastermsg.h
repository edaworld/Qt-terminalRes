#ifndef MASTERMSG_H
#define MASTERMSG_H
#include "qglobal.h"

typedef union
{
    uint8_t msg[36];
    struct
    {
        uint8_t head;//包头
        uint8_t devID;//设备id
        uint8_t Heartdata;//心率值
        uint8_t HrtPowerdata;//心率带电量
        uint8_t BatPowerdata;//电池电量
        uint8_t tail;//包尾
    };
}DATAPACKGE;

typedef union
{
    uint8_t msg[12];
    struct
    {
        uint8_t head;//包头
        int32_t Re;//设备id
        int32_t Im;//心率值
        uint8_t Verify1;//心率带电量
        uint8_t Verify2;//电池电量
        uint8_t tail;//包尾
    };
}RESPACKGE;



typedef struct
{
    bool ch1status;
    bool ch2status;
    bool ch3status;
    bool ch4status;
    bool ch5status;
    bool ch6status;
    bool ch7status;
    bool ch8status;
}STATUSFLAG;


#define DATAPACKGE_HEAD    '&'//包头
#define DATAPACKGE_TAIL    '%'//包尾
//#define DATAPACKGE_H       'H'//心率数据
//#define DATAPACKGE_B       'B'//从设备的电量
//#define DATAPACKGE_b       'b'//心率计的电量
//#define DATAPACKGE_M       'M'//从设备状态
//#define DATAPACKGE_S       'S'//心率带的状态

#endif // MASTERMSG_H
