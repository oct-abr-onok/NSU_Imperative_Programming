#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void printTime(int hours, int minutes, int seconds) //ф-я ◉_◉
{
    printf("%02d:%02d:%02d\n", hours, minutes, seconds);
}

int main(void)
{
    int N, hours, minutes, seconds;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &N); //читаем переменные из файла

    for (int i = 0; i < N; i++) // в принципе очевидно
    {
        scanf("%d", &hours);
        scanf("%d", &minutes);
        scanf("%d", &seconds);
        printTime(hours, minutes, seconds);
    }

    return 0;
}