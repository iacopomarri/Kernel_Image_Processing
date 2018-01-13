
#include "ThreeChannels.h"
#include <iostream>
#include <bitset>



ThreeChannels::ThreeChannels():Image(){}

void ThreeChannels::loadImage(string filename) {
        ifstream picture;

        //open the stream to the file
        picture.open(filename);

        //check if che file it's been opened
        if (picture.fail()) {
            cout << "Errore di caricamento" << endl;
        }

        this->commentCheck(&picture);

        path=filename;
        cout<<path<<endl;
        cout<<magic<<endl;
        cout<<width<<endl;
        cout<<height<<endl;
        cout<<max<<endl;


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

    // write the ppm header
    imageFile << magic << endl << width<< endl << height
              << endl << to_string(max) << endl;


    //scrive il contenuto di bytes nel file
    imageFile.write(bytes,width*height*3);
    imageFile.close();
}

//i valori R G e B dei pixels di ogni sottomatrice 3x3 vengono moltiplicati per il rispettivo valore della matrice kernel e sommati
//tra loro per colore, così da ottenere sumR sumG e sumB, che formano i valore R G B del nuovo pixel

void ThreeChannels::effect(float** e) {
        float sumR,sumG, sumB;
        //parametri usati per indicizzare la matrice kernel 3x3 dell'effetto usato
        int a, b;


        for(int k=0; k<height-2;k++)
            for(int h=0; h<width-2;h++) {
                sumR = 0;
                sumG = 0;
                sumB = 0;
                a=0;
                for (int i = k; i < k + 3; i++) {
                    b=0;
                    for (int j = h; j < h + 3; j++) {
                        sumR += e[a][b] *(int)(unsigned char) pixels[i][j].getR();
                        sumG += e[a][b] *(int)(unsigned char) pixels[i][j].getG();
                        sumB += e[a][b] *(int)(unsigned char) pixels[i][j].getB();
                        b++;
                    }
                    a++;

                }

                //inseriti controlli per evitare pixels di valori superiori a 255.
                //da risolvere il problema che alcuni suerano 255

                pixels[k][h].setR(sumR);
                if(sumR>255)    pixels[k][h].setR(255);

                pixels[k][h].setG(sumG);
                if(sumG>255) pixels[k][h].setG(255);

                pixels[k][h].setB(sumB);
                if(sumB>255)  pixels[k][h].setB(255);

            }

        //le dimensioni dell'immagine si riducono di 2 in seguito alla convoluione
        width-=2;
        height-=2;

        //reinstanzia bytes con le nuove dimensioni
        bytes = new char[3*width*height];
        //bytes[0]='\n';


        //mette la nuova immagine in bytes per essere salvata
        for(int i=1; i<height;i++)
            for(int j=0; j<width;j++) {
                bytes[3*i * width + 3*j] = pixels[i][j].getR();
                bytes[3*i* width + 3*j+1] = pixels[i][j].getG();
                bytes[3*i * width + 3*j+2] = pixels[i][j].getB();
            }
}
