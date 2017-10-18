//
// Created by Lorenzo De Luca on 16/10/17.
//

#ifndef KERNELIMAGEPROCESSING_CHANNELS_3_H
#define KERNELIMAGEPROCESSING_CHANNELS_3_H


class Channels_3 {
    public:
        Channels_3();
        Channels_3(char r, char g, char b);

        char getR() const;
        void setR(char r);

        char getG() const;
        void setG(char g);

        char getB() const;
        void setB(char b);

    private:
        char r;
        char g;
        char b;
    };



#endif //KERNELIMAGEPROCESSING_CHANNELS_3_H
