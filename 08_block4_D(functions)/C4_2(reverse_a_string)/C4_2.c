#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int strlen_mine(char *start) //считаем кол-во элементов в строке
{
    int i = 0;
    while (*(start + i) != 0)
    {
        i++;
    }
    return i;
}

void swap(char *a, char *b) //чаровский свуп (◕‿◕)
{
    char c;
    c = *a;
    *a = *b;
    *b = c;
}

void reverse(char *start, int len) //ф-я
{
    for (int i = 0; i < len / 2; i++)
    {
        swap(&start[i], &start[len - 1 - i]);
    }
}

int main(void)
{
    int N, len;
    char str[101] = {0};

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &N); //читаем переменные из файла

    for (int i = 0; i < N; i++) //вызываем ф-ю нужное количество раз
    {
        scanf("%s", str);
        len = strlen_mine(&str[0]);
        reverse(&str[0], len);
        printf("%s", str);
        printf("\n");
    }

    return 0;
}