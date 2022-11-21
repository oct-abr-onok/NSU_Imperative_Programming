#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int power(int found, int index) //простая ф-я возведения в степень
{
    int pow = 1;
    for (int i = 0; i < index; i++)
    {
        pow *= found;
    }
    
    return pow;
}

int main(void)
{
    int N, ogr, byte_mem;
    char bit;
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanf("%d", &N);    //читаем переменные из файла
    scanf(" ");

    for (int i = 0; i < N;)
    {
        byte_mem = 0;
        for (int bi = 0; bi < 8; bi++)  //каждые 8 битов переводим в десятичное число
        {
            scanf("%c", &bit);
            if (bit == '1')
            {
                byte_mem += power(2, bi);
            }
            if (++i >= N)  //проверка на то, что биты не закончились в файле
            {
                break;
            }
        }
        printf("%d ", byte_mem); //выводим десятичное число
    }
    
     return 0;
}