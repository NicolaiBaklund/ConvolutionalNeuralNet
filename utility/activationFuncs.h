#pragma once
#include "matrix.h"

double sigmoid(double x);

double reLu(double x);

Matrix softMax(const Matrix& input);