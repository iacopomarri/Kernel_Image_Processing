#include "FourChannels.h"
#include <iostream>
#include <bitset>

FourChannels::FourChannels():Image(){}
FourChannels::~FourChannels() {
        for (int i = 0; i < width; i++)
            delete[] pixels[i];
    delete  pixels;
}


void FourChannels::loadImage(string filename) {

    ifstream picture;
    path=filename;

    //open the stream to the file
    picture.open(filename);

    //check if che file it's been opened
    if (picture.fail()) {
        cout << "Errore di caricamento" << endl;
    }

    this->headerCommentCheck(&picture);

    //  allocate memory for the pixels matrix
    pixels = new Transparent_Color*[width];
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


    picture.close();
}


void FourChannels::saveImage(string filename) {
    ofstream imageFile;
    imageFile.open(filename);

    // write the ppm header
    imageFile << magic << endl << width<< endl << height
              << endl << to_string(max);// << endl;


    //  SCRIVE IL CONTENUTO DI BYTES NEL FILE
    imageFile.write(bytes,width*height*4);
    imageFile.close(); //close the stream
}


//TODO
void FourChannels::effect(float** e) {
}