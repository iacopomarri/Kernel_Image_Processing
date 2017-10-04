//
// Created by iacopo on 12/10/16.
//

#ifndef KERNELIMAGEPROCESSING_IMAGE_H
#define KERNELIMAGEPROCESSING_IMAGE_H

#include <string>
#include "Color.h"

using namespace std;

class Image{
public:
    Image();
    virtual ~Image();

    void loadImage(std::string filename);
    void saveImage();



private:
    string datatype;
    int width;
    int height;
    int max;
    Color* pixels;

};

#endif //KERNELIMAGEPROCESSING_IMAGE_H
