//
// Created by iacopo on 24/02/18.n
//

#include "gtest/gtest.h"

#include "../Image.h"
#include "../Effect.h"

TEST(Image, DefaultConstructor) {
    Image* i = new Image();

    ASSERT_EQ("null", i->getPath());
    ASSERT_EQ(0, i->getSize());
    ASSERT_EQ(0, i->getMax());
    ASSERT_EQ(0, i->getHeight());
    ASSERT_EQ(0, i->getWidth());
    ASSERT_EQ("null", i->getMagic());
    std::cout<<"DefaultContructor"<<std::endl;
}

TEST(Image, Effect){
    Image i;
    Effect e;

    i.loadImage("../../test/test.ppm");
    i.effect(e.getEdgedetection());
    ASSERT_EQ(510, i.getWidth());
    ASSERT_EQ(510, i.getHeight());
    std::cout<<"Image effect"<<std::endl;
}
TEST(Image, GreyPixels){
    Image i;

    i.loadImage("../../test/test2.pgm");
    i.modifyGrey(1,1, 65);
    ASSERT_EQ(65, i.readGrey(1,1));
}
TEST(Image, Pixels){
    Image i;

    i.loadImage("../../test/test.ppm");
    i.modifyRGB(1,1, 50, 50, 50);
    ASSERT_EQ(50, i.readRGB(1,1).getR());
    ASSERT_EQ(50, i.readRGB(1,1).getG());
    ASSERT_EQ(50, i.readRGB(1,1).getB());
}


