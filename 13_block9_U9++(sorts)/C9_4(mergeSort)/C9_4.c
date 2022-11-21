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

    FILE *fi = fopen("input.txt", "rb");
    FILE *fo = fopen("output.txt", "wb");

    //читаем переменные из файла
    fread(&N, sizeof(int), 1, fi);

    if (N != 0)
    {
        int *arr = malloc(sizeof(int) * N);
        int *res = malloc(sizeof(int) * N);
        fread(arr, sizeof(int), N, fi);

        //сортировка
        mergeSort(arr, N, res);
        
        //вывод
        fwrite(arr, sizeof(int), N, fo);

        free(arr);
        free(res);
    }

    fclose(fi);
    fclose(fo);
}