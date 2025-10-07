//
// Created by DingYong on 25-8-3.
//

#ifndef CYCLE_TIME_H
#define CYCLE_TIME_H

#include <time.h>

void cycle_init(struct timespec *next_time);
void wait_next_cycle(struct timespec *next_time);

#endif //CYCLE_TIME_H
