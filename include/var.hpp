#ifndef VAR_HPP
#define VAR_HPP

#include <functional>
#include <vector>

class Var {
private:
    double value;
    double derivative;
    double grad;
    std::function<void()> backward;
    std::vector<Var*> children;

public:
    Var(double v = 0.0, double d = 0.0);
    double getValue() const;
    double getDerivative() const;
    void setValue(double v);
    void setDerivative(double d);
    void addGrad(double g);
    double getGrad() const;
    void setBackward(std::function<void()> func);
    void runBackward();
};

#endif // VAR_HPP