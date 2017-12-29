
#include "FourChannels.h"
#include <fstream>
#include <iostream>
#include <bitset>

FourChannels::FourChannels():Image(){}


void FourChannels::loadImage(string filename) {

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

    flag=false;

    while(!flag) {
        picture >> a;
        if (a == "#")
            std::getline(picture, a);
        else
            flag = true;
        max=atoi(a.c_str());
    }

    path=filename;
    cout<<path<<endl;
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

void FourChannels::effect(float** e) {
}