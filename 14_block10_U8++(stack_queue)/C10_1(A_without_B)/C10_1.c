#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    int x = *(int *)a;
    int y = *(int *)b;
    return (x == y ? 0 : (x < y ? -1 : 1));
}

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
    int Na, Nb, cnt = 0;

    FILE *fin = fopen("input.txt", "rt");
    FILE *fout = fopen("output.txt", "wt");

    //читаем переменные из файла
    fscanf(fin, "%d", &Na);
    int *A = malloc(sizeof(int) * Na);
    int *res = malloc(sizeof(int) * Na);
    for (int i = 0; i < Na; i++)
    {
        fscanf(fin, "%d\n", &A[i]);
    }
    fscanf(fin, "%d", &Nb);
    int *B = malloc(sizeof(int) * Nb);
    for (int i = 0; i < Nb; i++)
    {
        fscanf(fin, "%d\n", &B[i]);
    }

    //сортировка
    qsort(A, Na, sizeof(int), cmp);
    qsort(B, Nb, sizeof(int), cmp);

    //переносим только нужные значения
    for (int i = 0; i < Na; i++)
    {
        int flag = 0;
        if (i > 0 && (A[i] == A[i - 1]))
        {
            continue;
        }
        if (binFind(B, A[i], Nb) != -1)
        {
            flag++;
        }
        if (!flag)
        {
            res[cnt++] = A[i];
        }
    }

    fprintf(fout, "%d\n", cnt);
    for (int i = 0; i < cnt; i++)
    {
        fprintf(fout, "%d ", res[i]);
    }

    free(res);
    free(A);
    free(B);
    fclose(fin);
    fclose(fout);
}
