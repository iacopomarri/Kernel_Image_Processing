//
// Created by Lorenzo De Luca on 18/10/17.
//

#include "Color.h"

Color::Color():r(0), g(0), b(0) {}
Color::Color(char red,  char green, char blu): r(red), g(green),b(blu) {};

char Color::getR() const {return r;}
void Color::setR(char r) {this->r=r;}

char Color::getG() const {return g;}
void Color::setG(char g) {this->g=g;}

char Color::getB() const {return b;}
void Color::setB(char b) {this->b=b;}