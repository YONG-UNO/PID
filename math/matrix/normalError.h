//
// Created by DingYong on 25-8-4.
//
//描述:
//归一化误差,将两个向量归一化后求叉乘,
//角度误差在[-1,1]之间,保留角度关系,消除模长影响,用于p-i模型计算

#ifndef NORMALERROR_H
#define NORMALERROR_H
#include "crossProduct.h"

float normalError(vector3d_t *vect1, vector3d_t *vect2);

#endif //NORMALERROR_H
