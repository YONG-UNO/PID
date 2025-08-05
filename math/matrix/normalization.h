//
// Created by DingYong on 25-8-4.
//

#ifndef NORMALIZATION_H
#define NORMALIZATION_H
#include "crossProduct.h"

typedef struct {
    float x;         //归一化后的x分量
    float y;         //归一化后的x分量
    float z;         //归一化后的x分量
    float norm;      //模长
} normal_t;

normal_t normalization (vector3d_t *vect);

#endif //NORMALIZATION_H
