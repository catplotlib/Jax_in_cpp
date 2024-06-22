// test_var.cpp
#include "var.hpp"
#include <gtest/gtest.h>

// Test the constructor of the Var class
TEST(VarTest, Constructor) {
    Var v(5.0, 1.0);
    EXPECT_DOUBLE_EQ(v.getValue(), 5.0);
    EXPECT_DOUBLE_EQ(v.getDerivative(), 1.0);
}

// Test the setters and getters
TEST(VarTest, SettersAndGetters) {
    Var v;
    v.setValue(10.0);
    v.setDerivative(2.0);

    EXPECT_DOUBLE_EQ(v.getValue(), 10.0);
    EXPECT_DOUBLE_EQ(v.getDerivative(), 2.0);
}

// int main(int argc, char **argv) {
//     ::testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }
