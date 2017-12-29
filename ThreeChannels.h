//
// Created by Lorenzo De Luca on 16/10/17.
//
#ifndef KERNELIMAGEPROCESSING_CHANNELS_3_H
#define KERNELIMAGEPROCESSING_CHANNELS_3_H

#include <string>
#include "Color.h"
#include "Image.h"

class Channels_3: public Image {
    public:
        Channels_3();

        void loadImage(string filename)override ;
        void saveImage(string filename)override ;
    void effect(float** e);


    private:
        Color** pixels;
    };



#endif //KERNELIMAGEPROCESSING_CHANNELS_3_H
