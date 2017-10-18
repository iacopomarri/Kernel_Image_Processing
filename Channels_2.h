//
// Created by Lorenzo De Luca on 16/10/17.
//

#ifndef KERNELIMAGEPROCESSING_CHANNELS_2_H
#define KERNELIMAGEPROCESSING_CHANNELS_2_H


class Channels_2 {
public:
    Channels_2();
    Channels_2(char gr);

    char getGR() const;
    void setGR(char gr);

private:
    char gr;

};


#endif //KERNELIMAGEPROCESSING_CHANNELS_2_H
