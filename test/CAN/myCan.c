//
// Created by DingYong on 25-8-7.
//

#include "myCan.h"

#include "can.h"
#include "main.h"

void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan) {
    CAN_RxHeaderTypeDef rx_header;  //定义一个can消息头结构体变量,存储收到的can消息头部信息
                                    //包含消息id(StdId),帧类型(IDE,标准帧或拓展帧),消息类型(RTR,数据帧还是远程帧),数据长度(DLC,0-8字节)

    uint8_t rx_data[8];             //存储收到的CAN数据场(CAN最大支持8Byte数据)

    HAL_CAN_GetRxMessage(hcan,CAN_RX_FIFO0,&rx_header,rx_data);   //hcan指针由回调函数触发后直接传入,rx_data[]是个语法糖,本质希望你传入指针

    switch (rx_header.StdId) {
        case CAN_3508_M1_ID:        //当收到的CAN消息ID(rx_header.StdId)
        case CAN_3508_M2_ID:        //与switch中的任意一个ID匹配时,就会执行{}中的代码
        case CAN_3508_M3_ID:
        case CAN_3508_M4_ID:
        case CAN_6020_M5_ID: {

            uint8_t n = rx_header.StdId - 0x201;  //3508: 0x200+n   6020:0x204+n
            get_motor_measure(&motor_gimbal[n], rx_data);

            break;

        } default: {                 //如果一个都不匹配就直接退出

            break;
        }
    }
}

void get_motor_measure(motor_measure_t *motor_measure,uint8_t rx_data[]) {
    motor_measure->last_ecd      =  motor_measure->ecd;
    motor_measure->ecd           =  ((uint16_t)rx_data[0] << 8  | (uint16_t)rx_data[1]);
    motor_measure->speed_rpm     =  ((int16_t) rx_data[2] << 8  | (int16_t)rx_data[3]);
    motor_measure->given_current =  ((int16_t) rx_data[4] << 8  | (int16_t)rx_data[5]);
    motor_measure->temperate     =  rx_data[6];
}


void CAN_Filter_Init(void)
{
    CAN_FilterTypeDef can1_filter_st,can2_filter_st;

    can1_filter_st.FilterIdHigh = 0x0000;
    can1_filter_st.FilterIdLow = 0x0000;
    can1_filter_st.FilterMaskIdHigh = 0x0000;
    can1_filter_st.FilterMaskIdLow = 0x0000;
    can1_filter_st.FilterFIFOAssignment = CAN_RX_FIFO0;
    can1_filter_st.FilterActivation = ENABLE;
    can1_filter_st.FilterMode = CAN_FILTERMODE_IDMASK;
    can1_filter_st.FilterScale = CAN_FILTERSCALE_32BIT;
    can1_filter_st.FilterBank = 0;
    can1_filter_st.SlaveStartFilterBank = 14;

    can2_filter_st.FilterIdHigh = 0x0000;
    can2_filter_st.FilterIdLow = 0x0000;
    can2_filter_st.FilterMaskIdHigh = 0x0000;
    can2_filter_st.FilterMaskIdLow = 0x0000;
    can2_filter_st.FilterFIFOAssignment = CAN_RX_FIFO1;
    can2_filter_st.FilterActivation = ENABLE;
    can2_filter_st.FilterMode = CAN_FILTERMODE_IDMASK;
    can2_filter_st.FilterScale = CAN_FILTERSCALE_32BIT;
    can2_filter_st.FilterBank = 14;
    can2_filter_st.SlaveStartFilterBank = 14;
    //使能CAN通道
    if (HAL_CAN_ConfigFilter(&hcan1, &can1_filter_st) != HAL_OK)// 配置 CAN1 过滤器
    {
        Error_Handler();  // 处理错误
    }
    if (HAL_CAN_Start(&hcan1) != HAL_OK)// 启动 CAN1
    {
        Error_Handler();
    }
    if (HAL_CAN_ActivateNotification(&hcan1, CAN_IT_RX_FIFO0_MSG_PENDING) != HAL_OK)// 使能 CAN1 接收 FIFO0 消息中断
    {
        Error_Handler();
    }
    HAL_Delay(10);
    if (HAL_CAN_ConfigFilter(&hcan2, &can2_filter_st) != HAL_OK)    // 配置 CAN2 过滤器
    {
        Error_Handler();
    }
    if (HAL_CAN_Start(&hcan2) != HAL_OK)// 启动 CAN2
    {
        Error_Handler();
    }
    if (HAL_CAN_ActivateNotification(&hcan2, CAN_IT_RX_FIFO1_MSG_PENDING) != HAL_OK)// 使能 CAN2 接收 FIFO1 消息中断
    {
        Error_Handler();
    }}