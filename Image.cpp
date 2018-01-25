//
// Created by iacopo on 12/10/16.
//
#include "Image.h"
#include <iostream>
#include <bitset>


Image::Image():magic("null"),path(""),width(0),height(0),max(0){}

Image::~Image() { delete[] bytes; }

int Image::getHeight()const{return height; }
int Image::getWidth()const {return width; }
int Image::getMax()const{return max; }
string Image::getMagic() const { return magic;}

void Image::setHeight(int h){this->height=h;}
void Image::setWidth(int w){this->width=w;}
void Image::setMax(int m){this->max=m;}
void Image::setMagic(string m) {this->magic = m;}


//controlla se la riga letta  è un commento, in tal caso la salta
//il tutto è ripetuto 1 volta per ogni attributo; per fare tutto in un unico ciclo
//è necessario cambiare la struttura della classe usando un vettore al posto dei singoli
//attributi, e di conseguenza vanno cambiate diverse cose nel programma

void Image::headerCommentCheck(ifstream* picture) {
    string byteToCheck = "";
    bool isComment = false;

    while (!isComment) {
        *picture >> byteToCheck;
        if (byteToCheck == "#")
            std::getline(*picture, byteToCheck);
        else
            isComment = true;
        magic = byteToCheck;
    }

    isComment = false;

    while (!isComment) {
        *picture >> byteToCheck;
        if (byteToCheck == "#")
            std::getline(*picture, byteToCheck);
        else
            isComment = true;
        //a va convertito in intero
        width = atoi(byteToCheck.c_str());
    }

    isComment = false;

    while (!isComment) {
        *picture >> byteToCheck;
        if (byteToCheck == "#")
            std::getline(*picture, byteToCheck);
        else
            isComment = true;
        height = atoi(byteToCheck.c_str());
    }

    isComment = false;

    if (magic != "P1" or magic != "P4") {
        while (!isComment) {
            *picture >> byteToCheck;
            if (byteToCheck == "#")
               std::getline(*picture, byteToCheck);
            else
                isComment = true;
            max = atoi(byteToCheck.c_str());
        }
    }
}


string Image::magicCheck(string filename) {
    ifstream picture;
    picture.open(filename);                            //open the stream to the file
    if (picture.fail()) {                              //check if che file it's been opened
        cout << "Errore di caricamento" << endl;
    }


    //controlla se la riga letta  è un commento, in tal caso la salta
    string a="";
    bool flag=false;

    while(!flag) {
        picture >> a;
        if (a == "#")
            std::getline(picture, a);
        else
            flag = true;
    }

    return a;
}


string Image::getPath() {return path;}


/*
Image Image::operator=(const Image& other)
{
        height = other.height;
        width = other.width;
      //  loader = other.loader;
        pixels = other.pixels;

        return *this;
}


Image::Image(const Image& copy)
{
        width = copy.width;
        height = copy.height;
     //   loader = copy.loader;

        pixels = new Color[copy.height];
        for(int i = 0; i < copy.height; i++)
        {
                pixels = new Color[copy.width];
        }

        for(int h = 0; h < copy.height; h++)
        {
                for(int w = 0; w < copy.width; w++)
                {
                        pixels[h*w] = copy.pixels[h*w];
                }
        }

}*/





