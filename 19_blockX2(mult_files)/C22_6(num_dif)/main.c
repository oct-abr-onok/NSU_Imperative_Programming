#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define ACCURACY 0.00000001

double Function(double x);

int main(void)
{
    int M;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &M); //читаем переменные из файла
    double *x = malloc(sizeof(double) * M);
    for (int i = 0; i < M; i++)
    {
        scanf("%lf", &x[i]);
    }
    for (int i = 0; i < M; i++)
    {
        if (x[i] > 0.9)
            printf("%.6lf\n", (Function(x[i] - ACCURACY) - Function(x[i])) / (-1 * ACCURACY));
        else
            printf("%.6lf\n", (Function(x[i] + ACCURACY) - Function(x[i])) / ACCURACY);
    }

    free(x);

    return 0;
}