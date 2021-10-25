#ifndef MATRIX_DEFINITONS_H
#define MATRIX_DEFINITONS_H

#include <iostream>
#include <vector>

namespace MatrixLibrary
{
    struct matrix_dim
    {
        int rows, cols;
    };

    class Matrix
    {
    public:
        Matrix(int row_dim, int col_dim);
        Matrix(std::vector<std::vector<double>>table);

        double getElement(int row_idx, int col_idx);
        void setElement(int row_idx, int col_idx, double value);

        std::vector<double> getRow(int row_idx);
        std::vector<double> getColumn(int col_idx);
        void setRow(int row_idx, std::vector<double> newRow);
        void setColumn(int col_idx, std::vector<double> newColumn);

        void printMatrix();

        matrix_dim dim;

        std::vector<std::vector<double>> data;
    };
}

#endif