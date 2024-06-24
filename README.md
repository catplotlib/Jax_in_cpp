# Automatic Differentiation in C++
This project demonstrates automatic differentiation using C++ to compute the value and derivative of mathematical functions. Automatic differentiation (AD) is a technique that allows us to evaluate the derivative of a function specified by a computer program efficiently and accurately.

<img width="521" alt="Screenshot 2024-06-23 at 9 27 19 PM" src="https://github.com/catplotlib/Jax_in_cpp/assets/61319491/b14848ba-00e0-4193-b992-1133a46b14ff">

# What is AD?
Automatic differentiation is a computational technique used to find the derivative of functions. Unlike symbolic differentiation, which manipulates mathematical expressions, or numerical differentiation, which approximates derivatives using finite differences, AD works at the level of computer programs by applying the chain rule of calculus at every step of a given computation.

This project provides a basic implementation of AD in C++ by defining a class for variables and implementing operations that support both forward and backward propagation.

# How It Works

## Forward Propagation
Forward propagation computes the value of the function and its derivative with respect to the input variables as the operations are performed. Each variable holds its value and derivative, which are updated as operations are applied.

- Initialize Variables:
Each variable is initialized with a value and a derivative. The derivative of the independent variable with respect to itself is set to 1, while the derivatives with respect to other variables are set to 0.
- Compute Intermediate Values:
Perform operations like addition, multiplication, and trigonometric functions on the variables. Each operation updates the value and derivative of the resulting variable using the chain rule.

## Backward Propagation
Backward propagation calculates the gradient (derivative) of the output with respect to each input by traversing the computation graph in reverse order. This is useful for optimization problems, such as training neural networks, where we need the gradients to update parameters.

- Set Up Backward Functions:
For each operation, define a backward function that specifies how to propagate the gradient backward through that operation. This function updates the gradient of the input variables based on the gradient of the output variable.
- Propagate Gradients:
Starting from the final output, call the backward functions to propagate the gradient through the computation graph. Each variable accumulates the gradient contributions from all operations that depend on it.

# File Structure
## var.cpp
The var.cpp file defines the Var class, which represents a variable in the computation graph. This class includes methods for both forward and backward propagation.

- Constructor: Initializes the variable's value, derivative, and gradient.
- Getters/Setters: Methods to access and modify the variable's value, derivative, and gradient.
- Gradient Management: Methods to accumulate and retrieve gradients during backpropagation.
- Backward Function Management: Methods to set and execute functions that propagate gradients through the computation graph.
- Children Management: Methods to manage dependencies in the computational graph, ensuring proper gradient propagation.

## operations.cpp
The operations.cpp file implements basic mathematical operations on Var objects. Each operation computes the value and derivative during forward propagation and sets up the backward function to handle gradient propagation.

- multiply: Multiplies two variables and computes the product's value and derivative.
- add: Adds two variables and computes the sum's value and derivative.
- sin: Applies the sine function to a variable and computes the resulting value and derivative.
- cos: Applies the cosine function to a variable and computes the resulting value and derivative.

# Running the Code
## Using Makefile
A Makefile is provided with the project. To compile and run the code, follow these steps:

- Compile the Code:

```bash
make
```

# Run the Compiled Program:

```bash
./sin_example
```

# Expected Output
The program will print the value of the function and the derivatives with respect to each input variable. This demonstrates the successful implementation of both forward and backward propagation.

By constructing a computation graph and using both forward and backward propagation, the system accurately computes the value and derivatives of complex functions. 

