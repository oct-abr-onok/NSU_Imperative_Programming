#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void)
{
    int A, B, out1, out2, out3, out4;
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanf("%d", &A);    //читаем переменные из файла
    scanf("%d", &B);

    out1 = A / B;
    if ((A % B <= 0) && (A % B != 0))    //по умолчанию округление в сторону нуля, так что меняем направление округления при отрицательных значениях
    {
        out1 -= 1;
    }
    
    out2 = A / B;
    if ((A % B >= 0) && (A % B != 0))    //по умолчанию округление в сторону нуля, так что меняем направление округления при положительных значениях
    {
        out2 += 1;
    }

    out3 = A / B;   //по умолчанию округление в сторону нуля, так что ничего менять не надо

    out4 = A % B;
    if (out4 < 0)   //если остаток не подходит под критерии - приводим его в нужный вид
    {
        out4 += B;
    }

    printf("%d ", out1); //выводим результаты
    printf("%d ", out2);
    printf("%d ", out3);
    printf("%d ", out4);

    return 0;
}