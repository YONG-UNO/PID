//
// Created by DingYong on 25-8-4.
//

#include "crossProduct.h"

vector3d crossProduct(vector3d *vect1,vector3d *vect2) {
    vector3d crossResult;  //直接创建结构体变量,自动分配内存

    //利用叉乘公式计算各个分量
    crossResult.x = vect1->y * vect2->z - vect1->z * vect2 ->y;
    crossResult.y = vect1->z * vect2->x - vect1->x * vect2 ->z;
    crossResult.z = vect1->x * vect2->y - vect1->y * vect2 ->x;

    return crossResult;
}

//使用结构体指针,需提前创建结构体变量,分配内存
// // 不返回值，通过指针输出结果（需在调用前分配内存）
// void crossProduct(vector3d *vect1, vector3d *vect2, vector3d *crossResult) {
//     // 直接修改传入的指针所指向的内存
//     crossResult->x = vect1->y * vect2->z - vect1->z * vect2->y;
//     crossResult->y = vect1->z * vect2->x - vect1->x * vect2->z;
//     crossResult->z = vect1->x * vect2->y - vect1->y * vect2->x;
// }
//
// // 调用示例：
// int main() {
//     vector3d v1 = {1, 2, 3};
//     vector3d v2 = {4, 5, 6};
//     vector3d result;  // 提前分配内存
//     crossProduct(&v1, &v2, &result);  // 传入结果指针
//     return 0;
// }
