#include "var.hpp"
#include "operations.hpp"
#include <iostream>

int main() {
    Var x(3.0, 1.0);  // x = 3, dx/dx = 1 (for forward mode)
    Var y(4.0, 0.0);  // y = 4, dy/dx = 0 (since y is treated as constant w.r.t x)

    Var xSquared = multiply(x, x);  // x^2
    std::cout << "xSquared = " << xSquared.getValue() << ", derivative (2*x) = " << xSquared.getDerivative() << std::endl;

    Var f = add(xSquared, y);  // x^2 + y
    std::cout << "f(x, y) = " << f.getValue() << ", derivative (df/dx = 2*x, df/dy = 1) = " << f.getDerivative() << std::endl;

    std::cout << "\n--- Forward Computation ---" << std::endl;
    std::cout << "Function f(x, y) = x^2 + y" << std::endl;
    std::cout << "At x = " << x.getValue() << ", y = " << y.getValue() << std::endl;
    std::cout << "f(x, y) = " << f.getValue() << std::endl;
    std::cout << "df/dx (partial derivative of f with respect to x) = " << f.getDerivative() << std::endl;

    std::cout << "\n--- Running Backward Computation ---" << std::endl;
    f.setBackward([&]() {
        xSquared.addGrad(f.getGrad());
        y.addGrad(f.getGrad());
        xSquared.runBackward();
    });
    xSquared.setBackward([&]() {
        x.addGrad(2 * x.getValue() * xSquared.getGrad());
        std::cout << "Backward computation for xSquared - x's new gradient: " << x.getGrad() << std::endl;
    });
    f.addGrad(1.0);
    f.runBackward();

    std::cout << "Backward computation finished." << std::endl;
    std::cout << "\n--- Backward Computation Results ---" << std::endl;
    std::cout << "Gradient df/dx at x = " << x.getGrad() << std::endl;
    std::cout << "Gradient df/dy at y = " << y.getGrad() << std::endl;

    return 0;
}
