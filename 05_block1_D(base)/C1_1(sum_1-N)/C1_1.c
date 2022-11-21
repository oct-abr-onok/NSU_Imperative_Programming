#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void)
{
    int N, sum = 0;
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanf("%d", &N);    //читаем переменную из файла
    
    for (int i = 1; i <= N; i++)
    {
        sum += i; //считаем сумму всех i до N
    }

    printf("%d", sum);

    return 0;
}