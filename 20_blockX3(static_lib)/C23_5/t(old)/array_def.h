#include <stdlib.h>
#include <string.h>
#define TCAT2(a, b) a##_##b
#define CAT2(a, b) TCAT2(a, b)

// initializes members of [vec] structure for empty array
void CAT2(NAME, init)(NAME *vec)
{
    vec->n = 0;
    vec->cap = 1;
    vec->arr = malloc(sizeof(TYPE));
}

// makes array [vec] empty and frees its array buffer [vec->arr]
// note: this function can be called many times
void CAT2(NAME, destroy)(NAME *vec)
{
    if (vec->arr != NULL)
    {
        vec->n = 0;
        vec->cap = 0;
        free(vec->arr);
        vec->arr = NULL;
    }
}

// adds element [value] to the end of array [vec]
// returns index of the added element
int CAT2(NAME, push)(NAME *vec, TYPE value)
{
    if (vec->arr == NULL)
    {
        CAT2(NAME, init)
        (vec);
    }

    if (vec->n == vec->cap)
    {
        if (vec->cap == 0)
        {
            vec->cap = 1;
            vec->arr = realloc(vec->arr, sizeof(TYPE));
        }
        else
        {
            vec->arr = realloc(vec->arr, vec->cap * 2 * sizeof(TYPE));
            vec->cap *= 2;
        }
    }
    vec->arr[vec->n++] = value;
    return (vec->n - 1);
}

// removes the last element from array [vec]
// returns removed element
TYPE CAT2(NAME, pop)(NAME *vec)
{
    if (vec->arr == NULL)
    {
        CAT2(NAME, init)
        (vec);
    }

    vec->n--;
    TYPE mem = vec->arr[vec->n];
    if (vec->n < 0)
    {
        vec->n = 0;
    }

    return mem;
}

// ensures that array [vec] has enough storage for [capacity] elements
// note: address of elements surely won’t change before [vec->n] exceeds capacity
void CAT2(NAME, reserve)(NAME *vec, int capacity)
{
    if (vec->arr == NULL)
    {
        CAT2(NAME, init)
        (vec);
    }

    if (vec->cap < capacity)
    {
        vec->arr = realloc(vec->arr, capacity * sizeof(TYPE));
        vec->cap = capacity;
    }
}

// changes number of elements in array [vec] to [newCnt]
// if the number increases, new elements get value [fill]
// if the number decreases, some elements at the end are removed
void CAT2(NAME, resize)(NAME *vec, int newCnt, TYPE fill)
{
    if (vec->arr == NULL)
    {
        CAT2(NAME, init)
        (vec);
    }

    if (newCnt > vec->n)
    {
        CAT2(NAME, reserve)
        (vec, newCnt);
        for (int i = vec->n; i < newCnt; i++)
            vec->arr[i] = fill;
    }
    vec->n = newCnt;
}

// inserts elements [arr[0]], [arr[1]], [arr[2]], ..., [arr[num-1]]
// in-between elements [vec->arr[where-1]] and [vec->arr[where]]
// note: the whole array [arr] cannot be part of array [vec]
//[where] may vary from 0 to [vec->n], [num] can also be zero
void CAT2(NAME, insert)(NAME *vec, int where, TYPE *arr, int num)
{
    CAT2(NAME, reserve)
    (vec, num + vec->n);
    //[vec->arr[where]] -->> (num)
    memmove(&(vec->arr[where + num]), &(vec->arr[where]), (vec->n - where) * sizeof(TYPE));
    vec->n += num;
    // inserts elements [arr[0]], [arr[1]], [arr[2]], ..., [arr[num-1]]
    memcpy(&(vec->arr[where]), arr, num * sizeof(TYPE));
}

// removes elements [vec->arr[k]] for k = [where], [where+1], ..., [where+num-1]
// all the elements starting from [where+num]-th are shifted left by [num] positions
void CAT2(NAME, erase)(NAME *vec, int where, int num)
{
    //[vec->arr[where+num]] <<-- (num)
    memmove(&(vec->arr[where]), &(vec->arr[where + num]), (vec->n - (where + num)) * sizeof(TYPE));

    vec->n -= num;
    if (vec->n < where)
        vec->n = where;
}