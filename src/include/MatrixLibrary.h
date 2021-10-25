#ifndef MATRIX_LIB_H
#define MATRIX_LIB_H

#include "MatrixDefinitions.h"

namespace MatrixLibrary
{
    Matrix Eye(int size);

    Matrix Sum(Matrix A, Matrix B);
    
    Matrix Multiply(Matrix A, Matrix B);

}
#endif