//
// Created by Lorenzo De Luca on 18/10/17.
//

#ifndef KERNELIMAGEPROCESSING_COLOR_H
#define KERNELIMAGEPROCESSING_COLOR_H


class Color {
public:
    Color();
    Color(char r, char g, char b);

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


#endif //KERNELIMAGEPROCESSING_COLOR_H
