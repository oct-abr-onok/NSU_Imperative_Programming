#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    int N, b[100];
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanf("%d", &N);    //читаем переменные из файла
    
    for (int j = 0; j < N; j++)
    {
        scanf("%d", &b[j]); //заполняем массив
    }
    
    for (int j = 0; j < N; j++)
    {
        int cnt = 0;  //проходимся по массиву и смотрим все элементы правее текущего на соответствие условию
        for (int i = j + 1; i < N; i++)
            if (b[i] < b[j]) cnt++;
        printf("%d ", cnt);
    }

    return 0;
}