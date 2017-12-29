//
// Created by Lorenzo De Luca on 16/10/17.
//

#ifndef KERNELIMAGEPROCESSING_FOURCHANNELS_H
#define KERNELIMAGEPROCESSING_FOURCHANNELS_H

#include "Transparent_Color.h"
#include <string>
#include "Image.h"

class FourChannels: public Image {
public:
    FourChannels();
    void loadImage(string filename) override ;
    void saveImage(string filename) override ;
    void effect(float** e);


private:
    Transparent_Color** pixels;
};



#endif //KERNELIMAGEPROCESSING_CHANNELS_4_H
