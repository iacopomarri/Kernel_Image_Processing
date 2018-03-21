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


