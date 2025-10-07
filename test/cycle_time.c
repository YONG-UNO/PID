//
// Created by DingYong on 25-8-3.
//

#include "cycle_time.h"

#include <stdio.h>
#include <time.h>

// 10ms周期(纳秒)
#define CYCLE_10MS 10000000

/**
 * 初始化周期控制初始化
 * @param next_time 用于存储下一次执行时间的结构体指针
 */
void cycle_init(struct timespec *next_time) {
    clock_gettime(CLOCK_MONOTONIC, next_time);
}

/**
 * 等待并进入下一个周期(10ms)
 * @param next_time 用于存储下一次执行时间的结构体指针
 */
void wait_next_cycle(struct timespec *next_time) {
    struct timespec current;

    // 计算下一个周期的目标时间
    next_time->tv_nsec += CYCLE_10MS;
    if (next_time->tv_nsec >= 1000000000) {
        next_time->tv_sec++;
        next_time->tv_nsec -= 1000000000;
    }

    // 等待到目标时间
    clock_gettime(CLOCK_MONOTONIC, &current);
    if (current.tv_sec < next_time->tv_sec ||
        (current.tv_sec == next_time->tv_sec && current.tv_nsec < next_time->tv_nsec)) {

        struct timespec sleep = {
            next_time->tv_sec - current.tv_sec,
            next_time->tv_nsec - current.tv_nsec
        };
        nanosleep(&sleep, NULL);
        } else {
            // 执行超时提示
            printf("周期超时!\n");
        }
}