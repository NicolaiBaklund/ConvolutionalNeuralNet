#include "convLayer.h"

ConvLayer::ConvLayer(int height, int width, int kernelSize, int stride, int depth)
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

//Sum of element-wise product of a matrix and a kernel
double ConvLayer::getFeature(const Matrix& input, const Matrix& kernel, int indexRow, int indexCol, double bias){
    double sum = 0.0;
    for(int i = 0; i < kernel.getRows(); i++){
        for(int j = 0; j < kernel.getCols(); j++){
            sum += kernel.at(i,j) * input.at(indexRow + i, indexCol + j);
        }
    }
    return sum;
}

std::vector<Matrix> ConvLayer::forward(const std::vector<Matrix>& input){
    std::vector<Matrix> output;
    output.reserve(depth);
    int outputHeight = (height - kernelSize)/stride + 1;
    int outputWidth = (width - kernelSize)/stride + 1;

    for (int k = 0; k < depth; k++){
        Matrix featureMap(outputHeight, outputWidth);
        for (int i = 0; i < outputHeight; i++){
            for (int j = 0; j < outputWidth; j++){
                featureMap.at(i, j) = getFeature(input.at(0), kernels.at(k), i, j);
            }
        }
        output.push_back(featureMap);
    }
}