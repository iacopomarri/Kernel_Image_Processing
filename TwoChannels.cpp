
#include "TwoChannels.h"
#include <iostream>
#include <bitset>


TwoChannels::TwoChannels():Image(){}

TwoChannels::~TwoChannels() {
    for (int i = 0; i < width; i++)
        delete[] pixels[i];
    delete  pixels;
}

void TwoChannels::loadImage(string filename) {
    ifstream picture;
    path=filename;

    //open the stream to the file
    picture.open(filename);
    //check if che file it's been correctly opened
    if (picture.fail()) {
        cout << "Errore di caricamento" << endl;
    }

    this->headerCommentCheck(&picture);

    //allocate memory for the pixels matrix
    pixels = new char*[width];
    for(int i=0; i<width;i++)
        pixels[i]=new char[height];

    //dimensione in bytes dell'immagine
    int size = width*height;

    //alloca memoria per bytes
    bytes = new char[size];


    //legge il file e lo mette in bytes
    picture.read(bytes, size);

    // mette in pixels i valori immagazzinati in bytes
    for (int i=0; i<height; i++){
        for(int j=0; j<width; j++) {
            pixels[i][j] = bytes[(i*width)+j];
        }
    }

    picture.close();
}


void TwoChannels::saveImage(string filename) {
    ofstream imageFile;
    imageFile.open(filename);

    //write the ppm header
    imageFile << magic << endl << width << endl << height
              << endl << to_string(max) << endl;


    //scrive il contenuto di bytes nel file
    imageFile.write(bytes,width*height);
    imageFile.close();
}


void TwoChannels::effect(float** e) {
    //valori infinito meno infinito
    double max=-1.0/0.0;
    double min=1.0/0.0;

    float sum;
    //parametri usati per indicizzare la matrice kernel 3x3 dell'effetto usato
    int a, b;

    for(int k=0; k<height-2;k++)
        for(int h=0; h<width-2;h++) {
            sum = 0;
            a=0;
            for (int i = k; i < k + 3; i++) {
                b=0;
                for (int j = h; j < h + 3; j++) {
                    sum += e[a][b] *(int)(unsigned char) pixels[i][j];
                    b++;
                }
                a++;
            }
            pixels[k][h] = sum;

            if(sum>max)
                max=sum;
            if(sum<min)
                min=sum;

        }


    //le dimensioni dell'immagine si riducono di 2 in seguito alla convoluzione
    width-=2;
    height-=2;

    //normalizzazione
    for(int i=0; i<height;i++)
        for(int j=0; j<width;j++)
                pixels[i][j] = (pixels[i][j] - min) * (255 / (max - min));



    //reinstanzia bytes con le nuove dimensioni
    bytes = new char[width*height];


    //mette la nuova immagine in bytes per essere salvata
    for(int i=0; i<height;i++)
        for(int j=0; j<width;j++)
            bytes[i*width+j]=pixels[i][j];

}

