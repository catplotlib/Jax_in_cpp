// var.hpp
#ifndef VAR_HPP
#define VAR_HPP

class Var {
private:
    double value;        // The value of the variable
    double derivative;   // The derivative of the variable

public:
    // Constructor
    Var(double v = 0.0, double d = 0.0);

    // Getters
    double getValue() const;
    double getDerivative() const;

    // Setters
    void setValue(double v);
    void setDerivative(double d);
};

#endif // VAR_HPP
