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

    virtual void loadImage(string filename, Image** ptr);
  virtual  void saveImage(string filename){};

    int getHeight()const;
    int getWidth()const;
    int getMax()const;
    void setHeight(int h);
    void setWidth(int w);
    void setMax(int m);


protected:
    string magic;
    int width;
    int height;
    int max;
    char* bytes;
    Color* pixels;

};

#endif //KERNELIMAGEPROCESSING_IMAGE_H
