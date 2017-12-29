//
// Created by iacopo on 21/12/17.
//

#ifndef KERNELIMAGEPROCESSING_EFFECT_H
#define KERNELIMAGEPROCESSING_EFFECT_H


class Effect {
public:
    Effect();
    float** getBlur();
    float** getSharpen();
    float** getTopsobel();
    float** getEdgedetection();
    float** getIdentity();

private:
    float** blur;
    float** sharpen;
    float**topsobel;
    float** edgedetection;
    float** identity;

};


#endif //KERNELIMAGEPROCESSING_EFFECT_H
