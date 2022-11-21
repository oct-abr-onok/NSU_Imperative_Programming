#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void swap(char *a, char *b) //чаровский свуп (◕‿◕)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

int main(void)
{
    int N, flag = 0;
    char symbols[26] = {0};

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &N); //читаем переменные из файла

    for (int i = 0; i < N; i++) //читаем символы
    {
        scanf(" ");
        scanf("%c", &symbols[i]);
    }

    for (int i = 24; i >= 0; i--)
    {
        for (int j = 25; j > i; j--) //ищем 2 значения от конца, поменяв которые новая последовательность символов будет больше, чем исходная
        {

            if (symbols[i] < symbols[j] && symbols[i] != 0 && symbols[j] != 0)
            {
                swap(&symbols[i], &symbols[j]);
                flag = i + 1;
                break;
            }
        }
        if (flag) //выполняем бубльсорт для символов, после изменённого, чтобы выходная последовательность была минимальна
        {
            for (int f_sort = flag; f_sort < N; f_sort++)
            {
                for (int s_sort = f_sort; s_sort < N; s_sort++)
                {
                    if (symbols[f_sort] > symbols[s_sort])
                    {
                        swap(&symbols[f_sort], &symbols[s_sort]);
                    }
                }
            }
            break;
        }
    }

    for (int i = 0; i < N; i++) //выводим результат
    {
        if (symbols[i] != 0)
        {
            printf("%c ", symbols[i]);
        }
    }

    return 0;
}