

#include "OneChannel.h"
#include <iostream>
#include <bitset>

OneChannel::OneChannel():Image(){}

OneChannel::~OneChannel(){
    for(int i = 0; i < width; ++i) {
        delete [] pixels[i];
    }
    delete  pixels;
};

void OneChannel::loadImage(string filename) {
    ifstream picture;
    path=filename;

    //open the stream to the file
    picture.open(filename);

    //check if che file it's been opened
    if (picture.fail()) {
        cout << "Errore di caricamento" << endl;
    }

    this->headerCommentCheck(&picture);

    //allocate memory for the pixels matrix
    pixels = new bool*[height];

    for(int i=0; i<height;i++) {
        pixels[i] = new bool[width];
    }


    //read legge 1 char, ossia un byte di dati. un pixel è un bit quindi per fare un byte ne servono 8. per questo si divide per 8
    int size = width*height/8;


    bytes = new char[size];

    //legge il file e lo mette in bytes
    picture.read(bytes, size);
    cout<<size;

    //mette in pixels i valori immagazzinati in bytes
    bool bits[width*height];
    //Per ogni byte estraiamo 8 bit
    for(int k=0; k< size; k++) {
        for (int h = 0; h < 8; h++) {
            bits[k * 8 + h] = (bytes[k] >> h) & 1;
        }
    }

    for (int i=0; i<height; i++){
        for(int j=0; j<width; j++) {
            pixels[i][j] = bits[(i*width)+j];
        }
    }

    picture.close();

    }



void OneChannel::saveImage(string filename) {
    ofstream imageFile;
    imageFile.open(filename);

    // write the ppm header
    imageFile << magic << endl << width << endl << height << endl;


    //scrive il contenuto di bytes nel file
    imageFile.write(bytes,width*height/8);
    imageFile.close();

}

//TODO implement this
void OneChannel::effect(float** e) {
}

