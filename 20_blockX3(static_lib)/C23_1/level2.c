#include "myblas.h"
#include <stdlib.h>

//вычислить вектор (alpha*A*X + beta*Y) длины m, и записать его в Y
//здесь A –- матрица размера m на n, X –- вектор длины n, а Y –- вектор длины m
void dgemv(int m, int n, double alpha, const double *A, const double *X, double beta, double *Y)
{
    //умножение матрицы на вектор
    double *AX = calloc(m, sizeof(double));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            AX[i] += A[i * n + j] * alpha * X[j];

    for (int i = 0; i < m; i++)
        Y[i] = Y[i] * beta + AX[i];

    free(AX);
}

//вычислить матрицу (alpha*X*Yt + A) и записать её в A
//здесь Yt –- это транспонированный вектор Y, то есть записанный как вектор-строка
// A –- матрица размера m на n, X –- вектор длины m, а Y –- вектор длины n
void dger(int m, int n, double alpha, const double *X, const double *Y, double *A)
{
    //alpha*X*Yt
    double *XY = calloc(m *n, sizeof(double));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            XY[i * n + j] = X[i] * Y[j] * alpha;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            A[i * n + j] += XY[i * n + j];        

    free(XY);
}