#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int binFind(int *arr, int X, int N)
{
    int centr, first = 0, last = N - 1, res = -1;

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
            if (arr[first] == X)
            {
                res = first;
            }
            if (arr[last] == X)
            {
                res = last;
            }

            return res;
        }
    }
}

int main(void)
{
    int N, Q;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &N); //читаем переменные из файла

    int *arr = malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &Q);
    int res = 0, res_mem, X; //алгоритм из задания
    for (int i = 0; i < Q; i++)
    {
        scanf("%d", &X);
        X += res;
        res = -1;

        res = binFind(arr, X, N);

        printf("%d\n", res);
    }

    return 0;
}