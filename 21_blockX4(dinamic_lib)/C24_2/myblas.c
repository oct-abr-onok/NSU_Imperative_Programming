#include "cblas.h"
#include "openBlas_config.h"
#include <stdlib.h>

void cblas_dgemm(OPENBLAS_CONST enum CBLAS_ORDER Order, OPENBLAS_CONST enum CBLAS_TRANSPOSE TransA, OPENBLAS_CONST enum CBLAS_TRANSPOSE TransB, OPENBLAS_CONST blasint M, OPENBLAS_CONST blasint N, OPENBLAS_CONST blasint K, OPENBLAS_CONST double alpha, OPENBLAS_CONST double *A, OPENBLAS_CONST blasint lda, OPENBLAS_CONST double *B, OPENBLAS_CONST blasint ldb, OPENBLAS_CONST double beta, double *C, OPENBLAS_CONST blasint ldc)
{
    // alpha*A*B
    double *AB = calloc(M * N, sizeof(double));
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            for (int q = 0; q < K; q++)
                AB[i * N + j] += (A[i * K + q] * B[q * N + j]) * alpha;

    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            C[i * N + j] = C[i * N + j] * beta + AB[i * N + j];
    
    free(AB);
}