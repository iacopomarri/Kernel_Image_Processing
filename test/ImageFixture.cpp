//
// Created by iacopo on 24/02/18.
//

#include "gtest/gtest.h"
#include "../Image.h"

class ImageSuite : public ::testing::Test {
protected:
    virtual void SetUp(){
        i.setPath("");
        i.setMax(0);
        i.setWidth(0);
        i.setHeight(0);
        i.setMagic("");
        i.setSize(0);
    }
    Image i;
};

TEST_F(ImageSuite, TestLoad){
    i.loadImage("../../test/test.ppm");
    cout<<i.getPath()<<endl;

    //magic= P6, w=512, h=512, max=255, size=786432

    ASSERT_EQ("P6",i.getMagic());
    ASSERT_EQ(512,i.getWidth());
    ASSERT_EQ(512,i.getHeight());
    ASSERT_EQ(255,i.getMax());
    ASSERT_EQ(786432,i.getSize());

    std::cout<<"image testload  "<<std::endl;
}

