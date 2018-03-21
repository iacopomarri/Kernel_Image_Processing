//
// Created by iacopo on 12/10/16.
//
#include "Image.h"
#include <iostream>
#include <bitset>


Image::Image():magic("null"),path("null"),width(0),height(0),max(0),size(0){}

//Image::~Image() { delete[] bytes; }

int Image::getHeight()const{return height; }
int Image::getWidth()const {return width; }
int Image::getMax()const{return max; }
string Image::getMagic() const { return magic;}
string Image::getPath() const {return path;}
int Image::getSize() const { return size;}

void Image::setHeight(int h){this->height=h;}
void Image::setWidth(int w){this->width=w;}
void Image::setMax(int m){this->max=m;}
void Image::setMagic(string m) {this->magic = m;}
void Image::setPath(string p) {this->path=p;}
void Image::setSize(int s) {this->size=s;}

void Image::modifyGrey(int i, int j, char grey) {
    greyPixels[i][j]=grey;
}
void Image::modifyRGB(int i, int j, char R, char G, char B) {
    RGBPixels[i][j].setR(R);
    RGBPixels[i][j].setG(G);
    RGBPixels[i][j].setB(B);
}
char Image::readGrey(int i, int j) {
    return greyPixels[i][j];
}
Color Image::readRGB(int i, int j) {
    Color pixel;
    pixel.setR(RGBPixels[i][j].getR());
    pixel.setG(RGBPixels[i][j].getG());
    pixel.setB(RGBPixels[i][j].getB());
    return pixel;
}

//controlla se la riga letta  è un commento, in tal caso la salta
//il tutto è ripetuto 1 volta per ogni attributo; per fare tutto in un unico ciclo
//è necessario cambiare la struttura della classe usando un vettore al posto dei singoli
//attributi, e di conseguenza vanno cambiate diverse cose nel programma

void Image::loadImage(string filename) {
    ifstream picture;
    char* temp;

    path=filename;

    picture.open(path);                            //open the stream to the file
    if (picture.fail()) {                              //check if che file it's been opened
        cout << "Errore di caricamento" << endl;
        return;
    }

    headerCommentCheck(&picture);

    //dimensione in bytes dell'immagine
    size = width * height;


    //greyscale
    if(magic=="P2" or magic=="P5") {
        //alloca memoria per bytes
        temp = new char[size];

        //legge il file e lo mette in bytes
        picture.read(temp, size);

        //allocate memory for the pixels matrix
        greyPixels = new char*[width];
        for(int i=0; i<width;i++)
            greyPixels[i]=new char[height];

        // mette in pixels i valori immagazzinati in bytes
        for (int i=0; i<height; i++){
            for(int j=0; j<width; j++) {
                greyPixels[i][j] = temp[(i*width)+j];
            }
        }
    }

    //RGB
    else if(magic=="P3" or magic=="P6") {
        //dimensione in bytes dell'immagine
        size*=3;

        //alloca memoria per bytes
        temp = new char[size];

        //legge il file e lo mette in bytes
        picture.read(temp, size);

        //allocate memory for the pixels matrix
        RGBPixels = new Color*[width];
        for(int i=0; i<width;i++)
            RGBPixels[i]=new Color[height];

        //mette in pixels i valori immagazzinati in bytes
        for (int i=0; i<height; i++)
            for(int j=0; j<width;j++) {
                RGBPixels[i][j].setR(temp[3*i*width+3*j]);
                RGBPixels[i][j].setG(temp[3*i*width+3*j+1]);
                RGBPixels[i][j].setB(temp[3*i*width+3*j+2]);
            }
    }

    picture.close();
}



void Image::saveImage(string filename) {
    ofstream imageFile;
    imageFile.open(filename);
    char* temp;
    temp=new char[size];
    //mette la nuova immagine in temp per essere salvata
    //+1 all'inizio dell'indicizzazione serve per lasciare la prima posizione vuota, per aggiungerci poi '\n'. Il metodo read mette all
    //inizio un accapo, e per far funzionare saveimage lo mettiamo anche noi.
    if(magic=="P3" or magic=="P6") {
        for (int i = 0; i < height; i++)
            for (int j = 0; j < width; j++) {
                temp[3 * i * width + 3 * j] = RGBPixels[i][j].getR();
                temp[3 * i * width + 3 * j + 1] = RGBPixels[i][j].getG();
                temp[3 * i * width + 3 * j + 2] = RGBPixels[i][j].getB();
            }
        temp[0]='\n';
    }
    //mette la nuova immagine in temp per essere salvata
    else if(magic=="P2" or magic=="P5") {
        for (int i = 0; i < height; i++)
            for (int j = 0; j < width; j++)
                temp[i * width + j] = greyPixels[i][j];
        temp[0]='\n';
    }

    //write the ppm header
    imageFile << magic << endl << width << endl << height;

    if (magic != "P1" and magic != "P4")
        imageFile <<endl<< to_string(max);



    //scrive il contenuto di temp nel file
    imageFile.write(temp,size);
    imageFile.close();
}



void Image::effect(float **e) {
    float sumR,sumG, sumB, sum;
    double minR, minG, minB, min=1.0/0.0;
    double maxR, maxG, maxB, max=-1.0/0.0;

    //parametri usati per indicizzare la matrice kernel 3x3 dell'effetto usato
    int a, b;

    //le dimensioni dell'immagine si riducono di 2 in seguito alla convoluzione
    width-=2;
    height-=2;


    if(magic=="P3" or magic=="P6") {
        for (int k = 0; k < height; k++)
            for (int h = 0; h < width; h++) {
                sumR = 0;
                sumG = 0;
                sumB = 0;
                a = 0;
                for (int i = k; i < k + 3; i++) {
                    b = 0;
                    for (int j = h; j < h + 3; j++) {
                        sumR += e[a][b] * (int) (unsigned char) RGBPixels[i][j].getR();
                        sumG += e[a][b] * (int) (unsigned char) RGBPixels[i][j].getG();
                        sumB += e[a][b] * (int) (unsigned char) RGBPixels[i][j].getB();
                        b++;
                    }
                    a++;

                }

                //trova max e min di ogni sum

                RGBPixels[k][h].setR(sumR);
                if (sumR > maxR)
                    maxR = sumR;
                if (sumR < minR)
                    minR = sumR;

                RGBPixels[k][h].setG(sumG);
                if (sumG > maxG)
                    maxG = sumG;
                if (sumG < minG)
                    minG = sumG;


                RGBPixels[k][h].setB(sumB);
                if (sumB > maxB)
                    maxB = sumB;
                if (sumB < minB)
                    minB = sumB;
            }
    }
    else if(magic=="P2" or magic=="P5") {
        for(int k=0; k<height;k++)
            for(int h=0; h<width;h++) {
                sum = 0;
                a=0;
                for (int i = k; i < k + 3; i++) {
                    b=0;
                    for (int j = h; j < h + 3; j++) {
                        sum += e[a][b] *(int)(unsigned char) greyPixels[i][j];
                        b++;
                    }
                    a++;
                }
                greyPixels[k][h] = sum;

                if(sum>max)
                    max=sum;
                if(sum<min)
                    min=sum;

            }
    }

    //normalizzazione
    if(magic=="P3" or magic=="P6") {
        for (int i = 0; i < height; i++)
            for (int j = 0; j < width; j++) {
                RGBPixels[i][j].setR((RGBPixels[i][j].getR() - minR) * (255 / (maxR - minR)));
                RGBPixels[i][j].setG((RGBPixels[i][j].getG() - minG) * (255 / (maxG - minG)));
                RGBPixels[i][j].setB((RGBPixels[i][j].getB() - minB) * (255 / (maxB - minB)));
            }
    }
    else if(magic=="P2" or magic=="P5") {
        for(int i=0; i<height;i++)
            for(int j=0; j<width;j++)
                greyPixels[i][j] = (greyPixels[i][j] - min) * (255 / (max - min));
    }
}



void Image::headerCommentCheck(ifstream* picture) {
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

/*
string Image::magicCheck(string filename) {
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
    }

    return a;
}*/






Image Image::operator=(const Image& other)
{
        height = other.height;
        width = other.width;
        size = other.size;
        max = other.max;
        path = other.path;
        magic = other.magic;
    if(magic=="P2" or magic=="P5") {
        for (int i = 0; i < height; i++)
            for (int j = 0; j < width; j++)
                greyPixels[i][j] = other.greyPixels[i][j];
    }
    else if(magic=="P4" or magic=="P6") {
        for (int i = 0; i < height; i++)
            for (int j = 0; j < width; j++)
                RGBPixels[i][j] = other.RGBPixels[i][j];
    }
        return *this;
}


Image::Image(const Image& copy)
{
        width = copy.width;
        height = copy.height;
        size = copy.size;
        max = copy.max;
        path = copy.path;
        magic = copy.magic;

        RGBPixels = new Color*[copy.width];
        for(int i = 0; i < copy.height; i++)
                RGBPixels[i] = new Color[copy.height];
        for(int h = 0; h < copy.height; h++)
                for(int w = 0; w < copy.width; w++)
                        RGBPixels[h][w] = copy.RGBPixels[h][w];

}





