//
// Created by Lorenzo De Luca on 16/10/17.
//

#include "Channels_2.h"

Channels_2::Channels_2():gr(0) {}
Channels_2::Channels_2(char gray): gr(gray) {};

char Channels_2::getGR() const {return gr;}
void Channels_2::setGR(char r) {this->gr=gr;}