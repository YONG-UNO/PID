//
// Created by DingYong on 25-8-4.
//

#ifndef WHATEVER_H
#define WHATEVER_H

struct Student {
    char name[20];
    int number;
    char sex;
    int grade;
};

void printInit(struct Student *student,char name[20],int number,char sex,int grade);
void printBegin(struct Student *student);

#endif //WHATEVER_H
