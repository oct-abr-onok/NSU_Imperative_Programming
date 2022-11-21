#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N, cnt = 0;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &N); //читаем переменные из файла
    long long *arr = malloc(sizeof(long long) * N);
    for (int i = 0; i < N; i++)
    {
        scanf("%llx", &arr[i]);
    }

    for (int i = 0; i < N - 1; i++) //считаем...
    {
        for (int j = i + 1; j < N; j++)
        {
            if ((arr[i] & arr[j]) == 0)
            {
                cnt++;
            }
        }
    }

    printf("%d", cnt);

    return 0;
}