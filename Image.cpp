//
// Created by iacopo on 12/10/16.
//
#include "Image.h"
#include <fstream>
#include <iostream>


Image::Image():datatype("nulla"),width(0),height(0),max(255){}
Image::~Image() { delete[] pixels; }


void Image::loadImage(std::string filename) {
        ifstream picture;
        picture.open(filename);                            //open the stream to the file
        if (picture.fail()) {                              //check if che file it's been opened
                cout << "Errore di caricamento" << endl;
        }



        picture >> this->datatype >> this->height >> this->width >> this->max;         //extract header datas from the file


        cout<<datatype<<endl;
        cout<<width<<endl;
        cout<<height<<endl;
        cout<<max<<endl;

        pixels = new Color[width*height];       //  allocate memory for the pixels array
        int size = width*height;


        for(int i=0; i<size;i++){                //extract one bytes per time from the file (in order r g b) and put them into che pixels array
                char a;
                cout<<i <<" : "<<"\t";

                picture >> a;
                pixels[i].setR(a);
                cout<<pixels[i].getR()<<"\t";

                picture >> a;
                pixels[i].setG(a);
                cout<<pixels[i].getG()<<"\t";

                picture >> a;
                pixels[i].setB(a);
                cout<<pixels[i].getB()<<"\t"<<endl;
        }



        picture.close();             //close the stream

}


