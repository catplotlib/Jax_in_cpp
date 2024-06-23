#include "var.hpp"
#include "operations.hpp"
#include <iostream>
#include <cmath>  

int main() {
    Var x(1.0, 1.0);  // x = 1, dx/dx = 1 
    Var y(2.0, 0.0);  // y = 2, dy/dx = 0 

    Var xSquared = multiply(x, x);  // x^2
    Var sumXPlusY = add(x, y);  // x + y

    Var sineOfSum = sin(sumXPlusY);  // sin(x + y)

    Var sumXY = add(xSquared, y);  // x^2 + y
    Var z = multiply(sumXY, sineOfSum);  // (x^2 + y) * sin(x + y)

    std::cout << "z = " << z.getValue() << ", derivative = " << z.getDerivative() << std::endl;

    std::cout << "\n--- Forward Computation ---" << std::endl;
    std::cout << "Function z = (x^2 + y) * sin(x + y)" << std::endl;
    std::cout << "At x = " << x.getValue() << ", y = " << y.getValue() << std::endl;
    std::cout << "z = " << z.getValue() << std::endl;
    std::cout << "dz/dx (partial derivative of z with respect to x) = " << z.getDerivative() << std::endl;

    std::cout << "\n--- Running Backward Computation ---" << std::endl;
    z.setBackward([&]() {
        sumXY.addGrad(sineOfSum.getValue() * z.getGrad());
        sineOfSum.addGrad(sumXY.getValue() * z.getGrad());
        std::cout << "Backward of z, sumXY grad: " << sumXY.getGrad() << ", sineOfSum grad: " << sineOfSum.getGrad() << std::endl;
        sumXY.runBackward();
        sineOfSum.runBackward();
    });
    sumXY.setBackward([&]() {
        xSquared.addGrad(sumXY.getGrad());
        y.addGrad(sumXY.getGrad());
        std::cout << "Backward of sumXY - xSquared's new grad: " << xSquared.getGrad() << ", y's new grad: " << y.getGrad() << std::endl;
        xSquared.runBackward();
    });
    xSquared.setBackward([&]() {
        x.addGrad(2 * x.getValue() * xSquared.getGrad());
        std::cout << "Backward computation for xSquared - x's new gradient: " << x.getGrad() << std::endl;
    });
    sineOfSum.setBackward([&]() {
        sumXPlusY.addGrad(std::cos(sumXPlusY.getValue()) * sineOfSum.getGrad());
        std::cout << "Backward computation for sineOfSum - sumXPlusY's new grad: " << sumXPlusY.getGrad() << std::endl;
        sumXPlusY.runBackward();
    });
    sumXPlusY.setBackward([&]() {
        x.addGrad(sumXPlusY.getGrad());
        y.addGrad(sumXPlusY.getGrad());
        std::cout << "Backward of sumXPlusY, x's new grad: " << x.getGrad() << ", y's new grad: " << y.getGrad() << std::endl;
    });
    z.addGrad(1.0);
    z.runBackward();
    
    std::cout << "Backward computation finished." << std::endl;
    std::cout << "\n--- Backward Computation Results ---" << std::endl;
    std::cout << "Gradient df/dx at x = " << x.getGrad() << std::endl;
    std::cout << "Gradient df/dy at y = " << y.getGrad() << std::endl;

    return 0;
}


