#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    int gysto[95] = {0};
    char symbol;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (scanf("%c", &symbol) != EOF) //сканируем
    {
        if (symbol >= 32)
            gysto[(int)symbol - 32]++;
    }

    for (int i = 0; i < 95; i++) //вывод
    {
        if (gysto[i] > 0)
        {
            printf("%c ", (char)i + 32);
            for (int j = 0; j < gysto[i]; j++)
            {
                printf("#");
            }
            printf("\n");
        }
    }

    return 0;
}