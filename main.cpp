#include <iostream>
#include "matrix.h"     
int main(){

    Matrix a(5,5);
    Matrix b(6,5);

    a.setRandomVal(0,10);
    b.setRandomVal(0,10);

    std::cout << a << std::endl;
    std::cout << b << std::endl;

    Matrix c = b*a;

    std::cout << c << std::endl;
    return 0;
}