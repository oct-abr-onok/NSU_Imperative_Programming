#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct LongNum_s
{
    int len;      //сколько цифр в числе
    int arr[500]; //массив десятичных цифр числа
} LongNum;

LongNum LongSum(LongNum *a, LongNum *b)
{
    LongNum res = {0};
    int maxlen, overflw = 0, mem;

    if (a->len > b->len) //находим длину максимального из слогаемых
    {
        maxlen = a->len;
    }
    else
    {
        maxlen = b->len;
    }

    res.len = maxlen;
    for (int i = 0; i < maxlen + 1; i++) //считаем поразрядно с добавлением остатка с прошлого разряда
    {
        mem = a->arr[i] + b->arr[i];
        res.arr[i] = (mem + overflw) % 10;
        overflw = (mem + overflw) / 10;
    }
    if (res.arr[maxlen] != 0) //смотрим, не добавился ли дополнительный разряд
    {
        res.len++;
    }

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
    LongNum first = {1, {1}}, second = {1, {1}}, mem;
    int N;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &N);
    for (int i = 0; i < N - 2; i++) //делаем всё по алгоритму
    {
        mem = second;
        second = LongSum(&first, &second);
        first = mem;
    }
    LongPrint(&second);

    return 0;
}