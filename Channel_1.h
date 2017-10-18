//
// Created by Lorenzo De Luca on 16/10/17.
//

#ifndef KERNELIMAGEPROCESSING_CHANNEL_1_H
#define KERNELIMAGEPROCESSING_CHANNEL_1_H


#include "Image.h"

class Channel_1: public Image {
public:
    Channel_1();

    void loadImage(string filename)override;
    void saveImage(string filename)override;

private:
    bool** pixels;


};


#endif //KERNELIMAGEPROCESSING_CHANNEL_1_H
