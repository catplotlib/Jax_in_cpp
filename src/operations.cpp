#include "var.hpp"
#include "operations.hpp"
#include <iostream>
#include <cmath> 


Var multiply(Var& a, Var& b) {
    Var result(a.getValue() * b.getValue(), a.getDerivative() * b.getValue() + b.getDerivative() * a.getValue());
    result.setBackward([&]() { 
        a.addGrad(b.getValue() * result.getGrad());
        b.addGrad(a.getValue() * result.getGrad());
    });
    return result;
}

Var add(Var& a, Var& b) {
    Var result(a.getValue() + b.getValue(), a.getDerivative() + b.getDerivative());
    result.setBackward([&]() { 
        a.addGrad(result.getGrad());
        b.addGrad(result.getGrad());
    });
    return result;
}

Var sin(Var& a) {
    Var result(std::sin(a.getValue()), std::cos(a.getValue()) * a.getDerivative());
    result.setBackward([&]() {
        a.addGrad(std::cos(a.getValue()) * result.getGrad());
    });
    return result;
}

Var cos(Var& a) {
    Var result(std::cos(a.getValue()), -std::sin(a.getValue()) * a.getDerivative());
    result.setBackward([&]() { 
        a.addGrad(-std::sin(a.getValue()) * result.getGrad());
    });
    return result;
}