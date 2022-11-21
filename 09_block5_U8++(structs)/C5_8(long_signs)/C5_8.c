#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct LongNum_s
{
    int len;      //сколько цифр в числе
    int arr[100]; //массив десятичных цифр числа
} LongNum;

void swap(int *a, int *b)
{
    int mem;
    mem = *b;
    *b = *a;
    *a = mem;
}

void LongReverse(LongNum *num)
{
    for (int i = 0; i <= num->len / 2 - 1; i++)
    {
        swap(&num->arr[i], &num->arr[num->len - i - 1]);
    }
}

void LongSum(LongNum *a, LongNum *b, LongNum *res)
{
    for (int i = 0; i < res->len; i++)
    {
        res->arr[i] = 0;
    }

    int maxlen, overflw = 0, mem;

    if (a->len > b->len) //находим длину максимального из слогаемых
    {
        maxlen = a->len;
    }
    else
    {
        maxlen = b->len;
    }

    res->len = maxlen;
    for (int i = 0; i < maxlen + 1; i++) //считаем поразрядно с добавлением остатка с прошлого разряда
    {
        mem = a->arr[i] + b->arr[i];
        res->arr[i] = (mem + overflw) % 10;
        overflw = (mem + overflw) / 10;
    }
    if (res->arr[maxlen] != 0) //смотрим, не добавился ли дополнительный разряд
    {
        res->len++;
    }
}

void LongMultiplyShort(LongNum *a, int mult, LongNum *res)
{
    for (int i = 0; i < res->len; i++)
    {
        res->arr[i] = 0;
    }

    int mem, overflw = 0, i;

    for (i = 0; i < a->len || overflw > 0; i++) //умножаем поразрядно на 'маленькое' число, переносим перенаполнение разряда в следующий
    {
        mem = a->arr[i] * mult;
        res->arr[i] = (mem + overflw) % 10;
        overflw = (mem + overflw) / 10;
    }
    res->len = i; //определяем длину полученного числа
}

void LongMultiplyShortS(LongNum *a, int mult, LongNum *res, int ten_pow) //S - Speciolized
{
    for (int i = 0; i < res->len; i++)
    {
        res->arr[i] = 0;
    }

    int mem, overflw = 0, i;

    for (i = 0; i < a->len || overflw > 0; i++) //умножаем поразрядно на 'маленькое' число, переносим перенаполнение разряда в следующий
    {
        mem = a->arr[i] * mult;
        res->arr[i + ten_pow] = (mem + overflw) % 10;
        overflw = (mem + overflw) / 10;
    }
    res->len = i + ten_pow; //определяем длину полученного числа
}

void LongPrint(LongNum *num) //печатаем в обратном порядке (o˘◡˘o)
{
    for (int i = num->len - 1; i >= 0; i--)
    {
        printf("%d", num->arr[i]);
    }
    printf("\n");
}

void LongScan(LongNum *num)
{
    scanf(" ");
    char mem;
    for (int i = 0; i < 100; i++)
    {
        mem = getchar();
        if (mem < '0')
        {
            num->len = i;
            for (int j = i; j < 100; j++)
            {
                num->arr[j] = 0;
            }
            break;
        }
        num->arr[i] = (int)mem - '0';
    }
    LongReverse(num);
}

void LongMultiply(LongNum *a, LongNum *b, LongNum *res)
{
    LongNum *longmem = malloc(sizeof(LongNum));
    LongNum *funcres = malloc(sizeof(LongNum));

    for (long long i = 0; i < b->len; i++) //выполняем умножение столбиком
    {
        LongMultiplyShortS(a, b->arr[i], longmem, i); //умножаем число на разряд
        LongSum(res, longmem, funcres);               //прибавляем к результату
        *res = *funcres;
    }

    free(longmem);
    free(funcres);
}

void LongDop(LongNum *num)
{
    LongNum one = {1, {1}}, res;
    for (int i = 0; i < 100; i++)
    {
        num->arr[i] = 9 - num->arr[i];
    }
    //LongSum(num, &one, &res);
    //*num = res;
}

int main(void)
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N, mem, first, second;

    scanf("%d", &N);

    LongNum *ln = malloc(sizeof(LongNum) * N);
    LongNum *res = malloc(sizeof(LongNum));
    
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &mem);
        switch (mem)
        {
        case 0:
            LongScan(&ln[i]);
            break;

        case 1:
            scanf("%d", &first);
            scanf("%d", &second);
            LongSum(&ln[first], &ln[second], &ln[i]);
            break;

        case 2:
            scanf("%d", &first);
            scanf("%d", &second);
            break;

        case 3:
            scanf("%d", &first);
            scanf("%d", &second);
            LongMultiply(&ln[first], &ln[second], &ln[i]);
            break;

        default:
            break;
        }
    }
    
    printf("1\n");
    //LongScan(&ln[0]);
    //LongScan(&ln[1]);
    //LongDop(&ln[2]);
    for (int i = 0; i < N; i++)
    {
        if (ln[i].arr[99] > 0)
        {
            printf("-");
        }

        LongPrint(&ln[i]);
    }

    free(ln);
    free(res);

    return 0;
}