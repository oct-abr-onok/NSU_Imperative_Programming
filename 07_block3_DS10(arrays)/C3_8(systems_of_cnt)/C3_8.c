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

long long int_pow(long long base, long long index) //функция возведения в степень
{
    long long base_mem = base;
    for (int i = 0; i < index - 1; i++)
    {
        base *= base_mem;
    }
    if (index == 0)
    {
        base = 1;
    }
    return base;
}

long long int_sqrt(long long base, long long index) //корень степени с округлением вниз
{
    for (int i = 0;; i++)
    {
        if (int_pow(i, index) > base)
        {
            return i - 1;
        }
    }
} //в итоге не понадобилась(

int main(void)
{
    long long mem = 0;
    int first_sys, second_sys, int_num[30], digit_cnt, flag_for_out = 0, max_pow;
    char N, num[30] = {0};

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &first_sys); //читаем переменные из файла
    scanf("%d", &second_sys);
    scanf(" ");
    for (int i = 0; i < 30; i++)
    {
        scanf("%c", &num[i]);
        if (num[i] == 0 || num[i] == ' ' || num[i] == '\n')
        {
            num[i] = 0;
            digit_cnt = i;
            break;
        }
    }

    for (int i = 0; i < digit_cnt; i++) //приводим массив в 'приличный' вид
    {
        swap(&num[i], &num[30 + i - digit_cnt]);
    }

    for (int i = 0; i < 30; i++) //переводим строку в инт
    {
        if (num[i] < 'a' && num[i] > 0)
        {
            int_num[i] = (int)num[i] - '0';
        }
        else
        {
            if (num[i] >= 'a')
            {
                int_num[i] = (int)num[i] - 87;
            }
            else
            {
                int_num[i] = 0;
            }
        }
    }

    for (int i = 29; i >= 0; i--) //переводим в десятичное
    {
        mem += int_num[i] * int_pow(first_sys, 29 - i);
    }

    for (int i = 0; i < 30; i++) //зануляем массив
    {
        int_num[i] = 0;
    }

    for (int i = 0; mem > int_pow(second_sys, i); i++) //считаем, с какого разряда начинается число в нужной системе
    {
        max_pow = i + 1;
    }

    for (int i = max_pow; i >= 0; i--) //переводим в нужную систему
    {
        int_num[i] = mem / int_pow(second_sys, i);
        mem %= int_pow(second_sys, i);
    }

    for (int i = 0; i < 30; i++) //переводим строку в char
    {
        if (int_num[i] < 10 && int_num[i] >= 0)
        {
            num[i] = (char)int_num[i] + '0';
        }
        else
        {
            if (int_num[i] >= 10)
            {
                num[i] = (char)int_num[i] + 87;
            }
            else
            {
                num[i] = ' ';
            }
        }
    }

    for (int i = 29; i >= 0; i--) //выводим результат
    {
        if (num[i] != '0' || flag_for_out)
        {
            flag_for_out = 1;
            printf("%c", num[i]);
        }
    }

    return 0;
}