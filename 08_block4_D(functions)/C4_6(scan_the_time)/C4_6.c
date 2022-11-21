#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

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

int strlen_mine(char *start) //считаем кол-во элементов в строке
{
    int i = 0;
    while (*(start + i) != 0)
    {
        i++;
    }
    return i;
}

int readTime(char *iStr, int *oHours, int *oMinutes, int *oSeconds)
{
    int i, last, len, len_h, len_m, len_s, str_counter = 0, hours_mem = 0, minutes_mem = 0, seconds_mem = 0, error_flag = 0;
    char hours[16] = {0}, minutes[16] = {0}, seconds[16] = {0}, symb;
    len = strlen_mine(iStr);

    i = 0;

    sscanf(&iStr[i], "%c", &hours[i]); //cчитаем часы
    i++;
    for (; hours[i - 1] != ':' && hours[i - 1] != 0; i++) //заводим в строку
    {
        sscanf(&iStr[i], "%c", &hours[i]);
    }
    len_h = strlen_mine(&hours[0]); //подготавливаем строку для перевода в инт
    reverse(&hours[0], len_h);
    for (int j = 0; j < len_h; j++)
    {
        sscanf(&hours[j], "%c", &symb);
        if (symb >= '0' && symb <= '9') //переводим в инт
        {
            if (str_counter == 1)
                hours_mem += ((int)symb - 48) * 10;
            else
            {
                if (str_counter > 1)
                    return 0;
                hours_mem += (int)symb - 48;
            }
            str_counter++;
        }
        else
        {
            if (symb == '|') //ставим ошибку, если видим эту штуку
            {
                error_flag = 1;
            }
            if (symb == ':')
            {
                continue;
            }
        }
    }
    last = i;
    str_counter = 0;

    if (hours_mem > 23)
    {
        error_flag = 1; //ставим ошибку при переполнении
    }

    sscanf(&iStr[i], "%c", &minutes[i - last]); //аналогично часам
    i++;
    for (; minutes[i - last - 1] != ':' && minutes[i - last - 1] != 0; i++)
    {
        sscanf(&iStr[i], "%c", &minutes[i - last]);
    }
    len_m = strlen_mine(&minutes[0]);
    reverse(&minutes[0], len_m);
    for (int j = 0; j < len_m; j++)
    {
        sscanf(&minutes[j], "%c", &symb);
        if (symb >= '0' && symb <= '9')
        {
            if (str_counter == 1)
                minutes_mem += ((int)symb - 48) * 10;
            else
            {
                if (str_counter > 1)
                    return 0;
                minutes_mem += (int)symb - 48;
            }
            str_counter++;
        }
        else
        {
            if (symb == '|')
            {
                error_flag = 1;
            }
            if (symb == ':')
            {
                continue;
            }
        }
    }
    last = i;
    str_counter = 0;

    if (minutes_mem > 59)
    {
        error_flag = 1;
    }

    sscanf(&iStr[i], "%c", &seconds[i - last]); //аналогично часам
    i++;
    for (; seconds[i - last - 1] != ':' && seconds[i - last - 1] != 0; i++)
    {
        sscanf(&iStr[i], "%c", &seconds[i - last]);
    }
    len_s = strlen_mine(&seconds[0]);
    reverse(&seconds[0], len_s);
    for (int j = 0; j < len_s; j++)
    {
        sscanf(&seconds[j], "%c", &symb);
        if (symb >= '0' && symb <= '9')
        {
            if (str_counter == 1)
                seconds_mem += ((int)symb - 48) * 10;
            else
            {
                if (str_counter > 1)
                    return 0;
                seconds_mem += (int)symb - 48;
            }
            str_counter++;
        }
        else
        {
            if (symb == '|')
            {
                error_flag = 1;
            }
            if (symb == ':')
            {
                continue;
            }
        }
    }
    last = i;
    str_counter = 0;

    if (seconds_mem > 59)
    {
        error_flag = 1;
    }

    if (error_flag) //вывод
    {
        *oHours = -1;
        if (oMinutes != NULL)
            *oMinutes = -1;
        if (oSeconds != NULL)
            *oSeconds = -1;
        return 0;
    }
    else
    {
        *oHours = hours_mem;
        if (oMinutes != NULL)
            *oMinutes = minutes_mem;
        if (oSeconds != NULL)
            *oSeconds = seconds_mem;
        return 1;
    }
}

int main(void)
{
    int oHours = -1, oMinutes = -1, oSeconds = -1, mem;
    char time[16] = {0};

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    gets(&time[0]); //в мейне комментировать нечего
    mem = readTime(&time[0], &oHours, &oMinutes, &oSeconds);
    printf("%d %d %d %d\n", mem, oHours, oMinutes, oSeconds);
    mem = readTime(&time[0], &oHours, &oMinutes, NULL);
    printf("%d %d %d\n", mem, oHours, oMinutes);
    mem = readTime(&time[0], &oHours, NULL, NULL);
    printf("%d %d\n", mem, oHours);
    return 0;
}