#ifndef KERNELIMAGEPROCESSING_IMAGE_H
#define KERNELIMAGEPROCESSING_IMAGE_H

//#include <string>
#include <fstream>
#include <array>
#include "Color.h"
#include "Image_Base.h"


using namespace std;

template <typename T>
class Image:public Image_Base{
public:
    Image();
    ~Image();

    Image(const Image& copy);
    Image& operator=(const Image&);

    void loadImage(string filename) override;
    void saveImage(string filename) override;

    //effect applica l'effetto desiderato all'immagine; float** e è un vettore bidimensionale 3x3 contenente il kernel
    void effect(float** e) override;



    //legge l'header dell'immagine evitando le righe di commento.
    //ifstream passato come riferimento altrimenti dà problema "deleted function"
    void headerCommentCheck(ifstream* picture);



    int getHeight()const;
    int getWidth()const;
    int getMax()const;
    int getSize()const;
    string getPath()const;
    string getMagic() const;

    void setHeight(int h);
    void setWidth(int w);
    void setMax(int m);
    void setSize(int size);
    void setPath(string p);
    void setMagic(string m);

    //metodi per modificare il pixel in posizione (i,j)
    //void modifyRGB(int i, int j, char R, char G, char B);
    void modifyPixel(int i, int j, T newPix);

    //metodi per leggere il pixel in posizione (i,j)
    //Color readRGB(int i, int j);
    T readPixel(int i, int j);

protected:
    string magic;
    string path;
    int width;
    int height;
    int max;
    int size;
    T** Pixels;
    //char** greyPixels;
    //Color** RGBPixels;
    //char* bytes; //contiene i bytes dell'immagine in sequenza senza far distinzione tra i vari pixels, serve per leggere e scrivere l'immagine sul file



};

#endif //KERNELIMAGEPROCESSING_IMAGE_H
