// operations.cpp
#include "var.hpp"

// Addition of two Var objects
Var add(const Var& a, const Var& b) {
    // The derivative of the sum is the sum of the derivatives
    double result_value = a.getValue() + b.getValue();
    double result_derivative = a.getDerivative() + b.getDerivative();
    return Var(result_value, result_derivative);
}

// Multiplication of two Var objects
Var multiply(const Var& a, const Var& b) {
    double result_value = a.getValue() * b.getValue();
    double result_derivative = a.getDerivative() * b.getValue() + a.getValue() * b.getDerivative();
    return Var(result_value, result_derivative);
}

