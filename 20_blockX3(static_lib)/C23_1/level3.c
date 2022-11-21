#include "myblas.h"
#include <stdlib.h>

//вычислить матрицу (alpha*A*B + beta*C) и записать её в C
//здесь A –- матрица размера m на k, B –- матрица размера k на n,
// C –- матрица размера m на n
void dgemm(int m, int n, int k, double alpha, const double *A, const double *B, double beta, double *C)
{
    // alpha*A*B
    double *AB = calloc(m * n, sizeof(double));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            for (int q = 0; q < k; q++)
                AB[i * n + j] += (A[i * k + q] * B[q * n + j]) * alpha;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            C[i * n + j] = C[i * n + j] * beta + AB[i * n + j];
    
    free(AB);
}