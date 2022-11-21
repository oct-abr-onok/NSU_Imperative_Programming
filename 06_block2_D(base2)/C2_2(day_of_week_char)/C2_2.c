#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void)
{
    char FirstLetter, SecondLetter;
    int num;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanf("%c", &FirstLetter);
    scanf("%c", &SecondLetter);    //читаем переменные из файла
    
    switch (FirstLetter) //в зависимости от первых двух букв определяем, что выводить
    {
    case 'M':
        num = 1;
        break;
    
    case 'T':
        if (SecondLetter == 'u')
            num = 2;
        else
            num = 4;
        break;

    case 'W':
        num = 3;
        break;

    case 'S':
        if (SecondLetter == 'a')
            num = 6;
        else
            num = 7;
        break;

    default:
        num = 5;
        break;
    }

    printf("%d", num); //выводим результат
    return 0;
}