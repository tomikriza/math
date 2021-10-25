
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
}
