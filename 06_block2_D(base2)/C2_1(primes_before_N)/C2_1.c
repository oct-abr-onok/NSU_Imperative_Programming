#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void)
{
    int N, IsPrime;
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanf("%d", &N);    //читаем переменные из файла
    
    for (int i = 2; i <= N; i++)
    {
        IsPrime = 1;
        for (int del = 2; del <= sqrt(i); del++)
        {
            if (i % del == 0)
            {
                IsPrime = 0; //проверка на простоту
                break;
            }
        }
        if (IsPrime)
        {
            printf("%d\n", i); //выводим числа
        }
    }

    return 0;
}