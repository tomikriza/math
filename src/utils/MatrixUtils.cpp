
#include "MatrixUtils.h"

namespace MatrixLibrary::Utils
{

    bool MatchingDimensions(Matrix A, Matrix B)
    {
        if (A.dim.rows == B.dim.rows && A.dim.cols == B.dim.cols)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isSquareMatrix(Matrix A)
    {
        if (A.dim.rows == A.dim.cols)
        {
            return true;
        }
        return false;
    }

    double dotProduct(std::vector<double> v1, std::vector<double> v2)
    {
        double result = 0;
        if (v1.size() == v2.size())
        {
            for (int i = 0; i < v1.size(); i++)
            {
                result += v1[i] * v2[i];
            }
        }
        return result;
    }
}
