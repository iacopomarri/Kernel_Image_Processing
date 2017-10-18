//
// Created by Lorenzo De Luca on 16/10/17.
//

#ifndef KERNELIMAGEPROCESSING_CHANNELS_4_H
#define KERNELIMAGEPROCESSING_CHANNELS_4_H


class Channels_4 {
public:
    Channels_4();
    Channels_4(char r, char g, char b, char a);

    char getR() const;
    void setR(char r);

    char getG() const;
    void setG(char g);

    char getB() const;
    void setB(char b);

    char getA() const;
    void setA(char a);

private:
    char r;
    char g;
    char b;
    char a;

};


#endif //KERNELIMAGEPROCESSING_CHANNELS_4_H
