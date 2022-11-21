#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void)
{
    int N, IsPrime = 1;
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanf("%d", &N);    //читаем переменные из файла
    
    for (int i = 2; i <= N / 2; i++)
    {
        if (N % i == 0)
        {
            IsPrime = 0;  //проверяем, простое ли число
        }
    }
    
    if (N == 1)
    {
        IsPrime = 0; //оказалось, что по каким-то непонятным причинам 1 - не простое число ¯\_(ツ)_/¯
    }
    
    if (IsPrime)  //выдаём ответ
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }

    return 0;
}