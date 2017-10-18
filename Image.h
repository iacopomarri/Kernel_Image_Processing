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
    Image(const Image& copy);


    Image operator=(const Image&);

    void loadImage(string filename);
    void saveImage(string filename);
    void effect(int effectCode);




    int getHeight()const;
    int getWidth()const;
    int getMax()const;
    void setHeight(int h);
    void setWidth(int w);
    void setMax(int m);


private:
    string magic;
    int width;
    int height;
    int max;
    char* bytes;
    Color* pixels;
    int  sharpen[9]={0,-1,0,-1,5,-1,0,-1,0};


};

#endif //KERNELIMAGEPROCESSING_IMAGE_H
