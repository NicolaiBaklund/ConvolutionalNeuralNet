#pragma once
#include "layer.h"
#include "matrix.h"
#include <vector>

class PoolLayer : public Layer {
private:
public:

    Matrix maxPool(int poolSize, int stride, const Matrix& map);
    std::vector<Matrix> forward(const std::vector<Matrix>& input) override;
};