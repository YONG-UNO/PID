//
// Created by DingYong on 25-8-4.
//

#include "normalError.h"

#include "normalization.h"

float normalError(vector3d_t *vect1, vector3d_t *vect2) {
    vector3d_t vect_norm1,vect_norm2;

    //将normliaztion()返回的normal_t(包含模长),转换为vector_t(标准向量结构体)
    vect_norm1.x = normalization(vect1).x;
    vect_norm1.y = normalization(vect1).y;
    vect_norm1.z = normalization(vect1).z;
    vect_norm2.x = normalization(vect2).x;
    vect_norm2.y = normalization(vect2).y;
    vect_norm2.z = normalization(vect2).z;

    vector3d_t crossResult = crossProduct(&vect_norm1,&vect_norm2);

    normal_t normal = normalization(&crossResult);
    return normal.norm;
}


//使用方法
// vector3d_t vect1 = {1.0f,1.0f,1.0f};
// vector3d_t vect2 = {1.0f,1.0f,0.0f};
//
// printf("X:%.1f\t",normalError(&vect1,&vect2));
