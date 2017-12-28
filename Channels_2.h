//
// Created by Lorenzo De Luca on 16/10/17.
//

#ifndef KERNELIMAGEPROCESSING_CHANNELS_2_H
#define KERNELIMAGEPROCESSING_CHANNELS_2_H


#include "Image.h"

class Channels_2: public Image {
public:
    Channels_2();

    void loadImage(string filename)override;
    void saveImage(string filename)override;
    void effect(float** e);


private:
    char** pixels;

};


#endif //KERNELIMAGEPROCESSING_CHANNELS_2_H
