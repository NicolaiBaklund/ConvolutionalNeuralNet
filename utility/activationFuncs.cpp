#include "activationFuncs.h"

double sigmoid(double x) {

    return 1/(exp(-x) + 1);
}

double reLu(double x) {
   return (x < 0) ? 0 : x; 
}

double leakyReLu(double x){
    return (x < 0) ? 0.1*x : x;
}

double dReLu(double x)
{
    return (x < 0) ? 0: 1;
}

double dSigmoid(double x)
{
    double sig = sigmoid(x);
    return sig * (1 - sig);
}
