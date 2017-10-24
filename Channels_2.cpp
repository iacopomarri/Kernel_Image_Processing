//
// Created by Lorenzo De Luca on 16/10/17.
//

#include "Channels_2.h"
#include <fstream>
#include <iostream>
#include <bitset>

Channels_2::Channels_2():Image(){}

void Channels_2::loadImage(string filename) {
    ifstream picture;
    picture.open(filename);                            //open the stream to the file
    if (picture.fail()) {                              //check if che file it's been opened
        cout << "Errore di caricamento" << endl;
    }

    picture >> Channels_2::magic >> Channels_2::height >> Channels_2::width >> Channels_2::max;

    cout<<magic<<endl;
    cout<<width<<endl;
    cout<<height<<endl;
    cout<<max<<endl;

    pixels = new char*[width]; //  allocate memory for the pixels matrix
    for(int i=0; i<width;i++)
        pixels[i]=new char[height];
    int size = width*height;

    bytes = new char[size];


    //LEGGE IL FILE E LO METTE IN bytes
    picture.read(bytes, size);



    // METTE IN PIXELS I VALORI IMMAGAZZINATI IN bytes
    for (int i=0; i<height; i++){
        for(int j=0; j<width; j++) {
            pixels[i][j] = bytes[(i*width)+j];
        }
    }
    picture.close();             //close the stream

}

void Channels_2::saveImage(string filename) {
    ofstream imageFile;
    imageFile.open(filename);

    // write the ppm header
    imageFile << magic << endl << width << endl << height
              << endl << to_string(max);// << endl;


    //  SCRIVE IL CONTENUTO DI BYTES NEL FILE
    imageFile.write(bytes,width*height);
    imageFile.close();          //close the stream

}
