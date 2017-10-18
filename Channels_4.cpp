//
// Created by Lorenzo De Luca on 16/10/17.
//

#include "Channels_4.h"
#include <fstream>
#include <iostream>
#include <bitset>

Channels_4::Channels_4():Image(){}


void Channels_4::loadImage(string filename) {

    ifstream picture;
    picture.open(filename);                            //open the stream to the file
    if (picture.fail()) {                              //check if che file it's been opened
        cout << "Errore di caricamento" << endl;
    }

    picture >> Channels_4::magic >> Channels_4::width >> Channels_4::height >> Channels_4::max;



    cout<<magic<<endl;
    cout<<width<<endl;
    cout<<height<<endl;
    cout<<max<<endl;


    pixels = new Transparent_Color*[width];         //  allocate memory for the pixels matrix
    for(int i=0; i<width;i++)
        pixels[i]=new Transparent_Color[height];

    int size = width*height;

    bytes = new char[size*4];


    //LEGGE IL FILE E LO METTE IN bytes
    picture.read(bytes, size*4);



    // METTE IN PIXELS I VALORI IMMAGAZZINATI IN bytes
    for (int i=0; i<height; i++)
        for(int j=0; j<width;j++) {
            pixels[i][j].setR(bytes[(j * 4)+(i*width*4)]);
            pixels[i][j].setG(bytes[(j * 4)+(i*width*4)]);
            pixels[i][j].setB(bytes[(j * 4)+(i*width*4)]);
            pixels[i][j].setA(bytes[(j * 4)+(i*width*4)]);
        }


    picture.close();             //close the stream
}


void Channels_4::saveImage(string filename) {
    ofstream imageFile;
    imageFile.open(filename);

    // write the ppm header
    imageFile << magic << endl << width<< endl << height
              << endl << to_string(max);// << endl;


    //  SCRIVE IL CONTENUTO DI BYTES NEL FILE
    imageFile.write(bytes,width*height*4);
    imageFile.close(); //close the stream
}
