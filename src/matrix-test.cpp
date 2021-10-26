#include <iostream>
#include "include/MatrixLibrary.h"
#include "include/utils/MatrixUtils.h"

int main()
{
    std::cout << "Matrix 4x8 with all zeros.\n";
    MatrixLibrary::Matrix A = MatrixLibrary::Zeros(4, 8);
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
    B.setRow(1, B.getRow(2));
    B.printMatrix();

    std::cout << "Multiply the previous 4x4 modified identity matrix by itself.\n";
    MatrixLibrary::Multiply(B, B).printMatrix();

    std::cout << "Dot product of two vectors [1,2,3,4] and [4,3,2,1]\n";
    std::vector<double> v1 = {1, 2, 3, 4};
    std::vector<double> v2 = {4, 3, 2, 1};
    std::cout << MatrixLibrary::Utils::dotProduct(v1, v2) << "\n";

    MatrixLibrary::Matrix M = MatrixLibrary::Matrix({{1, 2, 3},
                                                     {4, 5, 6},
                                                     {7, 8, 9}});
    MatrixLibrary::Multiply(3, M).printMatrix();
    std::cout << MatrixLibrary::areEqual(M, M) << "\n";
    std::cout << MatrixLibrary::areEqual(M, MatrixLibrary::Multiply(3, M)) << "\n";
    std::cout << MatrixLibrary::areEqual(M, A) << "\n";

    MatrixLibrary::Transpose(A).printMatrix();

    MatrixLibrary::Utils::removeRow(M, 1).printMatrix();

    MatrixLibrary::Utils::removeColumn(M, 1).printMatrix();

    MatrixLibrary::Utils::removeRowAndColumn(M, 0, 1).printMatrix();

    std::cout << "\n\nMatrica A1 \n";
    MatrixLibrary::Matrix A1 = MatrixLibrary::Matrix({{2, 2, 3, 1},
                                                      {-3, 3, 1, 5},
                                                      {0, 0, 3, 0},
                                                      {-1, 0, 0, 2}});
    A1.printMatrix();

    std::cout << "\n\nDeterminanta matrice A1: ";
    std::cout << MatrixLibrary::Det(A1) << "\n";

    return 0;
}