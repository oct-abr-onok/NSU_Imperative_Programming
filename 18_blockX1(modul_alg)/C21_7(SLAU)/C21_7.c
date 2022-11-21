#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void matrix_swap(double **matrix, int a, int b, int x)
{
    double mem;
    for (int i = 0; i < x; i++)
    {
        mem = matrix[i][a];
        matrix[i][a] = matrix[i][b];
        matrix[i][b] = mem;
    }
}

void to_stepped(double **matrix, int x, int y)
{
    int lock = 0;
    for (int i = 0; i < x; i++)
    {
        for (int j = lock; j < y; j++)
        {
            if (matrix[i][j] == 0) //случай A
            {
                continue;
            }
            else //случай B
            {
                matrix_swap(matrix, lock, j, x); //пермещение
                lock++;                          //сдвиг
                for (int k = lock; k < y; k++)   //зануление
                {
                    double t = matrix[lock - 1][k] / matrix[lock - 1][lock - 1];
                    // matrix[lock - 1][k] = 0;
                    for (int m = 0; m < x; m++) //не забываем про дополнительный (n+1)-ый столбец!
                        matrix[m][k] -= matrix[m][lock - 1] * t;
                }
                break;
            }
        }
    }
}

double *to_results(double **matrix, int x, int y) //возможны проблемы с d[i]
{
    double *res = malloc(sizeof(double) * (y + 1));
    res[y] = -1;

    for (int i = y - 1; i >= 0; i--)
    {
        double sum = 0;
        for (int j = i + 1; j < x; j++)
        {
            sum += matrix[j][i] * res[j] * -1;
        }
        res[i] = sum / matrix[i][i];
    }

    return res;
}

int main(void)
{
    int N;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &N);                                  //читаем переменные из файла
    double **slau = malloc((N + 1) * sizeof(double)); //создаём матрицу уравнений
    for (int i = 0; i < N + 1; i++)
    {
        slau[i] = malloc(N * sizeof(double));
    }

    //чтение уравнений
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N + 1; j++)
        {
            scanf("%lf", &slau[j][i]);
        }
    }

    to_stepped(slau, N + 1, N);
    double* res = to_results(slau, N + 1, N);

    /*for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N + 1; j++)
        {
            printf("%.1lf ", slau[j][i]);
        }
        printf("\n");
    }*/

    for (int i = 0; i < N; i++)
    {
        printf("%lf\n", res[i]);
    }

    return 0;
}