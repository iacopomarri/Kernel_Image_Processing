//
// Created by iacopo on 12/10/16.
//
#include "Image.h"
#include <fstream>
#include <iostream>
#include <bitset>


Image::Image():magic("null"),width(0),height(0),max(0){}

Image::~Image() { delete[] bytes; }

int Image::getHeight()const{return height; }
int Image::getWidth()const {return width; }
int Image::getMax()const{return max; }
string Image::getMagic() const { return magic;}

void Image::setHeight(int h){this->height=h;}
void Image::setWidth(int w){this->width=w;}
void Image::setMax(int m){this->max=m;}
void Image::setMagic(string m) {this->magic = m;}

//void Image::effect(int effectCode)
/*{
    int NexternalCicle=(width-2)*(height-2);


    for(int i=0; i<NexternalCicle; i++)
    {
        int sum = 0;
d        {
            sharpen[j]*bytes[i]
        }

    }
}*/


/*void Image::loadImage(std::string filename  ) {
        ifstream picture;
        picture.open(filename);                            //open the stream to the file
        if (picture.fail()) {                              //check if che file it's been opened
                cout << "Errore di caricamento" << endl;
        }

        picture >> Image::magic >> Image::width >> Image::height >> Image::max;

        cout<<magic<<endl;
        cout<<width<<endl;
        cout<<height<<endl;
        cout<<max<<endl;

        pixels = new Color[width*height];       //  allocate memory for the pixels array
        int size = width*height;

        bytes = new char[size*3];


        //LEGGE IL FILE E LO METTE IN bytes
        picture.read(bytes, size*3);



        // METTE IN PIXELS I VALORI IMMAGAZZINATI IN bytes
        for (int i=0; i<size; i++)
        {
                pixels[i].setR(bytes[i*3]);
                pixels[i].setG(bytes[i*3+1]);
                pixels[i].setB(bytes[i*3+2]);
        }


        //STAMPA SOLO TOT PIXELS CHE SENNO SI IMPALLA

        for(int i=0; i<6000;i++){

                //cout<<i <<" : "<<"\t";

                cout<<(unsigned int)pixels[i].getR()<<"\t";      bitset<8>x(pixels[i].getR());  cout<<x<<"\t";     cout<<pixels[i].getR()<<"\t\t\t";
                cout<<(unsigned int)pixels[i].getG()<<"\t";      bitset<8>y(pixels[i].getG());  cout<<y<<"\t";     cout<<pixels[i].getG()<<"\t\t\t";
                cout<<(unsigned int)pixels[i].getB()<<"\t";      bitset<8>z(pixels[i].getB());  cout<<z<<"\t";     cout<<pixels[i].getB()<<"\t\t\t"<<endl;

        }


        picture.close();             //close the stream
}



void Image::saveImage(std::string filename) {

        ofstream imageFile;
        imageFile.open(filename);

        // write the ppm header
        imageFile << magic << endl << width<< endl << height
        << endl << to_string(max);// << endl;


    //  SCRIVE IL CONTENUTO DI BYTES NEL FILE
       imageFile.write(bytes,width*height*3);
        imageFile.close();          //close the stream

}


Image Image::operator=(const Image& other)
{
        height = other.height;
        width = other.width;
      //  loader = other.loader;
        pixels = other.pixels;

        return *this;
}


Image::Image(const Image& copy)
{
        width = copy.width;
        height = copy.height;
     //   loader = copy.loader;

        pixels = new Color[copy.height];
        for(int i = 0; i < copy.height; i++)
        {
                pixels = new Color[copy.width];
        }

        for(int h = 0; h < copy.height; h++)
        {
                for(int w = 0; w < copy.width; w++)
                {
                        pixels[h*w] = copy.pixels[h*w];
                }
        }

}*/





