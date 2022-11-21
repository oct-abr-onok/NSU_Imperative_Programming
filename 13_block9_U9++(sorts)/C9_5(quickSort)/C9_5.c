#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//partitions array a[0..n-1] into two subarrays, returning value k
// the subarray a[0..k-1] must have all elements <= pivot
// the subarray a[k..n-1] must have all elements >= pivot
int partition(int *a, int n, int pivot)
{
    int *left = malloc(sizeof(int) * n);
    int *right = malloc(sizeof(int) * n);
    int leftCnt = 0, rightCnt = 0, monet = 0;

    //разделяем части
    for (int i = 0; i < n; i++)
    {
        if (a[i] < pivot)
        {
            left[leftCnt] = a[i];
            leftCnt++;
        }
        if (a[i] > pivot)
        {
            right[rightCnt] = a[i];
            rightCnt++;
        }
        if (a[i] == pivot)
        {
            if (monet % 2)
            {
                left[leftCnt] = a[i];
                leftCnt++;
            }
            else
            {
                right[rightCnt] = a[i];
                rightCnt++;
            }
            monet++;
        }
    }

    //соединяем всё в одном массиве
    for (int i = 0; i < leftCnt; i++)
    {
        a[i] = left[i];
    }
    for (int i = 0; i < rightCnt; i++)
    {
        a[i + leftCnt] = right[i];
    }

    free(left);
    free(right);
    return leftCnt;
}

void quickSort(int *arr, int n)
{
    int pivot, k;
    if (n <= 1)
    {
    }
    else
    {
        //разбиение->сортировка->слияние
        pivot = arr[rand() % n];
        k = partition(arr, n, pivot);
        quickSort(arr, k);
        quickSort(&arr[k], n - k);
    }
}

int main(void)
{
    int N;

    FILE *fi = fopen("input.txt", "rb");
    FILE *fo = fopen("output.txt", "wb");

    fread(&N, sizeof(int), 1, fi);
    if (N != 0)
    {
        //читаем переменные из файла
        int *arr = malloc(sizeof(int) * N);
        fread(arr, sizeof(int), N, fi);

        //сортировка
        quickSort(arr, N);

        //вывод
        fwrite(arr, sizeof(int), N, fo);

        free(arr);
    }

    fclose(fi);
    fclose(fo);
}