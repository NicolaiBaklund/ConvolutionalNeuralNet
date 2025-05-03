#include "convLayer.h"

ConvLayer::ConvLayer(long height, long width, long kernelSize, long stride, long depth)
    : height(height), width(width), kernelSize(kernelSize), stride(stride), depth(depth)
{
    if((height - kernelSize)%stride != 0){
        throw std::invalid_argument("Incompatible stride lenght");
    }
    if((width - kernelSize)%stride != 0){
        throw std::invalid_argument("Incompatible stride lenght");
    }
    for(int i = 0; i < depth; i++){
        kernels.emplace_back(Matrix(kernelSize,kernelSize));
        kernels.at(i).setRandomVal(-0.1, 0.1);
    }
    biases.resize(depth);
}

double getFeature(const Matrix& input, const Matrix& kernel, int indexRow, int indexCol, double bias){
    double sum;
    for(int i = 0; i < kernel.getRows(); i++){
        for(int j = 0; j < kernel.getCols(); j++){

        }
    }
}

std::vector<Matrix> ConvLayer::forward(const std::vector<Matrix>& input){
    std::vector<Matrix> output;
    output.reserve(depth);
    int outputHeight = (height - kernelSize)/stride + 1;
    int outputWidth = (width - kernelSize)/stride + 1;

    for (int k = 0; k < depth; k++){
        Matrix featureMap(outputHeight, outputWidth);
        for (long i = 0; i < outputHeight; i++){
            for (long j = 0; j < outputWidth; j++){
                featureMap.at(i, j) = getFeature(input.at(0), kernels.at(k), i, j);
            }
        }
    }
}