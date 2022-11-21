#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    int N, a[100000], gisto[10000] = {0};
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanf("%d", &N);    //читаем переменные из файла
    
    for (int i = 0; i < N; i++)
        scanf("%d", &a[i]); //заполняем массив
    
    for (int i = 0; i < N; i++)  //записываем результаты в гистограмму
        gisto[a[i] - 1]++; 

    for (int i = 0; i < 10000; i++)
        if (gisto[i] > 0) printf("%d: %d\n", i + 1/*сэкономил 1 int))*/, gisto[i]); 

    return 0;
}