#include "poolLayer.h"

Matrix PoolLayer::maxPool(int poolSize, int stride, const Matrix &map)
{
    if (!(((map.getCols()-poolSize) % stride == 0) || ((map.getRows()-poolSize) % stride == 0))){
        throw std::runtime_error("Stride incompatible with poolsize/inputsize");
    }
}

std::vector<Matrix> PoolLayer::forward(const std::vector<Matrix> &input)
{
    std::vector<Matrix> output;
    
    for(auto map : input)


    int inputRows = output.at(0).getRows(); //Size of cols(num of rows is size of a cols)
    int inputCols = output.at(0).getCols(); //Size of rows
    int inputLen = output.size();
    int flattenSize = inputRows * inputCols * inputSize;
    Matrix flattened(flattenSize, 1);

    for(int k = 0; k < inputLen; k++){
        for(int i = 0; i < inputRows; i++){
            for(int j = 0; j < inputCols; j++){
                flattened.at(k * inputCols*inputRows + i * inputCols + j) = output.at(k).at(i, j);
            }
        }
    }
}