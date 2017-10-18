//
// Created by Lorenzo De Luca on 16/10/17.
//

#include "Channels_3.h"

Channels_3::Channels_3():r(0), g(0), b(0) {}
Channels_3::Channels_3(char red,  char green, char blu): r(red), g(green),b(blu) {};

char Channels_3::getR() const {return r;}
void Channels_3::setR(char r) {this->r=r;}

char Channels_3::getG() const {return g;}
void Channels_3::setG(char g) {this->g=g;}

char Channels_3::getB() const {return b;}
void Channels_3::setB(char b) {this->b=b;}