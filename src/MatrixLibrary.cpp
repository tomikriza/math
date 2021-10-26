#include "include/MatrixLibrary.h"
#include "include/utils/MatrixUtils.h"

namespace MatrixLibrary
{

    Matrix Zeros(int row_dim, int col_dim)
    {
        std::vector<double> row;
        std::vector<std::vector<double>> table;
        row.assign(col_dim, 0);
        table.assign(row_dim, row);
        return Matrix(table);
    }

    Matrix Ones(int row_dim, int col_dim)
    {
        std::vector<double> row;
        std::vector<std::vector<double>> table;
        row.assign(col_dim, 1);
        table.assign(row_dim, row);
        return Matrix(table);
    }

    Matrix::Matrix(std::vector<std::vector<double>> table)
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
        for (int i = 0; i < dim.rows; i++)
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

    bool areEqual(Matrix A, Matrix B)
    {
        if (!Utils::MatchingDimensions(A, B))
        {
            return false;
        }

        for (int row_idx = 0; row_idx < A.dim.rows; row_idx++)
        {
            for (int col_idx = 0; col_idx < A.dim.cols; col_idx++)
            {
                if (A.data[row_idx][col_idx] != B.data[row_idx][col_idx])
                {
                    return false;
                }
            }
        }
        return true;
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
        Matrix M = Zeros(size, size);

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
            std::vector<std::vector<double>> table;
            for (int row_idx = 0; row_idx < A.dim.rows; row_idx++)
            {
                std::vector<double> row;
                for (int col_idx = 0; col_idx < A.dim.cols; col_idx++)
                {
                    row.push_back(A.data[row_idx][col_idx] + B.data[row_idx][col_idx]);
                }
                table.push_back(row);
            }
            return Matrix(table);
        }
        return Zeros(1, 1); //TODO Change this
    }

    Matrix Multiply(Matrix A, Matrix B)
    {
        std::vector<std::vector<double>> table;
        if (A.dim.cols == B.dim.rows)
        {
            for (int row_idx = 0; row_idx < B.dim.rows; row_idx++)
            {
                std::vector<double> row;
                for (int col_idx = 0; col_idx < A.dim.cols; col_idx++)
                {
                    row.push_back(Utils::dotProduct(A.getRow(row_idx), B.getColumn(col_idx)));
                }
                table.push_back(row);
            }
        }
        return Matrix(table);
    }

    Matrix Multiply(double scalar, Matrix A)
    {
        Matrix Result = A;

        for (int row_idx = 0; row_idx < Result.dim.rows; row_idx++)
        {
            for (int col_idx = 0; col_idx < Result.dim.cols; col_idx++)
            {
                Result.data[row_idx][col_idx] = Result.data[row_idx][col_idx] * scalar;
            }
        }

        return Result;
    }

    Matrix Multiply(Matrix A, double scalar)
    {
        return Multiply(scalar, A);
    }

    Matrix Transpose(Matrix A)
    {
        std::vector<std::vector<double>> table;
        for (int col_idx = 0; col_idx < A.dim.cols; col_idx++)
        {
            table.push_back(A.getColumn(col_idx));
        }

        return Matrix(table);
    }

    double Minor(Matrix A, int row_idx, int col_idx)
    {
        return Det(Utils::removeRowAndColumn(A, row_idx, col_idx));
    }

    double Det(Matrix A)
    {
        if (!Utils::isSquareMatrix(A))
        {
            return 0; //TODO Disable this possibility
        }
        else
        {
            switch (A.dim.rows)
            {
            case 2:
                return A.data[0][0] * A.data[1][1] - A.data[1][0] * A.data[0][1];
            default:
                double result = 0;
                int sign = 1;
                for (int col_idx = 0; col_idx < A.dim.cols; col_idx++)
                {
                    result += sign * A.data[0][col_idx] * Minor(A, 0, col_idx);
                    sign = -sign;
                }
                return result;
            }
        }
    }

    bool isInvertable(Matrix A)
    {
        if (Det(A) != 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    Matrix Inverse(Matrix A)
    {
        if (isInvertable(A))
        {
            std::vector<std::vector<double>> table;
            int sign;
            for (int row_idx = 0; row_idx < A.dim.rows; row_idx++)
            {
                if (row_idx % 2 == 0)
                {
                    sign = 1;
                }
                else
                {
                    sign = -1;
                }
                std::vector<double> row;
                for (int col_idx = 0; col_idx < A.dim.cols; col_idx++)
                {
                    row.push_back(sign * Minor(A, row_idx, col_idx));
                    sign = -sign;
                }
                table.push_back(row);
            }
            return Transpose(Multiply(1 / Det(A), Matrix(table)));
        }
        else
        { // TODO Deal with this scenario
            return Eye(A.dim.rows);
        }
    }
}