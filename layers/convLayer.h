#pragma once 
#include "layer.h"
#include "matrix.h"
#include <vector>

class ConvLayer : public Layer {
private:
    long height, width, kernelSize, stride, depth;
    std::vector<Matrix> kernels;
    std::vector<double> biases;
public:
    ConvLayer(long height, long width, long kernelSize, long stride, long depth);
    double getFeature(const Matrix& input, const Matrix& kernel, int indexRow, int indexCol, double bias);
    std::vector<Matrix> forward(const std::vector<Matrix>& input) override;


};