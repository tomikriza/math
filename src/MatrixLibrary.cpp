#include "include/MatrixLibrary.h"
#include "include/utils/MatrixUtils.h"

namespace MatrixLibrary
{

    Matrix::Matrix(int row_dim, int col_dim)
    {
        dim.rows = row_dim;
        dim.cols = col_dim;

        std::vector<double> row;
        row.assign(dim.cols, 0);

        data.assign(dim.rows, row);
    }

    Matrix::Matrix(std::vector<std::vector<double>>table)
    { //TODO - Check if table is valid
        dim.rows = table.size();
        dim.cols = table[0].size();

        data = table;
    }

    double Matrix::getElement(int row_idx, int col_idx)
    {
        return data[row_idx][col_idx];
    }

    void Matrix::setElement(int row_idx, int col_idx, double value)
    {
        data[row_idx][col_idx] = value;
    }

    std::vector<double> Matrix::getRow(int row_idx)
    {
        return data[row_idx];
    }

    std::vector<double> Matrix::getColumn(int col_idx)
    {
        std::vector<double> column;
        for (int i = 0; i < dim.cols; i++)
        {
            column.push_back(data[i][col_idx]);
        }
        return column;
    }

    void Matrix::setRow(int row_idx, std::vector<double> newRow)
    {
        for (int i = 0; i < dim.cols; i++)
        {
            data[row_idx][i] = newRow[i];
        }
    }

    void Matrix::setColumn(int col_idx, std::vector<double> newColumn)
    {
        for (int i = 0; i < dim.rows; i++)
        {
            data[i][col_idx] = newColumn[i];
        }
    }

    void Matrix::printMatrix()
    {
        std::cout << "-----------------Matrix print------------------\n";
        for (int row_idx = 0; row_idx < dim.rows; row_idx++)
        {
            std::cout << "\n";
            for (int col_idx = 0; col_idx < dim.cols; col_idx++)
            {
                std::cout << data[row_idx][col_idx];
                if (col_idx + 1 < dim.cols)
                {
                    std::cout << " , ";
                }
            }
        }
        std::cout << "\n\n---------------Matrix print end----------------\n";
    }

    Matrix Eye(int size)
    {
        Matrix M = Matrix(size, size);

        for (int row_idx = 0; row_idx < size; row_idx++)
        {
            M.data[row_idx][row_idx] = 1;
        }

        return M;
    }

    Matrix Sum(Matrix A, Matrix B)
    {
        if (Utils::MatchingDimensions(A, B))
        {
            Matrix Result = Matrix(A.dim.rows, A.dim.cols);
            for (int row_idx = 0; row_idx < Result.dim.rows; row_idx++)
            {
                for (int col_idx = 0; col_idx < Result.dim.cols; col_idx++)
                {
                    Result.data[row_idx][col_idx] = A.data[row_idx][col_idx] + B.data[row_idx][col_idx];
                }
            }
            return Result;
        }
        return Matrix(1, 1);
    }

    Matrix Multiply(Matrix A, Matrix B)
    {
        std::vector<std::vector<double>> resultData;
        if (A.dim.cols == B.dim.rows)
        {
            for (int row_idx = 0; row_idx < B.dim.rows; row_idx++)
            {
                std::vector<double> resultRow;
                for (int col_idx = 0; col_idx < A.dim.cols; col_idx++)
                {
                    resultRow.push_back(Utils::dotProduct(A.getRow(row_idx), B.getColumn(col_idx)));
                }
                resultData.push_back(resultRow);
            }
        }
        Matrix Result = Matrix(resultData);
        return Result;
    }



    
}