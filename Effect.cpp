#include "Effect.h"

Effect::Effect() {
    blur = new float*[3];
    for(int i=0; i<3; i++)
        blur[i]=new float[3];

    blur[0][0]=0.0625;
    blur[0][1]=0.125;
    blur[0][2]=0.0625;
    blur[1][0]=0.125;
    blur[1][1]=0.25;
    blur[1][2]=0.125;
    blur[2][0]=0.0625;
    blur[2][1]=0.125;
    blur[2][2]=0.0625;
}

float** Effect::getBlur() { return blur;}
