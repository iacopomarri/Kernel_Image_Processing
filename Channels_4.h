//
// Created by Lorenzo De Luca on 16/10/17.
//

#ifndef KERNELIMAGEPROCESSING_CHANNELS_4_H
#define KERNELIMAGEPROCESSING_CHANNELS_4_H

#include "Transparent_Color.h"
#include <string>
#include "Image.h"

class Channels_4: public Image {
public:
    Channels_4();
    void loadImage(string filename) override ;
    void saveImage(string filename) override ;

private:
    Transparent_Color** pixels;
};



#endif //KERNELIMAGEPROCESSING_CHANNELS_4_H
