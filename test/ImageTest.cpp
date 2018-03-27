//
// Created by iacopo on 24/02/18.n
//

#include "gtest/gtest.h"

#include "../Image.h"
#include "../Effect.h"


TEST(Image, DefaultConstructor) {
    Image<char> i;

    ASSERT_EQ("null", i.getPath());
    ASSERT_EQ(0, i.getSize());
    ASSERT_EQ(0, i.getMax());
    ASSERT_EQ(0, i.getHeight());
    ASSERT_EQ(0, i.getWidth());
    ASSERT_EQ("null", i.getMagic());
    std::cout<<"DefaultContructor"<<std::endl;
}

TEST(Image, Effect){
    Image<Color> i;
    Effect e;

    i.loadImage("../../test/test.ppm");
    i.effect(e.getEdgedetection());
    //controlla che le dimensioni siamo diminuite di 2
    ASSERT_EQ(510, i.getWidth());
    ASSERT_EQ(510, i.getHeight());
    std::cout<<"Image effect"<<std::endl;
}
TEST(Image, GreyPixel){
    Image<char> i;

    i.loadImage("../../test/test2.pgm");
    i.modifyPixel(1,1, 65);
    ASSERT_EQ(65, i.readPixel(1,1));
}
TEST(Image, RGBPixel){
    Image<Color> i;
    Color pixel;
    pixel.setR(50);
    pixel.setG(50);
    pixel.setB(50);

    i.loadImage("../../test/test.ppm");

    i.modifyPixel(1,1, pixel);
    ASSERT_EQ(50, i.readPixel(1,1).getR());
    ASSERT_EQ(50, i.readPixel(1,1).getG());
    ASSERT_EQ(50, i.readPixel(1,1).getB());
}
TEST(Image, equalOp){
    Image<Color> i;
    Image<Color> i2;

    i.loadImage("../../test/test.ppm"); //baboon 512x512
    i2.loadImage("../../test/test3.ppm"); //stop 99x99

    i2=i;

    for (int k = 0; k < i2.getHeight(); k++)
        for (int h = 0; h < i2.getWidth(); h++) {
            ASSERT_EQ(i2.readPixel(k, h).getR(), i.readPixel(k, h).getR());
            ASSERT_EQ(i2.readPixel(k, h).getG(), i.readPixel(k, h).getG());
            ASSERT_EQ(i2.readPixel(k, h).getB(), i.readPixel(k, h).getB());
        }
}
TEST(Image, copyConstructor){
    Image<Color> i;

    i.loadImage("../../test/test.ppm");
    Image<Color> i2(i);

    for (int k = 0; k < i2.getHeight(); k++)
        for (int h = 0; h < i2.getWidth(); h++) {
            ASSERT_EQ(i2.readPixel(k, h).getR(), i.readPixel(k, h).getR());
            ASSERT_EQ(i2.readPixel(k, h).getG(), i.readPixel(k, h).getG());
            ASSERT_EQ(i2.readPixel(k, h).getB(), i.readPixel(k, h).getB());
        }
}


