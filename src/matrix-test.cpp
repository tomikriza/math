#include <iostream>
#include "include/MatrixLibrary.h"

int main()
{
    std::cout<< "Matrix 4x8 with all zeros.\n";
    MatrixLibrary::Matrix A = MatrixLibrary::Matrix(4,8);
    A.printMatrix();

    std::cout<< "Sum of two 4x4 eye matrices.\n";
    MatrixLibrary::Matrix B = MatrixLibrary::Eye(4);

    MatrixLibrary::Sum(B,B).printMatrix();

    return 0;
}