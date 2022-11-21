#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    int N, a[100000];
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanf("%d", &N);    //читаем переменные из файла
    
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &a[i]); //заполняем массив
    }
    
    for (int i = 1; i <= N; i++)
    {
        int cnt = 0;
        for (int j = i - 1; j < N; j += i)  //считаем сумму с интервалом i
            cnt += a[j];
        printf("%d\n", cnt);
    }

    return 0;
}