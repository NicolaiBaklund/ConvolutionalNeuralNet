#pragma once
#include <vector>
#include "layer.h"
#include "denseLayer.h"
#include "convLayer.h"

class Network {
private:
    std::vector<Layer*> layers;


public:
    Network();
    Matrix feedForward(const Matrix& input);
};