//
// Created by Lorenzo De Luca on 16/10/17.
//

#include <curses.h>
#include "Channel_1.h"

Channel_1::Channel_1():w(TRUE) {}
Channel_1::Channel_1(bool white): w(white) {};

char Channel_1::getW() const {return w;}
void Channel_1::setW(bool r) {this->w=w;}