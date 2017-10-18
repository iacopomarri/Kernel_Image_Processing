//
// Created by Lorenzo De Luca on 16/10/17.
//

#include "Channel_1.h"
#include <fstream>
#include <iostream>
#include <bitset>

Channel_1::Channel_1():Image(){}

void Channel_1::loadImage(string filename) {
    ifstream picture;
    picture.open(filename);                            //open the stream to the file
    if (picture.fail()) {                              //check if che file it's been opened
        cout << "Errore di caricamento" << endl;
    }

    picture >> Channel_1::magic >> Channel_1::height >> Channel_1::width >> Channel_1::max;

    cout<<magic<<endl;
    cout<<width<<endl;
    cout<<height<<endl;
    cout<<max<<endl;

    pixels = new bool*[width]; //  allocate memory for the pixels matrix
    for(int i=0; i<width;i++)
        pixels[i]=new bool[height];
    int size = width*height;

    bytes = new char[size/8];

    //LEGGE IL FILE E LO METTE IN bytes
    picture.read(bytes, size);

    // METTE IN PIXELS I VALORI IMMAGAZZINATI IN bytes
    bool bits[width*height];
    //Per ogni byte estraiamo 8 bit
    for(int k=0; k< sizeof(bytes); k++) {
        for (int h = 0; h < 8; h++) {
            bits[k * 8 + h] = (bytes[k] >> h) & 1;
        }
    }

    for (int i=0; i<height; i++){
        for(int j=0; j<width; j++) {
            pixels[i][j] = bits[(i*width)+j];
        }
    }
    picture.close();             //close the stream

}

void Channel_1::saveImage(string filename) {
    ofstream imageFile;
    imageFile.open(filename);

    // write the ppm header
    imageFile << magic << endl << width << endl << height
              << endl << to_string(max);// << endl;


    //  SCRIVE IL CONTENUTO DI BYTES NEL FILE
    imageFile.write(bytes,width*height);
    imageFile.close();          //close the stream

}