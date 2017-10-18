//
// Created by iacopo on 18/10/17.
//

#include "Transparent_Color.h"
 Transparent_Color::Transparent_Color():Color(), a(0) {}

float Transparent_Color::getA() const {return a;}
void Transparent_Color::setA(float a) {this->a=a;}