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

private:
    float** blur;
    float** sharpen;
    float**topsobel;
    float** edgedetection;

};


#endif //KERNELIMAGEPROCESSING_EFFECT_H
