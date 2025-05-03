#pragma once
#include "layer.h"
#include "matrix.h"

class DenseLayer : public Layer{
private:
    Matrix weights, bias, inputCache;
public:
    DenseLayer(long inputSize, long outputSize);
    
    Matrix forward(const Matrix& input) override;
    Matrix backward(const Matrix& gradientOutput) override;
    void updateWeights(double learningRate);

};