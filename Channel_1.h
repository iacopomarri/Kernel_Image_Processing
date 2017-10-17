//
// Created by Lorenzo De Luca on 16/10/17.
//

#ifndef KERNELIMAGEPROCESSING_CHANNEL_1_H
#define KERNELIMAGEPROCESSING_CHANNEL_1_H


class Channel_1 {
public:
    Channel_1();
    Channel_1(bool w);

    char getW() const;
    void setW(bool w);

private:
    bool w;

};


#endif //KERNELIMAGEPROCESSING_CHANNEL_1_H
