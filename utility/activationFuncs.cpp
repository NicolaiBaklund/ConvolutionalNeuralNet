#include "activationFuncs.h"

double sigmoid(double x) {

    return 1/(exp(-x) + 1);
}

double reLu(double x) {
   return (x < 0) ? 0 : x; 
}


//Softmax rowwise to use on output layer of net
Matrix softmax(const Matrix& input) {
    Matrix output = input;
    for (long i = 0; i < input.getRows(); i++) {
        double maxVal = input.at(i, 0);
        for (long j = 1; j < input.getCols(); j++)
            maxVal = std::max(maxVal, input.at(i, j));

        double sum = 0.0;
        for (long j = 0; j < input.getCols(); j++) {
            double e = std::exp(input.at(i, j) - maxVal);
            output.at(i, j) = e;
            sum += e;
        }
        for (long j = 0; j < input.getCols(); j++)
            output.at(i, j) /= sum;
    }
    return output;
}