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


// struct SIN *sinWaveA;
// sinInit(&sinWaveA,10.0f,0.1f,0.1f);
//
// struct PID pid;
// pidInit(&pid,0.7f,0.0f,0.0f);
//
// float current = 0;
//
// for (int i = 1;i < 100; i++) {
//     float target = sinGenerate(&sinWaveA,i  * M_PI_4);
//     float output = pidCalc(&pid,target,current,0.01);
//     current += output;
//
//     float error = target - current;
//     printf("target:%.1f ,current:%.1f ,error: %.1f\n",target,current,error);
// }