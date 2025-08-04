//
// Created by DingYong on 25-8-4.
//

#ifndef MATRIX_H
#define MATRIX_H

typedef struct {
    float x;
    float y;
    float z;
} vector3d;

vector3d crossProduct (vector3d *vect1,vector3d *vect2);

#endif //MATRIX_H


// vector3d vect1 = {1.0f,1.0f,1.0f};
// vector3d vect2 = {1.0f,1.0f,-1.0f};
//
// vector3d crossResult = crossProduct(&vect1,&vect2);
//
// printf("X:%.1f\t",crossResult.x);
// printf("Y:%.1f\t",crossResult.y);
// printf("Z:%.1f\t",crossResult.z);