

#include "Channel_1.h"
#include <fstream>
#include <iostream>
#include <bitset>

Channel_1::Channel_1():Image(){}

Channel_1::~Channel_1(){
    for(int i = 0; i < width; ++i) {
        delete [] pixels[i];
    }
    delete [] pixels;
};

void Channel_1::loadImage(string filename) {
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
                magic=a;
        }

        flag=false;

        while(!flag) {
            picture >> a;
            if (a == "#")
                std::getline(picture, a);
            else
                flag = true;
            width=atoi(a.c_str());
        }

        flag=false;

        while(!flag) {
            picture >> a;
            if (a == "#")
                std::getline(picture, a);
            else
                flag = true;
            height=atoi(a.c_str());
        }





    path=filename;      //mette il percorso dell'immagine nell'attributo path dell'oggetto immagine
    cout<<path<<endl;
    cout<<magic<<endl;
    cout<<width<<endl;
    cout<<height<<endl;
    cout<<path;


    pixels = new bool*[height]; //  allocate memory for the pixels matrix

    for(int i=0; i<height;i++) {
        pixels[i] = new bool[width];
    }


    //read legge 1 char, ossia un byte di dati. un pixel è un bit quindi per fare un byte ne servono 8. per questo si divide per 8
    int size = width*height/8;


    bytes = new char[size];
    //LEGGE IL FILE E LO METTE IN bytes
    picture.read(bytes, size);
    cout<<size;

    // METTE IN PIXELS I VALORI IMMAGAZZINATI IN bytes
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

    picture.close();             //close the stream

    }



void Channel_1::saveImage(string filename) {
    ofstream imageFile;
    imageFile.open(filename);

    // write the ppm header
    imageFile << magic << endl << width << endl << height;// << endl;


    //  SCRIVE IL CONTENUTO DI BYTES NEL FILE
    imageFile.write(bytes,width*height/8);
    imageFile.close();          //close the stream

}

void Channel_1::effect(float** e) {
}

