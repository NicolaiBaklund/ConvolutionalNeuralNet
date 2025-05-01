#include "utils.h"

//Generates random double value within given bounds
double randDouble(double lowerBound, double upperBound){
    std::random_device rnd;
    std::default_random_engine generator(rnd());
    std::uniform_real_distribution<double> dist(lowerBound, upperBound);

    return dist(generator);
}