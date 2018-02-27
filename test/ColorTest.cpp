//
// Created by iacopo on 26/02/18.
//

#include "gtest/gtest.h"

#include "../Color.h"

TEST(Color, DefaultConstructor) {
    Color c;

    ASSERT_EQ(0, c.getR());
    ASSERT_EQ(0, c.getG());
    ASSERT_EQ(0, c.getB());
    std::cout<<"Color"<<std::endl;
}