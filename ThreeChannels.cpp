
#include "ThreeChannels.h"
#include <iostream>
#include <bitset>



ThreeChannels::ThreeChannels():Image(){}
ThreeChannels::~ThreeChannels() {
    for (int i = 0; i < width; i++)
        delete[] pixels[i];
    delete  pixels;
}

void ThreeChannels::loadImage(string filename) {
        ifstream picture;
        path=filename;

        //open the stream to the file
        picture.open(filename);

        //check if che file it's been opened
        if (picture.fail()) {
            cout << "Errore di caricamento" << endl;
        }

        this->headerCommentCheck(&picture);

        //allocate memory for the pixels matrix
        pixels = new Color*[width];
        for(int i=0; i<width;i++)
            pixels[i]=new Color[height];

        //dimensione in bytes dell'immagine
        int size = width*height*3;


        //alloca memoria per bytes
        bytes = new char[size];

        //legge il file e lo mette in bytes
        picture.read(bytes, size);


    //mette in pixels i valori immagazzinati in bytes
        for (int i=0; i<height; i++)
            for(int j=0; j<width;j++) {
                pixels[i][j].setR(bytes[3*i*width+3*j]);
                pixels[i][j].setG(bytes[3*i*width+3*j+1]);
                pixels[i][j].setB(bytes[3*i*width+3*j+2]);
            }

        picture.close();
    }


void ThreeChannels::saveImage(string filename) {
    ofstream imageFile;
    imageFile.open(filename);

    // write the ppm header. l'ultimo endl serve se salvo dopo aver applicato l'effetto, mentre se salvo senza applicarlo non va messo      . da capire perchè
    imageFile << magic << endl << width<< endl << height
              << endl << to_string(max);//<< endl;


    //scrive il contenuto di bytes nel file

    imageFile.write(bytes,width*height*3);
    imageFile.close();
}

//i valori R G e B dei pixels di ogni sottomatrice 3x3 vengono moltiplicati per il rispettivo valore della matrice kernel e sommati
//tra loro per colore, così da ottenere sumR sumG e sumB, che formano i valori R G B del nuovo pixel

void ThreeChannels::effect(float** e) {
        float sumR,sumG, sumB;
        double minR, minG, minB=1.0/0.0;
        double maxR, maxG, maxB=-1.0/0.0;
        //parametri usati per indicizzare la matrice kernel 3x3 dell'effetto usato
        int a, b;


        for(int k=0; k<height-2;k++)
            for(int h=0; h<width-2;h++) {
                sumR = 0;
                sumG = 0;
                sumB = 0;
                a = 0;
                for (int i = k; i < k + 3; i++) {
                    b = 0;
                    for (int j = h; j < h + 3; j++) {
                        sumR += e[a][b] * (int) (unsigned char) pixels[i][j].getR();
                        sumG += e[a][b] * (int) (unsigned char) pixels[i][j].getG();
                        sumB += e[a][b] * (int) (unsigned char) pixels[i][j].getB();
                        b++;
                    }
                    a++;

                }

                //trova max e min di ogni sum

                pixels[k][h].setR(sumR);
                if (sumR > maxR)
                    maxR = sumR;
                if (sumR < minR)
                    minR = sumR;

                pixels[k][h].setG(sumG);
                if (sumG > maxG)
                    maxG = sumG;
                if (sumG < minG)
                    minG = sumG;


                pixels[k][h].setB(sumB);
                if (sumB > maxB)
                    maxB = sumB;
                if (sumB < minB)
                    minB = sumB;
            }

    //le dimensioni dell'immagine si riducono di 2 in seguito alla convoluzione
    width-=2;
    height-=2;

        //reinstanzia bytes con le nuove dimensioni
        delete [] bytes;
        bytes = new char[3*width*height];

    //normalizzazione
    for(int i=0; i<height;i++)
        for(int j=0; j<width;j++) {
            pixels[i][j].setR((pixels[i][j].getR() - minR) * (255 / (maxR - minR)));
            pixels[i][j].setG((pixels[i][j].getG() - minG) * (255 / (maxG - minG)));
            pixels[i][j].setB((pixels[i][j].getB() - minB) * (255 / (maxB - minB)));
        }

        //mette la nuova immagine in bytes per essere salvata
        //+1 all'inizio dell'indicizzazione serve per lasciare la prima posizione vuota, per aggiungerci poi '\n'. Il metodo read mette all
        //inizio un accapo, e per far funzionare saveimage lo mettiamo anche noi.
       for(int i=0; i<height;i++)
            for(int j=0; j<width;j++) {
                bytes[3*i * width + 3*j] = pixels[i][j].getR();
                bytes[3*i* width + 3*j+1] = pixels[i][j].getG();
                bytes[3*i * width + 3*j+2] = pixels[i][j].getB();
            }
bytes[0]='\n';

}



    ///home/iacopo/Desktop/vecchio.ppm