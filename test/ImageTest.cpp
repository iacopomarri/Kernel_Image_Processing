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

    i.loadImage("test.ppm");
    i.effect(e.getEdgedetection());
    ASSERT_EQ(510, i.getWidth());
    ASSERT_EQ(510, i.getHeight());
    std::cout<<"Image effect"<<std::endl;
}

