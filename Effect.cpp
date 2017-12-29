#include "Effect.h"

Effect::Effect() {
    blur = new float*[3];
    sharpen = new float*[3];
    topsobel = new float*[3];
    edgedetection= new float*[3];
    identity = new float*[3];

    for(int i=0; i<3; i++) {
        blur[i] = new float[3];
        sharpen[i] = new float[3];
        topsobel[i] = new float[3];
        edgedetection[i]=new float[3];
        identity[i]=new float[3];
    }

    blur[0][0]=0.0625;
    blur[0][1]=0.125;
    blur[0][2]=0.0625;
    blur[1][0]=0.125;
    blur[1][1]=0.25;
    blur[1][2]=0.125;
    blur[2][0]=0.0625;
    blur[2][1]=0.125;
    blur[2][2]=0.0625;


    sharpen[0][0]=0;
    sharpen[0][1]=-1;
    sharpen[0][2]=0;
    sharpen[1][0]=-1;
    sharpen[1][1]=5;
    sharpen[1][2]=-1;
    sharpen[2][0]=0;
    sharpen[2][1]=-1;
    sharpen[2][2]=0;


    topsobel[0][0]=1;
    topsobel[0][1]=2;
    topsobel[0][2]=1;
    topsobel[1][0]=0;
    topsobel[1][1]=0;
    topsobel[1][2]=0;
    topsobel[2][0]=-1;
    topsobel[2][1]=2;
    topsobel[2][2]=-1;

    edgedetection[0][0]=-1;
    edgedetection[0][1]=-1;
    edgedetection[0][2]=-1;
    edgedetection[1][0]=-1;
    edgedetection[1][1]=8;
    edgedetection[1][2]=-1;
    edgedetection[2][0]=-1;
    edgedetection[2][1]=-1;
    edgedetection[2][2]=-1;

    identity[0][0]=0;
    identity[0][1]=0;
    identity[0][2]=0;
    identity[1][0]=0;
    identity[1][1]=1;
    identity[1][2]=0;
    identity[2][0]=0;
    identity[2][1]=0;
    identity[2][2]=0;
}

float** Effect::getBlur() { return blur;}
float** Effect::getSharpen() {return sharpen;}
float** Effect::getTopsobel() {return topsobel;}
float** Effect::getEdgedetection() {return edgedetection;}
float** Effect::getIdentity() {return identity;}
