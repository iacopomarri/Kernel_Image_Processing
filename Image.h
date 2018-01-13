#ifndef KERNELIMAGEPROCESSING_IMAGE_H
#define KERNELIMAGEPROCESSING_IMAGE_H

#include <string>
#include <fstream>


using namespace std;


class Image{
public:
    Image();
    virtual ~Image();

    //Image(const Image& copy);
    //Image operator=(const Image&);

    virtual void loadImage(string filename)=0;
    virtual void saveImage(string filename)=0;
    virtual void effect(float** e)=0;

    //ritorna il magic number dell'immagine (P1, P2...)
    string magicCheck(string filename);

    //trova ed evita i commenti nell'immagine. legge gli attributi
    //ifstream passato come riferimento altrimenti dà problema "deleted function"
    void commentCheck(ifstream* picture);



    int getHeight()const;
    int getWidth()const;
    int getMax()const;
    string getPath();
    string getMagic() const;

    void setHeight(int h);
    void setWidth(int w);
    void setMax(int m);
    void setMagic(string m);

protected:
    string magic;
    string path;
    int width;
    int height;
    int max;
    char* bytes; //contiene i bytes dell'immagine in sequenza senza far distinzione tra i vari pixels, serve per leggere e scrivere l'immagine sul file



};

#endif //KERNELIMAGEPROCESSING_IMAGE_H
