#ifndef KERNELIMAGEPROCESSING_IMAGE_H
#define KERNELIMAGEPROCESSING_IMAGE_H

#include <string>
#include <fstream>
#include "Color.h"


using namespace std;


class Image{
public:
    Image();
    virtual ~Image();

    //Image(const Image& copy);
    //Image operator=(const Image&);

    void loadImage(string filename);
    void saveImage(string filename);

    //effect applica l'effetto desiderato all'immagine; float** e è un vettore bidimensionale 3x3 contenente il kernel
    void effect(float** e);

    //ritorna il magic number dell'immagine (P1, P2...)
    //string magicCheck(string filename);

    //legge l'header dell'immagine evitando le righe di commento.
    //ifstream passato come riferimento altrimenti dà problema "deleted function"
    void headerCommentCheck(ifstream* picture);



    int getHeight()const;
    int getWidth()const;
    int getMax()const;
    string getPath()const;
    string getMagic() const;
    int getSize()const;

    void setHeight(int h);
    void setWidth(int w);
    void setMax(int m);
    void setMagic(string m);
    void setPath(string p);
    void setSize(int size);
protected:
    string magic;
    string path;
    int width;
    int height;
    int max;
    int size;
    char** greyPixels;
    Color** RGBPixels;
    char* bytes; //contiene i bytes dell'immagine in sequenza senza far distinzione tra i vari pixels, serve per leggere e scrivere l'immagine sul file



};

#endif //KERNELIMAGEPROCESSING_IMAGE_H
