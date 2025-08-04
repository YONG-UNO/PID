//
// Created by DingYong on 25-8-4.
//

#ifndef NORMALIZATION_H
#define NORMALIZATION_H
#include "crossProduct.h"

typedef struct {
    float x;
    float y;
    float z;
    float norm;
} normal_t;

normal_t normalization (vector3d_t *vect);

//使用方法:
// vector3d_t vect = {2,2,0};
// normal_t normal = normalization(&vect);
//
// printf("X:%.3f   ",normal.x);
// printf("Y:%.3f   ",normal.y);
// printf("Z:%.3f   ",normal.z);
// printf("norm:%.3f   \n",normal.norm);

#endif //NORMALIZATION_H
