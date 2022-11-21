#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct DateTime_s
{
    int year, month, day;
    int hours, minutes, seconds;
} DateTime;

DateTime min(const DateTime *arr, int cnt)
{
    DateTime mem = {10000, 10000, 10000, 10000, 10000, 10000};
    long long min = 99999999999999, arr_mem;
    for (int i = 0; i < cnt; i++)
    {
        arr_mem = arr[i].seconds + arr[i].minutes * 100 + arr[i].hours * 10000 + arr[i].day * 1000000 + arr[i].month * 100000000 + arr[i].year * 10000000000;
        if (arr_mem < min) //приводим структуру к инту и сравниваем значения, чтобы не писать кучу ифов
        {
            mem = arr[i];
            min = arr_mem;
        }
    }

    return mem;
}

int main(void)
{
    int N;
    DateTime arr[50000], minDate;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &N); //читаем переменные из файла
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d %d %d %d %d", &arr[i].year, &arr[i].month, &arr[i].day, &arr[i].hours, &arr[i].minutes, &arr[i].seconds);
    }

    minDate = min(&arr[0], N); //выводим результат
    printf("%d %d %d %d %d %d", minDate.year, minDate.month, minDate.day, minDate.hours, minDate.minutes, minDate.seconds);

    return 0;
}