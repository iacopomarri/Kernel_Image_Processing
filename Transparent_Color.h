//
// Created by iacopo on 18/10/17.
//

#ifndef KERNELIMAGEPROCESSING_TRANSPARENT_COLOR_H
#define KERNELIMAGEPROCESSING_TRANSPARENT_COLOR_H

#include "Color.h"

class Transparent_Color:public Color {
    public:
        Transparent_Color();

        float getA() const;
        void setA(float a);

    private:
    //trasparenza
        float a;

};


#endif //KERNELIMAGEPROCESSING_TRANSPARENT_COLOR_H
