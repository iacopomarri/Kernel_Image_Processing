
#include "Channels_3.h"
#include <fstream>
#include <iostream>
#include <bitset>



Channels_3::Channels_3():Image(){}

void Channels_3::loadImage(string filename) {

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
        magic=a;
    }

    flag=false;

    while(!flag) {
        picture >> a;
        if (a == "#")
            std::getline(picture, a);
        else
            flag = true;
        width=atoi(a.c_str());
    }

    flag=false;

    while(!flag) {
        picture >> a;
        if (a == "#")
            std::getline(picture, a);
        else
            flag = true;
        height=atoi(a.c_str());
    }

    flag=false;

    while(!flag) {
        picture >> a;
        if (a == "#")
            std::getline(picture, a);
        else
            flag = true;
        max=atoi(a.c_str());
    }


        path=filename;      //mette il percorso dell'immagine nell'attributo path dell'oggetto immagine
        cout<<path<<endl;
        cout<<magic<<endl;
        cout<<width<<endl;
        cout<<height<<endl;
        cout<<max<<endl;



        pixels = new Color*[width];         //  allocate memory for the pixels matrix
        int size = width*height;

        for(int i=0; i<width;i++)
            pixels[i]=new Color[height];



        bytes = new char[size*3];

        //LEGGE IL FILE E LO METTE IN bytes
        picture.read(bytes, size*3);



       //  METTE IN PIXELS I VALORI IMMAGAZZINATI IN bytes
        for (int i=0; i<height; i++)
            for(int j=0; j<width;j++) {
                pixels[i][j].setR(bytes[3*i*width+3*j]);
                pixels[i][j].setG(bytes[3*i*width+3*j+1]);
                pixels[i][j].setB(bytes[3*i*width+3*j+2]);
            }


        picture.close();             //close the stream
    }


void Channels_3::saveImage(string filename) {


    ofstream imageFile;
    imageFile.open(filename);

    // write the ppm header
    imageFile << magic << endl << width<< endl << height
              << endl << to_string(max);// << endl;


    //  SCRIVE IL CONTENUTO DI BYTES NEL FILE
    imageFile.write(bytes,width*height*3);
    imageFile.close(); //close the stream
}


void Channels_3::effect(float** e) {
        float sumR,sumG, sumB;
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

                pixels[k][h].setR(sumR);
                if(sumR>255)    pixels[k][h].setR(255);

                    //cout<<endl<<sumR<<endl;
                pixels[k][h].setG(sumG);
                if(sumG>255) pixels[k][h].setG(255);
                    //cout<<endl<<sumG<<endl;

                pixels[k][h].setB(sumB);
                if(sumB>255)  pixels[k][h].setB(255);
                    //cout<<endl<<sumB<<endl;

            }
        width-=2;
        height-=2;

        bytes = new char[3*width*height];
        bytes[0]='\n';

        cout<<endl;
        cout<<path<<endl;
        cout<<magic<<endl;
        cout<<width<<endl;
        cout<<height<<endl;
        cout<<max<<endl;


        cout<<endl;

        for(int i=1; i<height;i++)
            for(int j=0; j<width;j++) {
                bytes[3*i * width + 3*j] = pixels[i][j].getR();
                bytes[3*i* width + 3*j+1] = pixels[i][j].getG();
                bytes[3*i * width + 3*j+2] = pixels[i][j].getB();

                }

        // /home/iacopo/Desktop/immagini/aaa.pgm

}
