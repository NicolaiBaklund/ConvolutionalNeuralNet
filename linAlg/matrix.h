#pragma once
#include "utils.h"
#include "activationFuncs.h"
#include <format>
#include <iostream>
#include <vector>

class Matrix{
protected:
    long rows;
    long cols;
    std::vector<double> data;
public:
    //constructors
    Matrix(long rows, long cols);
    Matrix(const Matrix& m);
    Matrix() = default;
    Matrix& operator=(const Matrix& m2);
    //Move functionality
    Matrix(Matrix && other) noexcept;
    Matrix& operator=(Matrix&& other) noexcept;

    friend std::ostream& operator<<(std::ostream& os, Matrix& m);
    long getRows() const {return rows;}
    long getCols() const {return cols;}
    long getMaxRow() const;
    double& at(long i, long j) {return data[i * cols + j];}
    double at(long i, long j) const {return data[i * cols + j];}
    Matrix operator*(const Matrix& m2) const;
    Matrix operator*(double scalar) const;
    Matrix operator+(const Matrix& m2) const;
    Matrix operator+(double scalar) const;
    Matrix operator-(const Matrix& m2) const {return *this+(m2*(-1));};
    Matrix operator-(double scalar) const {return *this+(-scalar);}
    void map(double (*f)(double));
    Matrix map(double (*f)(double)) const;
    void setRandomVal(double lowerBound, double upperBound);
    Matrix transposed() const;
    Matrix hadamard(const Matrix& m2) const;
    Matrix activate(std::string func) const;
};