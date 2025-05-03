#pragma once
#include "matrix.h"

class Layer {
public:
    virtual ~Layer() = default;
    virtual std::vector<Matrix> forward(const std::vector<Matrix>& input) = 0;
    virtual Matrix backward(const Matrix& gradientOutput) = 0;
};
