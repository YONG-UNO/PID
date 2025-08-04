//
// Created by DingYong on 25-8-4.
//

#ifndef SINGENERATE_H
#define SINGENERATE_H

struct SIN {
    float A;         //振幅
    float W;         //角频率
    float phi;       //相位
};

//初始化
void sinInit(struct SIN *sinWaveA,float A,float W,float phi);
//生成
float sinGenerate(struct SIN *sinWaveA,float X);

#endif //SINGENERATE_H


//struct SIN sinWaveA 使用栈上的结构体变量,在栈上分配内存
//sinInit(&sinWaveA,A,W,phi); 再传递地址
//sinGenerate(&sinWaveA,W,phi);