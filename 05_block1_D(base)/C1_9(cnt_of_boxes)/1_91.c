#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void)
{
    long long N, cnt = 0;
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanf("%lld", &N);    //читаем переменные из файла
    
    /*for (long long x = 1; x <= N / 3; x++)
    {
        for (long long y = x; y <= N / x; y++)
        {
           for (long long z = y; z <= N / x / y; z++) //откуда берётся именно такой цикл могу показать в тетради
           {
               cnt++;
           }
        }
    }*/

    for (int z = 1; N / z / z - (z - 1) > 0; z++)
    {
        for (int x = z; N / x / z - (x - 1) > 0; x++)
        {
            //printf("%d %d\n", x, z);
            cnt += N / x / z - (x - 1);
        }
    }

    printf("%lld", cnt); //выводим результат

    return 0;
}