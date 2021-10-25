#include <iostream>
#include "include/MatrixLibrary.h"
#include "include/utils/MatrixUtils.h"

int main()
{
    std::cout << "Matrix 4x8 with all zeros.\n";
    MatrixLibrary::Matrix A = MatrixLibrary::Matrix(4, 8);
    A.printMatrix();

    std::cout << "Sum of two 4x4 eye matrices.\n";
    MatrixLibrary::Matrix B = MatrixLibrary::Eye(4);
    MatrixLibrary::Sum(B, B).printMatrix();

    std::cout << "Third row (index 2) of 4x4 identity matrix.\n";
    for (int i = 0; i < 4; i++)
    {
        std::cout << B.getRow(2)[i] << " , ";
    }
    std::cout << "\n";

    std::cout << "Second row (index 1) of 4x4 identity matrix.\n";
    for (int i = 0; i < 4; i++)
    {
        std::cout << B.getColumn(1)[i] << " , ";
    }
    std::cout << "\n";

    std::cout << "Set second row (index 1) of 4x4 identity matrix to be equal to the third row (index 2).\n";
    B.setRow(1,B.getRow(2));
    B.printMatrix();

    std::cout<<"Multiply the previous 4x4 modified identity matrix by itself.\n";
    MatrixLibrary::Multiply(B,B).printMatrix();

    std::cout<<"Dot product of two vectors [1,2,3,4] and [4,3,2,1]\n";
    std::vector<double> v1 = {1,2,3,4};
    std::vector<double> v2 = {4,3,2,1};
    std::cout<< MatrixLibrary::Utils::dotProduct(v1,v2)<<"\n";

    return 0;
}