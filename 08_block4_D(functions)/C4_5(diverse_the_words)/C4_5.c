#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//char test[8] = {'.', ',', ';', ':', 'a', 'z', 'A', 'Z'};

void Str_separator(char *str)
{
    char word[10000001];
    int up_cnt = 0, word_start = 0, i;

    for (i = 0; str[i] != 0; i++)
    {
        if (!((str[i] <= 'z') && (str[i] >= 'a')) && !((str[i] <= 'Z') && (str[i] >= 'A')))
        {
            if (i - word_start)
            {
                printf("%d/%d %s\n", up_cnt, i - word_start, word);
            }

            for (int j = 0; j <= i - word_start; j++) //сбрасываем слово
            {
                word[j] = 0;
            }
            up_cnt = 0;

            word_start = i + 1; //готовим всё для записи нового слова
        }
        else //записываем букву в слово
        {
            word[i - word_start] = str[i];
            if ((str[i] <= 'Z') && (str[i] >= 'A'))
            {
                up_cnt++;
            }
        }
    }
    if (i - word_start)
            {
                printf("%d/%d %s\n", up_cnt, i - word_start, word);
            }
}

int main(void)
{
    char str[10000001];

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    gets(&str[0]);
    Str_separator(&str[0]);

    return 0;
}