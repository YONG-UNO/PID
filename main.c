#include <math.h>
#include <stdio.h>
#include <unistd.h>

typedef struct {
    float kp;
    float ki;
    float kd;
    float setpoint;
    float current;
    float error;
    float last_error;
    float integrate;
    float derivative;
} PID;

//初始化PID参数
PID pid;
float time = 0.0f;               //时间变量(用于生成正弦函数)
const float dt = 0.01f;          //控制周期(10ms);
const float amplitude = 100.0f;  //sin振幅
const float frequency = 0.5f;    //正弦波频率(0.5f)

void strcopy(char *str1, char *str2);

int main(void) {
    // //初始化pid参数
    // pid.kp = 30.0f;               //比例系数(快速响应)
    // pid.ki = 0.1f;                //积分系数(消除静差)
    // pid.kd = 0.3f;                //微分系数(抑制超调)
    // pid.integrate = 0.0f;         //积分项初始化为0
    // pid.last_error = 0.0f;
    // pid.current = 0.0f;           //被控制量初始值为0
    //
    // for (;;) {
    //     //生成正弦波函数目标(setpoint = A * sin(2 PI f t))
    //     pid.setpoint = amplitude * sin (2 * M_PI * frequency * time);
    //
    //     //计算当前误差
    //     pid.error = pid.setpoint - pid.current;
    //
    //     //计算pid三项
    //     float p_term = pid.kp * pid.error;            // 比例项 (kp * 误差)
    //
    //     pid.integrate += pid.error * dt;              // 累计误差
    //     if (pid.integrate > 500.0f) pid.integrate = 500.0f;
    //     if (pid.integrate < -500.0f) pid.integrate = -500.0f;
    //     float i_term = pid.ki * pid.integrate;        // 积分项 (ki * 累计误差)
    //
    //     pid.derivative = (pid.error - pid.last_error) / dt;
    //     float d_term = pid.kd * pid.derivative;        // 微分项 (kd * 误差导数)
    //
    //     //计算pid输出,更新当前值
    //     float output = p_term + i_term + d_term;
    //     pid.current += output * dt;                     // output是调幅,随时间线性变化,假设被控量与控制量线性变化
    //                                                     // 输入与输出成正比
    //     //存档当前误差到上一次误差,用于下一次微分项计算
    //     pid.last_error = pid.error;
    //
    //     //时间累加(模拟时间连续)
    //     time += dt;
    //
    //     printf("  时间:%.2f",time);
    //     printf("  目标值:%.2f",pid.setpoint);
    //     printf("  当前值:%.2f",pid.current);
    //     printf("   误差:%.2f\n",pid.error);
    //
    //     usleep(10000);              //单位是微秒,受到系统调度延迟,相当不准确
    //
    // }
    char str1[] = "mamba out";
    char str2[] = "";

    strcopy(str1,str2);

    printf("o: %s\n",str2);

    return 0;
}

void strcopy(char *str1, char *str2) {
    while (*str1 != '\0') {

        *str2 = *str1;
        str1++;
        str2++;
    }
    *str2 = '\0';




}
