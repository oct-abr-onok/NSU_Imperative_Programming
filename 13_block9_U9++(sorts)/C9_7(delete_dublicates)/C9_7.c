#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int merge(const int *a, int ak, const int *b, int bk, int *res)
{
    for (int i = 0, j = 0; i + j < ak + bk;)
    {
        if (a[i] <= b[j])
        {
            if (i == ak)
            {
                res[i + j] = b[j];
                j++;
            }
            else
            {
                res[i + j] = a[i];
                i++;
            }
        }
        else
        {
            if (j == bk)
            {
                res[i + j] = a[i];
                i++;
            }
            else
            {
                res[i + j] = b[j];
                j++;
            }
        }
    }

    return ak + bk;
}

void mergeSort(int *arr, int n, int *res)
{
    if (n == 1)
    {
    }
    else
    {
        //делим->сортируем->сливем
        mergeSort(arr, n / 2, res);
        mergeSort(&arr[n / 2], n - n / 2, res);
        merge(arr, n / 2, &arr[n / 2], n - n / 2, res);
        for (int i = 0; i < n; i++)
        {
            arr[i] = res[i];
        }
    }
}

int main(void)
{
    int N;

    FILE *fi = fopen("input.txt", "rt");
    FILE *fo = fopen("output.txt", "wt");

    //сканирование
    fscanf(fi, "%d", &N);
    int *arr = malloc(sizeof(int) * N);
    int *res = malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
    {
        fscanf(fi, "%d", &arr[i]);
    }

    //сортировка
    mergeSort(arr, N, res);

    //находим все уникальные числа
    int mem = arr[0];
    int cnt = 1;
    res[cnt - 1] = mem;
    for (int i = 1; i < N; i++)
    {
        if (arr[i] > mem)
        {
            cnt++;
            mem = arr[i];
            res[cnt - 1] = mem;
        }
    }
    fprintf(fo, "%d\n", cnt);

    //вывод
    for (int i = 0; i < cnt; i++)
    {
        fprintf(fo, "%d\n", res[i]);
    }

    free(res);
    free(arr);
    fclose(fi);
    fclose(fo);
}