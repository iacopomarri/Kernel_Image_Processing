
#include "TwoChannels.h"
#include <fstream>
#include <iostream>
#include <bitset>


TwoChannels::TwoChannels():Image(){}

void TwoChannels::loadImage(string filename) {
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

    pixels = new char*[width]; //  allocate memory for the pixels matrix
    for(int i=0; i<width;i++)
        pixels[i]=new char[height];
    int size = width*height;

    bytes = new char[size];


    //LEGGE IL FILE E LO METTE IN bytes
    picture.read(bytes, size);



    // METTE IN PIXELS I VALORI IMMAGAZZINATI IN bytes
    for (int i=0; i<height; i++){
        for(int j=0; j<width; j++) {
            pixels[i][j] = bytes[(i*width)+j];
        }
    }
    picture.close();             //close the stream

}

void TwoChannels::saveImage(string filename) {
    ofstream imageFile;
    imageFile.open(filename);

    // write the ppm header
    imageFile << magic << endl << width << endl << height
              << endl << to_string(max);// << endl;


    //  SCRIVE IL CONTENUTO DI BYTES NEL FILE
    imageFile.write(bytes,width*height);
    imageFile.close();          //close the stream

}


void TwoChannels::effect(float** e) {
    float sum;
    int a, b;
  /*  cout<<endl<<(int)(unsigned char)bytes[1]<<endl;
    cout<<endl<<(int)(unsigned char)bytes[2]<<endl;
    cout<<endl<<(unsigned char)bytes[2]<<endl;
*/



   /* cout<<"9 elementi di pixels prima di blur"<<endl;
    for(int i=0; i<3;i++)
        for(int j=0; j<3;j++)
            cout<<(int)(unsigned char)pixels[i][j]<<endl;

*/



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
        }
    width-=2;
    height-=2;


    cout<<endl<<(int)pixels[0][0]<<endl;

    bytes = new char[width*height];
    bytes[0]='\n';

    cout<<endl;
    cout<<path<<endl;
    cout<<magic<<endl;
    cout<<width<<endl;
    cout<<height<<endl;
    cout<<max<<endl;

    for(int i=0; i<10;i++)
        cout<<pixels[0][i];

    cout<<endl;

    for(int i=1; i<height;i++)
        for(int j=0; j<width;j++)
            bytes[i*width+j]=pixels[i][j];


}

