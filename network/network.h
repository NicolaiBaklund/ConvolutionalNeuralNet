#pragma once
#include <vector>
#include "layer.h"
#include "denseLayer.h"
#include "convLayer.h"

class Network {
private:
    std::vector<Layer*> layers;
    double learningRate;
    int inputLayerRows, inputLayerCols, outputLayerSize;
    std::vector<std::string> activationFuncs;

public:
    Network(int inputLayerRows, int inputLayerCols, std::vector<int> hiddenLayerSizes, int outputLayerSize, std::vector<std::string> activationFuncs, bool convolutional = false);
    Matrix feedForward(const Matrix& input);
};