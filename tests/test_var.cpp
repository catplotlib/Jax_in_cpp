#include "var.hpp"
#include "operations.hpp"  // Make sure to include this
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

// Test adding to the gradient
TEST(VarTest, GradientAddition) {
    Var v(3.0, 1.0);
    v.addGrad(5.0);
    EXPECT_DOUBLE_EQ(v.getGrad(), 5.0);

    v.addGrad(2.0);
    EXPECT_DOUBLE_EQ(v.getGrad(), 7.0);  // Check cumulative addition
}

// Test backward function setting and gradient propagation
TEST(VarTest, BackwardFunction) {
    Var x(2.0, 1.0);
    Var y(3.0, 0.0);

    Var z = add(x, y);  // z = x + y
    z.setBackward([&]() {  // Custom backward function for testing
        x.addGrad(z.getGrad());
        y.addGrad(z.getGrad());
    });

    // Simulate backward computation
    z.addGrad(1.0);  // Typically, we would seed with 1.0
    z.runBackward();

    EXPECT_DOUBLE_EQ(x.getGrad(), 1.0);
    EXPECT_DOUBLE_EQ(y.getGrad(), 1.0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
