#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

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
    long long sumOfMins = 0;

    FILE *fi = fopen("input.txt", "rt");
    FILE *fo = fopen("output.txt", "wt");

    //чтение
    fscanf(fi, "%d", &N);
    int *arr = malloc(sizeof(int) * N);
    int *res = malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
    {
        fscanf(fi, "%d", &arr[i]);
    }
    
    //подсчёты
    mergeSort(arr, N, res);
    for (int i = 0; i < N; i++)
    {
        sumOfMins += (long long)arr[i] * (N - i - 1);
    }

    //вывод
    fprintf(fo, "%lld", sumOfMins);

    free(res);
    free(arr);
    fclose(fi);
    fclose(fo);
}