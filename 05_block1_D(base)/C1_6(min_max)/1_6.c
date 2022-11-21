#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void)
{
    int N, max = -10001, min = 10001, minN, maxN, mem;
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanf("%d", &N);    //читаем переменные из файла

    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &mem);
        if (mem > max)  //запоминаем максимальные и минимальные значения и их номера
        {
            max = mem;
            maxN = i;
        }
        if (mem < min)
        {
            min = mem;
            minN = i;
        }
    }
    
    printf("%d ", min); //вывод
    printf("%d ", minN);
    printf("%d ", max);
    printf("%d ", maxN);

    return 0;
}