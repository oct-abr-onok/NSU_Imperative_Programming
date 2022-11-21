#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "myblas.h"

int main(void)
{
    const double A[16] = {8, 2, 5, 9, 5, 7, 1, 9, 7, 6, 5, 3, 6, 2, 2, 0};
    const double B[16] = {2, 3, 8, 6, 1, 9, 6, 0, 4, 2, 6, 6, 1, 4, 9, 6};
    double *C = calloc(16, 8);

    dgemm(4, 4, 4, 1.0, A, B, 1.0, C);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%.0lf ", C[i * 4 + j]);
        }
        printf("\n");
    }
    
    return 0;
}