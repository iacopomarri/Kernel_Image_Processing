//
// Created by Lorenzo De Luca on 16/10/17.
//
#ifndef KERNELIMAGEPROCESSING_THREECHANNELS_H
#define KERNELIMAGEPROCESSING_THREECHANNELS_H

#include <string>
#include "Color.h"
#include "Image.h"

class ThreeChannels: public Image {
    public:
        ThreeChannels();
        ~ThreeChannels();

        void loadImage(string filename)override ;
        void saveImage(string filename)override ;
        void effect(float** e)override ;


    private:
        Color** pixels;
    };



#endif //KERNELIMAGEPROCESSING_CHANNELS_3_H
