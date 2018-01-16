
#ifndef KERNELIMAGEPROCESSING_TWOCHANNELS_H
#define KERNELIMAGEPROCESSING_TWOCHANNELS_H


#include "Image.h"

class TwoChannels: public Image {
public:
    TwoChannels();
    ~TwoChannels();


    void loadImage(string filename)override;
    void saveImage(string filename)override;
    void effect(float** e);


private:
    char** pixels;

};


#endif //KERNELIMAGEPROCESSING_CHANNELS_2_H
