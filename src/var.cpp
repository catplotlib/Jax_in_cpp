// var.cpp
#include "var.hpp"

// Constructor to initialize the value and derivative
Var::Var(double v, double d) : value(v), derivative(d) {}

// Getter for the value
double Var::getValue() const {
    return value;
}

// Getter for the derivative
double Var::getDerivative() const {
    return derivative;
}

// Setter for the value
void Var::setValue(double v) {
    value = v;
}

// Setter for the derivative
void Var::setDerivative(double d) {
    derivative = d;
}
