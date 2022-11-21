#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

long long binFindMin(long long *arr, int X, int N)
{
    long long centr, first = 0, last = N - 1, res = -1;

    while (1)
    {
        centr = (first + last) / 2;
        if (X < arr[centr])
        {
            last = centr;
        }
        else
        {
            if (X == arr[centr])
            {
                res = centr;
            }
            first = centr;
        }
        if (last - first < 2)
        {
            if (arr[first] - X >= 0)
            {
                res = first;
            }
            else
            {
                res = last;
            }

            return res;
        }
    }
}

int main(void)
{
    int N, Q, C;

    FILE *fin = fopen("input.txt", "rt");
    FILE *fout = fopen("output.txt", "wt");

    //читаем переменные из файла
    fscanf(fin, "%d", &N);
    long long *arr = malloc(N * sizeof(long long));
    long long *derivative = malloc((N - 1) * sizeof(long long));
    for (int i = 0; i < N; i++)
    {
        fscanf(fin, "%lld", &arr[i]);
        if (i > 0) //находим дискретно "производные"
        {
            derivative[i - 1] = arr[i] - arr[i - 1];
        }
    }

    fscanf(fin, "%d", &Q);
    for (int j = 0; j < Q; j++)
    {
        //поиск минимума
        fscanf(fin, "%d", &C);
        long long last_der;
        if (derivative[N - 2] + C < 0)
        {
            fprintf(fout, "%d\n", N - 1);
        }
        else
        {
            fprintf(fout, "%d\n", binFindMin(&derivative[0], -C, N - 1));
        }
    }

    free(derivative);
    free(arr);
    fclose(fin);
    fclose(fout);
}