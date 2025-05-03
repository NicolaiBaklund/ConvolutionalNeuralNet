#include "denseLayer.h"

DenseLayer::DenseLayer(long inputSize, long outputSize, std::string activation) : activation(activation) {
    weights = Matrix(outputSize, inputSize);
    bias = Matrix(outputSize, 1); //TODO: Research proper bias initialization
    //HE-initialization of weights
    double scale = (2.0/sqrt(inputSize));
    weights.setRandomVal(-scale, scale);
}

Matrix DenseLayer::forward(const Matrix &input) {
    return (weights * input + bias).activate(activation);
}

Matrix DenseLayer::backward(const Matrix &gradientOutput)
{
    return Matrix();
}
