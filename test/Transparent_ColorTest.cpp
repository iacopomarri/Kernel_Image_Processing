//
// Created by iacopo on 26/02/18.
//

#include "gtest/gtest.h"

#include "../Transparent_Color.h"

TEST(Transparent_Color, DefaultConstructor) {
    Transparent_Color tc;

    ASSERT_EQ(0, tc.getR());
    ASSERT_EQ(0, tc.getG());
    ASSERT_EQ(0, tc.getB());
    ASSERT_EQ(0, tc.getA());
    std::cout<<"TransparentColor"<<std::endl;
}