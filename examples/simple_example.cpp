#include "var.hpp"
#include "operations.hpp"
#include <iostream>

int main() {
    // Initialize variables
    Var x(3.0, 1.0);  // x = 3, dx/dx = 1
    Var y(4.0, 0.0);  // y = 4, dy/dx = 0 (since y is treated as constant w.r.t x)

    // Compute x^2
    Var xSquared = multiply(x, x);  // x^2

    // Compute x^2 + y
    Var f = add(xSquared, y);       // x^2 + y

    // Output the value and derivative of the function
    std::cout << "Function f(x, y) = x^2 + y" << std::endl;
    std::cout << "At x = " << x.getValue() << ", y = " << y.getValue() << std::endl;
    std::cout << "f(x, y) = " << f.getValue() << std::endl;
    std::cout << "df/dx (partial derivative of f with respect to x) = " << f.getDerivative() << std::endl;

    return 0;
}
