#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int binFindMin(int *arr, int X, int N)
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
            if (abs(arr[first] - X) < abs(arr[last] - X))
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
    int res, Y; //алгоритм из задания
    for (int i = 0; i < Q; i++)
    {
        scanf("%d", &Y);

        res = binFindMin(arr, Y, N);

        printf("%d %d\n", res, abs(Y - arr[res]));
    }

    return 0;
}