//
// Created by DingYong on 25-8-3.
//

#ifndef PIDCONTROLLER_H
#define PIDCONTROLLER_H

struct PID {
    float kp;            //比例系数(快速响应)
    float ki;            //积分系数(消除静差)
    float kd;            //微分系数(抑制超调)
    float setpoint;
    float current;
    float error;
    float last_error;
    float integrate;
    float derivative;
};


void pidInit(struct PID *pid,float kp,float ki,float kd);
float pidCalc(struct PID*pid,float setpoint,float current,float dt);
float setOutLimit(float value,float max,float min);
#endif //PIDCONTROLLER_H

