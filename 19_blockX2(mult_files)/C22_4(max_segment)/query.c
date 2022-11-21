#include <stdint.h>
#include <math.h>

extern int len;

long long Sum(int l, int r);

int Query(int l, int64_t sum)
{
    int centr, first = l, last = len, res = -1;

    while (1)
    {
        centr = (first + last) / 2;
        if (sum < Sum(l, centr))
        {
            last = centr;
        }
        else
        {
            if (sum == Sum(l, centr))
            {
                res = centr;
            }
            first = centr;
        }
        if (last - first < 2)
        {
            if (Sum(l, last) > sum)
                res = first;
            else
                res = last;

            return res;
        }
    }
}

//находит самый длинный отрезок с началом в l и суммой не более sum
//возвращает правый край искомого отрезка
/*int Query(int l, int64_t sum)
{
    for (int r = l; r <= len; r++)
    {
        if (Sum(l, r) > sum)
            return r - 1;
    }
    return len;
}*/