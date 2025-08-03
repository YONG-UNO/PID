//
// Created by DingYong on 25-8-4.
//

#include "sinGenerate.h"
#include <math.h>

void sinInit(struct SIN *sinWaveA,float A,float W,float phi) {
    sinWaveA->A = A;
    sinWaveA->W = W;
    sinWaveA->phi = phi;
}

float sinGenerate(struct SIN *sinWaveA,float X) {
    return sinWaveA->A * sin( sinWaveA->W * X + sinWaveA->phi );
}

 //struct SIN *sinWaveA
 //sinInit(&sinWaveA,A,W,phi);
 //sinGenerate(&sinWaveA,W,phi);
