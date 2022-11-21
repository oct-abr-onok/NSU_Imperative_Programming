#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int len_pref; //для сохранения сигнатуры ф-ии, которая указана в задаче...

int strlen_mine(char *start) //считаем кол-во элементов в строке
{
    int i = 0;
    while (*(start + i) != 0)
    {
        i++;
    }
    return i;
}

char *concat(char *pref, char *suff) //приписываем в конец первой строки элементы из второй
{
    int len_suff = strlen_mine(suff);

    for (int i = len_pref; i < len_pref + len_suff; i++)
    {
        pref[i] = suff[i - len_pref];
    }

    len_pref += len_suff;

    return pref;
}

int main(void)
{
    int N, len;
    char str1[1000001] = {0}, str2[101] = {0};
    char *res;
    char *start_str1 = &str1[0];

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &N); //читаем переменные из файла

    scanf("%s", str1);
    len_pref = strlen_mine(&str1[0]);
    for (int i = 0; i < N - 1; i++) //соединяем все строки
    {
        scanf("%s", str2);
        res = concat(&str1[0], &str2[0]);
    }

    printf("%s", str1); //выводим результат

    return 0;
}