//
// Created by Lorenzo De Luca on 21/03/18.
//

#ifndef KERNELIMAGEPROCESSING_IMAGE_BASE_H
#define KERNELIMAGEPROCESSING_IMAGE_BASE_H

#include <iostream>
#include <fstream>

using namespace std;

class Image_Base{
public:
    virtual ~Image_Base(){};
    virtual void loadImage(string filename){};
    virtual void saveImage(string filename){};
    virtual void effect(float **e){};

    //ritorna il magic number dell'immagine (P1, P2...)
    string magicCheck(string filename){

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

};
#endif //KERNELIMAGEPROCESSING_IMAGE_BASE_H
