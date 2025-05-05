#include "denseLayer.h"
#include "convLayer.h"

DenseLayer::DenseLayer(long inputSize, long outputSize, std::string activation) : activation(activation) {
    weights = Matrix(outputSize, inputSize);
    bias = Matrix(outputSize, 1); //TODO: Research proper bias initialization
    //HE-initialization of weights
    double scale = (2.0/sqrt(inputSize));
    weights.setRandomVal(-scale, scale);
}


std::vector<Matrix> DenseLayer::forward(const std::vector<Matrix> &input) {
    inputCache = (weights * input.at(0) + bias);
    return std::vector<Matrix> {(weights * input.at(0) + bias).activate(activation)};
}

Matrix DenseLayer::backward(const Matrix &gradientOutput)
{
    
}
