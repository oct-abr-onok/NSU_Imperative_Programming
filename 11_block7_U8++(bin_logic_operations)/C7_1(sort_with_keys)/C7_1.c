#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct zap_s
{
    int key;
    char str[8];
} zap;

int main(void)
{
    int N;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &N); //читаем переменные из файла
    zap *arr = malloc(sizeof(zap) * N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i].key);
        scanf("%s", arr[i].str);
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (arr[i].key < arr[j].key)
            {
                zap mem;
                mem = arr[i];
                arr[i] = arr[j];
                arr[j] = mem;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i].key);
        printf("%s\n", arr[i].str);
    }

    free(arr);
    return 0;
}