// test_operations.cpp
#include "var.hpp"
#include "operations.hpp"
#include <gtest/gtest.h>

// Test addition operation
TEST(OperationTest, Addition) {
    Var a(1.0, 4.0);
    Var b(3.0, 2.0);
    Var result = add(a, b);

    EXPECT_DOUBLE_EQ(result.getValue(), 4.0); // 1.0 + 3.0
    EXPECT_DOUBLE_EQ(result.getDerivative(), 6.0); // 4.0 + 2.0
}

// Test multiplication operation
TEST(OperationTest, Multiplication) {
    Var a(2.0, 3.0); // 2.0 with derivative 3.0
    Var b(4.0, 1.0); // 4.0 with derivative 1.0
    Var result = multiply(a, b);

    EXPECT_DOUBLE_EQ(result.getValue(), 8.0); // 2.0 * 4.0
    EXPECT_DOUBLE_EQ(result.getDerivative(), 14.0); // Correct expected derivative
}


// int main(int argc, char **argv) {
//     ::testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }
