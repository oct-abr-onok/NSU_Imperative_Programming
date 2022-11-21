#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int DoesFit(int a1, int a2, int x1, int x2) //ф-я для определения, вмещается ли данная конфигурация прямоугольников в большой прямоугольник
{
    if (((x1 <= a1) && (x2 <= a2)) || ((x1 <= a2) && (x2 <= a1)))
        return 1;
    else
        return 0;
}

int Max(int x1, int x2) //ф-я для определения максимальной стороны
{
    if (x1 > x2)
    {
        return x1;
    }
    else
    {
        return x2;
    }
}

int main(void)
{
    int a1, a2, b1, b2, c1, c2, max_c, max_b, min_c, min_b;
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanf("%d", &a1);
    scanf("%d", &a2);
    scanf("%d", &b1);
    scanf("%d", &b2);
    scanf("%d", &c1);
    scanf("%d", &c2);    //читаем переменные из файла
    
    /*max_c = c2;
    min_c = c1;
    if (c1 > c2)    //определяем меньшие и бОльшие стороны прямоугольников - это понадобится позже
    {
        max_c = c1;
        min_c = c2;
    }
    
    max_b = b2;
    min_b = b1;
    if (b1 > b2)
    {
        max_b = b1;
        min_b = b2;
    }*/

    if (DoesFit(a1, a2, Max(b1, c1) , b2 + c2) || DoesFit(a1, a2, Max(b1, c2) , b2 + c1) || DoesFit(a1, a2, Max(b2, c1) , b1 + c2) || DoesFit(a1, a2, Max(b2, c2) , b1 + c1)) //перебираем 4 оптимальные конфигурации и выводим результат
        printf("YES");
    else
        printf("NO");
            
    return 0;
}