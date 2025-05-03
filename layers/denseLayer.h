#pragma once
#include "layer.h"
#include "matrix.h"

class DenseLayer : public Layer{
private:
    Matrix weights, bias, inputCache;
    std::string activation;
public:
    DenseLayer(long inputSize, long outputSize, std::string activation);
    
    std::vector<Matrix> forward(const std::vector<Matrix>& input) override;
    Matrix backward(const Matrix& gradientOutput) override;
    void updateWeights(double learningRate);
    void updateBias(double learningRate);

};