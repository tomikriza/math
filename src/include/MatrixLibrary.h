#ifndef MATRIX_LIB_H
#define MATRIX_LIB_H

#include "MatrixDefinitions.h"

namespace MatrixLibrary
{
    Matrix Zeros(int row_dim, int col_dim);
    Matrix Ones(int row_dim, int col_dim);
    Matrix Eye(int size);

    bool areEqual(Matrix A, Matrix B);

    Matrix Sum(Matrix A, Matrix B);
    
    Matrix Multiply(Matrix A, Matrix B);
    Matrix Multiply(double scalar, Matrix A);
    Matrix Multiply(Matrix M, double scalar);

    Matrix Transpose(Matrix A);
    
    double Minor(Matrix A, int row_idx, int col_idx);

    double Det(Matrix A);

}
#endif