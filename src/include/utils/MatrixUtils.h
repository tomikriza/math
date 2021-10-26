#ifndef MATRIX_UTILS_H
#define MATRIX_UTILS_H

#include "MatrixDefinitions.h"

namespace MatrixLibrary::Utils
{

    bool MatchingDimensions(Matrix A, Matrix B);
    bool isSquareMatrix(Matrix A);
    double dotProduct(std::vector<double> v1, std::vector<double> v2);

    Matrix removeRow(Matrix A, int row_idx);
    Matrix removeColumn(Matrix A, int col_idx);
    Matrix removeRowAndColumn(Matrix A, int row_idx, int col_idx);

    
}

#endif