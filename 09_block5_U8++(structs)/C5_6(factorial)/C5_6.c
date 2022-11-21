#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct LongNum_s
{
    int len;       //сколько цифр в числе
    int arr[3000]; //массив десятичных цифр числа
} LongNum;

LongNum LongMultiply(LongNum *a, int mult)
{
    LongNum res = {0, {0}};
    int mem, overflw = 0, i;

    for (i = 0; i < a->len || overflw > 0; i++) //умножаем поразрядно на 'маленькое' число, переносим перенаполнение разряда в следующий
    {
        mem = a->arr[i] * mult;
        res.arr[i] = (mem + overflw) % 10;
        overflw = (mem + overflw) / 10;
    }
    res.len = i; //определяем длину полученного числа

    return res;
}

void LongPrint(LongNum *num) //печатаем в обратном порядке (o˘◡˘o)
{
    for (int i = num->len - 1; i >= 0; i--)
    {
        printf("%d", num->arr[i]);
    }
    printf("\n");
}

int main(void)
{
    LongNum mem = {1, {1}};
    int N;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &N);
    for (int i = 1; i <= N; i++) //выполняем всё, как указано в задании
    {
        mem = LongMultiply(&mem, i);
    }
    LongPrint(&mem);

    return 0;
}