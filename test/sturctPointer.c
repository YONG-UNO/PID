//
// Created by DingYong on 25-8-4.
//

#include "sturctPointer.h"

#include <stdio.h>
#include <string.h>


void printInit(struct Student *student,char name[20],int number,char sex,int grade) {
    strcpy(student->name, name);    //数组名是常量指针,不能直接赋值,需要复制
    student->number = number;
    student->sex = sex;
    student->grade = grade;
}

void printBegin(struct Student *student) {
    printf("%s",student->name);
}
