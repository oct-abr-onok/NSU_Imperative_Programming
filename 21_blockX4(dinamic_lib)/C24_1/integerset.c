#include "integerset.h"
#include <stdlib.h>

int int_cmp(const void *a, const void *b)
{
    int x = *(int *)a;
    int y = *(int *)b;
    if (x > y)
        return 1;
    else if (x == y)
        return 0;
    else
        return -1;
}

IntegerSet *CreateSet(int *arr, int cnt) //qsort
{
    IntegerSet *set = malloc(sizeof(IntegerSet));
    set->cnt = cnt;
    if (cnt == 0)
    {
        set->val = NULL;
    }
    else
    {
        set->val = calloc(set->cnt, sizeof(int));
        for (int i = 0; i < cnt; i++)
        {
            set->val[i] = arr[i];
        }

        qsort(set->val, set->cnt, sizeof(int), int_cmp); //сортировка массива

        for (int i = 1; i < cnt; i++) //проверка на одинаковые элементы
        {
            if (set->val[i] == set->val[i - 1])
            {
                return NULL;
            }
        }
    }

    return set;
}

int IsInSet(IntegerSet *set, int x) //bsearch
{
    if (set == NULL)
    {
        return 0;
    }
    else if (set->cnt == 0)
    {
        return 0;
    }
    else
    {
        if (bsearch(&x, set->val, set->cnt, sizeof(int), int_cmp) == NULL)
            return 0;
        else
            return 1;
    }
}