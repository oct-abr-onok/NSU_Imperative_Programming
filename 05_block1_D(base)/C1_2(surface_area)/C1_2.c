#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void)
{
    int x, y, z, S = 0, min = 1, mem;
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &x);    //читаем переменные из файла
    scanf("%d", &y);
    scanf("%d", &z);
    
    if (x < 1 || y < 1 || z < 1) //находим наименьший номер из неположительных чисел и выводим его номер
    {
        if (z < 1)
        {
            min = z;
            mem = -3;
        }
        if (y < 1)
        {
            min = y;
            mem = -2;
        }
        if (x < 1)
        {
            min = x;
            mem = -1;
        }
        printf("%d", mem);
    }
    else //если нет неподходящих чисел - считаем площадь и выводим
    {
        S = 2 * (x * y) + 2 * (x * z) + 2 * (z * y);
        printf("%d", S);
    }

    return 0;
}