#pragma once
#include "matrix.h"

class Layer {
public:
    virtual ~Layer() = default;
    virtual Matrix forward(const Matrix& input) = 0;
    virtual Matrix backward(const Matrix& gradientOutput) = 0;
    virtual void updateWeights(float learningRate) {}
};
