//
// Created by DingYong on 25-8-3.
//

#include "pidController.h"


void pidInit(struct PID *pid,float kp,float ki,float kd) {
    pid->kp = kp;
    pid->ki = ki;
    pid->kd = kd;

    pid->setpoint = 0.0f;        //目标值
    pid->current = 0.0f;         //当前值
    pid->error = 0.0f;           //用于p_term
    pid->last_error = 0.0f;      //用于derivative
    pid->integrate = 0.0f;       //用于i_term
    pid->derivative = 0.0f;      //用于d_term
}

float pidCalc(struct PID *pid,float setpoint,float current,float dt) {
    pid->setpoint = setpoint;
    pid->current = current;

    pid->error = setpoint - current;

    float p_term = pid->kp * pid->error;


    pid->integrate += pid->error * dt;
    pid->integrate = setOutLimit(pid->integrate,1000.0f,-1000.0f);
    float i_term = pid->ki * pid->integrate;

    pid->derivative = (pid->error - pid->last_error)/dt;
    pid->last_error = pid->error;
    float d_term = pid->kd * pid->derivative;

    return p_term + i_term + d_term;
}


float setOutLimit(float value,float max,float min) {
    if (value > max)           return max;
    else if (value < min)      return min;
    else                       return value;
}
