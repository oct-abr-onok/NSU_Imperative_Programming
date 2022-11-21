#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

int main(void)
{
    int N, a[100000];

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &N); //читаем переменные из файла

    for (int i = 0; i < N; i++)
        scanf("%d", &a[i]); //заполняем массив

    for (int i = 0; i < N; i++) //бубльсорт
    {
        for (int j = i; j < N; j++)
        {
            if (a[i] > a[j])
            {
                swap(&a[i], &a[j]);
            }
        }
    }

    for (int i = 0; i < N; i++) //выводим результат
    {
        printf("%d ", a[i]);
    }

    return 0;
}