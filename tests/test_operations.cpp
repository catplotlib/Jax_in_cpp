#include "var.hpp"
#include "operations.hpp"
#include <gtest/gtest.h>

// Test addition operation for both forward and backward computations
TEST(OperationTest, Addition) {
    Var a(1.0, 4.0);
    Var b(3.0, 2.0);
    Var result = add(a, b);

    EXPECT_DOUBLE_EQ(result.getValue(), 4.0); // 1.0 + 3.0
    EXPECT_DOUBLE_EQ(result.getDerivative(), 6.0); // 4.0 + 2.0

    // Simulate backward computation
    result.addGrad(1.0); // Typically, we seed with 1.0
    result.runBackward();
    EXPECT_DOUBLE_EQ(a.getGrad(), 1.0);
    EXPECT_DOUBLE_EQ(b.getGrad(), 1.0);
}

// Test multiplication operation for both forward and backward computations
TEST(OperationTest, Multiplication) {
    Var a(2.0, 3.0); // 2.0 with derivative 3.0
    Var b(4.0, 1.0); // 4.0 with derivative 1.0
    Var result = multiply(a, b);

    EXPECT_DOUBLE_EQ(result.getValue(), 8.0); // 2.0 * 4.0
    EXPECT_DOUBLE_EQ(result.getDerivative(), 14.0); // Correct expected derivative

    // Simulate backward computation
    result.addGrad(1.0); // Seed with 1.0 for the backward pass
    result.runBackward();
    EXPECT_DOUBLE_EQ(a.getGrad(), 4.0);  // Gradient contribution from b (4.0 * 1)
    EXPECT_DOUBLE_EQ(b.getGrad(), 2.0);  // Gradient contribution from a (2.0 * 1)
}

// int main(int argc, char **argv) {
//     ::testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }
