//
// Created by Lorenzo De Luca on 16/10/17.
//

#include "Channels_4.h"

Channels_4::Channels_4():r(0), g(0), b(0), a(0) {}
Channels_4::Channels_4(char red,  char green, char blu, char alpha): r(red), g(green),b(blu), a(alpha) {};

char Channels_4::getR() const {return r;}
void Channels_4::setR(char r) {this->r=r;}

char Channels_4::getG() const {return g;}
void Channels_4::setG(char g) {this->g=g;}

char Channels_4::getB() const {return b;}
void Channels_4::setB(char b) {this->b=b;}

char Channels_4::getA() const {return a;}
void Channels_4::setA(char a) {this->a=a;}