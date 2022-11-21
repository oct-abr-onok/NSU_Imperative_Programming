#include "cblas.h"
#include <Windows.h>
#include "openBlas_config.h"

// Computes R = A * A;
// Here A and R are square matrices N x N.
// Every matrix is stored in row-major layout,
// i.e. A[i*n+j] is the element in i-th row and j-th column.
void MatrixSqr(int n, const double *A, double *R)
{
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, n, n, n, 1, A, n, A, n, 0, R, n);
}