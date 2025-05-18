#pragma once 
#include "layer.h"
#include "matrix.h"
#include <vector>

class ConvLayer : public Layer {
private:
    int height, width, kernelSize, stride, depth;
    std::vector<Matrix> kernels;
    std::vector<double> biases;
public:
    ConvLayer(int height, int width, int kernelSize, int stride, int depth);
    double getFeature(const Matrix& input, const Matrix& kernel, int indexRow, int indexCol, double bias);
    std::vector<Matrix> forward(const std::vector<Matrix>& input) override;


};