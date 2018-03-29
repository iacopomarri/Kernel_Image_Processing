//
// Created by iacopo on 12/10/16.
//
#include "Image.h"
#include <iostream>
#include <bitset>

template <typename T>
Image<T>::Image():magic("null"),path("null"),width(0),height(0),max(0),size(0){}

//Image::~Image() { delete[] bytes; }

template <typename T>
int Image<T>::getHeight()const{return height; }
template <typename T>
int Image<T>::getWidth()const {return width; }
template <typename T>
int Image<T>::getMax()const{return max; }
template <typename T>
int Image<T>::getSize() const { return size;}
template <typename T>
string Image<T>::getMagic() const { return magic;}
template <typename T>
string Image<T>::getPath() const {return path;}

template <typename T>
void Image<T>::setHeight(int h){this->height=h;}
template <typename T>
void Image<T>::setWidth(int w){this->width=w;}
template <typename T>
void Image<T>::setMax(int m){this->max=m;}
template <typename T>
void Image<T>::setMagic(string m) {this->magic = m;}
template <typename T>
void Image<T>::setPath(string p) {this->path=p;}
template <typename T>
void Image<T>::setSize(int s) {this->size=s;}


template <typename T>
void Image<T>::modifyPixel(int i, int j, T newPix) {
    Pixels[i][j]=newPix;
}

template <typename T>
T Image<T>::readPixel(int i, int j) {
    return Pixels[i][j];
}

template <typename T>
void Image<T>::loadImage(string filename) {
    ifstream picture;
    char *temp;
    path = filename;

    picture.open(path);                            //open the stream to the file
    if (picture.fail()) {                              //check if che file it's been opened
        cout << "Errore di caricamento" << endl;
        return;
    }

    headerCommentCheck(&picture);

    //dimensione in bytes dell'immagine
    size = width * height;

    //alloca memoria per temp
    temp = new char[size];

    //legge il file e lo mette in temp
    picture.read(temp, size);

    //allocate memory for the pixels matrix
    Pixels = new T *[height];
    for (int i = 0; i < height; i++)
        Pixels[i] = new T[width];

    //mette in pixels i valori immagazzinati in temp
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            Pixels[i][j] = temp[(i * width) + j];

    picture.close();
}

//loadimage per T=Color
template <>
void Image<Color>::loadImage(string filename) {
    ifstream picture;
    char *temp;
    path=filename;

    picture.open(path);                            //open the stream to the file
    if (picture.fail()) {                              //check if che file it's been opened
        cout << "Errore di caricamento" << endl;
        return;
    }

    headerCommentCheck(&picture);

    //dimensione in bytes dell'immagine
    size=width*height*3;

    //alloca memoria per temp
    temp = new char[size];

    //legge il file e lo mette in bytes
    picture.read(temp, size);

    //allocate memory for the pixels matrix
    Pixels = new Color*[height];
    for(int i=0; i<height;i++)
        Pixels[i]=new Color[width];

    //mette in pixels i valori immagazzinati in bytes
    for (int i=0; i<height; i++)
        for(int j=0; j<width;j++) {
            Pixels[i][j].setR(temp[3*i*width+3*j]);
            Pixels[i][j].setG(temp[3*i*width+3*j+1]);
            Pixels[i][j].setB(temp[3*i*width+3*j+2]);
        }

    picture.close();
}


template <typename T>
void Image<T>::saveImage(string filename) {
    ofstream imageFile;
    imageFile.open(filename);
    char* temp;
    temp=new char[size];

    //mette la nuova immagine in temp per essere salvata
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            temp[i * width + j] = Pixels[i][j];
    temp[0]='\n';


    //write the ppm header
    imageFile << magic << endl << width << endl << height;

    if (magic != "P1" and magic != "P4")
        imageFile <<endl<< to_string(max);

    //scrive il contenuto di temp nel file
    imageFile.write(temp,size);
    imageFile.close();
}

//save per T=Color
template <>
void Image<Color>::saveImage(string filename) {
    ofstream imageFile;
    imageFile.open(filename);
    char* temp;
    temp=new char[size];

    //mette la nuova immagine in temp per essere salvata
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++) {
            temp[3 * i * width + 3 * j] = Pixels[i][j].getR();
            temp[3 * i * width + 3 * j + 1] = Pixels[i][j].getG();
            temp[3 * i * width + 3 * j + 2] = Pixels[i][j].getB();
        }
    temp[0]='\n';

    //write the ppm header
    imageFile << magic << endl << width << endl << height<<endl<< to_string(max);

    //scrive il contenuto di temp nel file
    imageFile.write(temp,size);
    imageFile.close();
}

template <typename T>
void Image<T>::effect(float **e) {
    float sum;
    double min=1.0/0.0;
    double max=-1.0/0.0;

    //parametri usati per indicizzare la matrice kernel 3x3 dell'effetto usato
    int a, b;

    //le dimensioni dell'immagine si riducono di 2 in seguito alla convoluzione
    width-=2;
    height-=2;



    for(int k=0; k<height;k++)
        for(int h=0; h<width;h++) {
            sum = 0;
            a = 0;
            for (int i = k; i < k + 3; i++) {
                b = 0;
                for (int j = h; j < h + 3; j++) {
                    sum += e[a][b] * (int) (unsigned char) Pixels[i][j];
                    b++;
                }
                a++;
            }
            Pixels[k][h] = sum;

            if (sum > max)
                max = sum;
            if (sum < min)
                min = sum;
        }

    //normalizzazione
    for(int i=0; i<height;i++)
        for(int j=0; j<width;j++)
            Pixels[i][j] = (Pixels[i][j] - min) * (255 / (max - min));

}

//effetct per T=Color
template <>
void Image<Color>::effect(float **e){
    float sumR,sumG, sumB;
    double minR, minG, minB=1.0/0.0;
    double maxR, maxG, maxB=-1.0/0.0;

    //parametri usati per indicizzare la matrice kernel 3x3 dell'effetto usato
    int a, b;

    //le dimensioni dell'immagine si riducono di 2 in seguito alla convoluzione
    width-=2;
    height-=2;

    for (int k = 0; k < height; k++)
        for (int h = 0; h < width; h++) {
            sumR = 0;
            sumG = 0;
            sumB = 0;
            a = 0;
            for (int i = k; i < k + 3; i++) {
                b = 0;
                for (int j = h; j < h + 3; j++) {
                    sumR += e[a][b] * (int) (unsigned char) Pixels[i][j].getR();
                    sumG += e[a][b] * (int) (unsigned char) Pixels[i][j].getG();
                    sumB += e[a][b] * (int) (unsigned char) Pixels[i][j].getB();
                    b++;
                }
                a++;

            }

            //trova max e min di ogni sum

            Pixels[k][h].setR(sumR);
            if (sumR > maxR)
                maxR = sumR;
            if (sumR < minR)
                minR = sumR;

            Pixels[k][h].setG(sumG);
            if (sumG > maxG)
                maxG = sumG;
            if (sumG < minG)
                minG = sumG;


            Pixels[k][h].setB(sumB);
            if (sumB > maxB)
                maxB = sumB;
            if (sumB < minB)
                minB = sumB;
        }

    //normalizzazione
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++) {
            Pixels[i][j].setR((Pixels[i][j].getR() - minR) * (255 / (maxR - minR)));
            Pixels[i][j].setG((Pixels[i][j].getG() - minG) * (255 / (maxG - minG)));
            Pixels[i][j].setB((Pixels[i][j].getB() - minB) * (255 / (maxB - minB)));
        }
}

//controlla se la riga letta  è un commento, in tal caso la salta
//il tutto è ripetuto 1 volta per ogni attributo; per fare tutto in un unico ciclo
//è necessario cambiare la struttura della classe usando un vettore al posto dei singoli
//attributi, e di conseguenza vanno cambiate diverse cose nel programma
template <typename T>
void Image<T>::headerCommentCheck(ifstream* picture) {
    string byteToCheck = "";
    bool isComment = false;

    while (!isComment) {
        *picture >> byteToCheck;
        if (byteToCheck == "#")
            std::getline(*picture, byteToCheck);
        else
            isComment = true;
        magic = byteToCheck;
    }

    isComment = false;

    while (!isComment) {
        *picture >> byteToCheck;
        if (byteToCheck == "#")
            std::getline(*picture, byteToCheck);
        else
            isComment = true;
        //a va convertito in intero
        width = atoi(byteToCheck.c_str());
    }

    isComment = false;

    while (!isComment) {
        *picture >> byteToCheck;
        if (byteToCheck == "#")
            std::getline(*picture, byteToCheck);
        else
            isComment = true;
        height = atoi(byteToCheck.c_str());
    }

    isComment = false;

    if (magic != "P1" and magic != "P4") {
        while (!isComment) {
            *picture >> byteToCheck;
            if (byteToCheck == "#")
               std::getline(*picture, byteToCheck);
            else
                isComment = true;
            max = atoi(byteToCheck.c_str());
        }
    }
}




template <typename T>
Image<T>& Image<T>::operator=(const Image& other)
{
        height = other.height;
        width = other.width;
        size = other.size;
        max = other.max;
        path = other.path;
        magic = other.magic;
    
        Pixels = new T *[height];
        for (int i = 0; i < height; i++)
            Pixels[i] = new T[width];

        for (int i = 0; i < height; i++)
            for (int j = 0; j < width; j++)
                Pixels[i][j] = other.Pixels[i][j];

        return *this;
}

template <typename T>
Image<T>::Image(const Image& copy)
{
        width = copy.width;
        height = copy.height;
        size = copy.size;
        max = copy.max;
        path = copy.path;
        magic = copy.magic;

        Pixels = new T*[height];
        for(int i = 0; i < height; i++)
                Pixels[i] = new T[width];

        for(int w = 0; w < height; w++)
                for(int h = 0; h < width; h++)
                        Pixels[w][h] = copy.Pixels[w][h];

}




template class Image<char>;
template class Image<Color>;
