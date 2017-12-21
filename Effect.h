//
// Created by iacopo on 21/12/17.
//

#ifndef KERNELIMAGEPROCESSING_EFFECT_H
#define KERNELIMAGEPROCESSING_EFFECT_H


class Effect {
public:
    Effect();
    float** getBlur();

private:
    float** blur;

};


#endif //KERNELIMAGEPROCESSING_EFFECT_H
