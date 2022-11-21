#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void)
{
    double TotalNumbers, PlusNumbers = 0, ZeroNumbers = 0, MinusNumbers = 0;
    int mem;
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanf("%lf", &TotalNumbers);    //читаем переменные из файла
    
    for (int i = 0; i < TotalNumbers; i++) //проходим по всем числам и считаем количество подходящих под каждую категорию
    {
        scanf("%d", &mem);
        if (mem > 0)
        {
            PlusNumbers++;
        }
        else
        {
            if (mem == 0)
            {
                ZeroNumbers++;
            }
            else
            {
                MinusNumbers++;
            }
        }
    }
    
    printf ("%0.5lf ", MinusNumbers / TotalNumbers); //выводим результаты
    printf ("%0.5lf ", ZeroNumbers / TotalNumbers);
    printf ("%0.5lf", PlusNumbers / TotalNumbers);

    return 0;
}