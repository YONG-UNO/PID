//
// Created by DingYong on 25-8-4.
//

#include "normalization.h"

#include <tgmath.h>


normal_t normalization(vector3d_t *vect) {
    normal_t normalResult = {0,0,0,0};
    float norm = sqrt(pow(vect->x,2) + pow(vect->y,2) + pow(vect->z,2));

    //处理norm为0的情况,使用极小值判断,避免浮点数精度问题
    if (norm >1e-6) {
        normalResult.x = vect->x / norm;
        normalResult.y = vect->y / norm;
        normalResult.z = vect->z / norm;
        normalResult.norm = norm;
    }

    //模长为0时,返回零向量
    return normalResult;
}
