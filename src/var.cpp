#include "var.hpp"
#include <iostream>

Var::Var(double v, double d) : value(v), derivative(d), grad(0.0), backward(nullptr) {}

double Var::getValue() const {
    return value;
}

double Var::getDerivative() const {
    return derivative;
}

void Var::setValue(double v) {
    value = v;
}

void Var::setDerivative(double d) {
    derivative = d;
}

void Var::addGrad(double g) {
    grad += g;
}

double Var::getGrad() const {
    return grad;
}

void Var::setBackward(std::function<void()> func) {
    backward = func;
}

void Var::runBackward() {
    if (backward) {
        backward();
    }
    for (Var* child : children) {
        child->addGrad(grad);
        child->runBackward();
    }
    derivative += grad;
    grad = 0.0;
}
