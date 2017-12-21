
#include "Channels_3.h"
#include <fstream>
#include <iostream>
#include <bitset>



Channels_3::Channels_3():Image(){}

void Channels_3::loadImage(string filename) {

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


        path=filename;      //mette il percorso dell'immagine nell'attributo path dell'oggetto immagine
        cout<<path<<endl;
        cout<<magic<<endl;
        cout<<width<<endl;
        cout<<height<<endl;
        cout<<max<<endl;



        pixels = new Color*[width];         //  allocate memory for the pixels matrix
        int size = width*height;

        for(int i=0; i<width;i++)
            pixels[i]=new Color[height];



        bytes = new char[size*3];


        //LEGGE IL FILE E LO METTE IN bytes
        picture.read(bytes, size*3);


/*
        // METTE IN PIXELS I VALORI IMMAGAZZINATI IN bytes
        for (int i=0; i<height; i++)
            for(int j=0; j<width;j++) {
                pixels[i][j].setR(bytes[(j * 3)+(i*width*3)]);
                pixels[i][j].setG(bytes[(j * 3)+(i*width*3)]);
                pixels[i][j].setB(bytes[(j * 3)+(i*width*3)]);
            }
*/

        picture.close();             //close the stream
    }


void Channels_3::saveImage(string filename) {


    ofstream imageFile;
    imageFile.open(filename);

    // write the ppm header
    imageFile << magic << endl << width<< endl << height
              << endl << to_string(max);// << endl;


    //  SCRIVE IL CONTENUTO DI BYTES NEL FILE
    imageFile.write(bytes,width*height*3);
    imageFile.close(); //close the stream
}


void Channels_3::effect(float** e) {
}
