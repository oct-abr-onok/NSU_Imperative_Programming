#include "primes.h"
#include <stdlib.h>
#define MAX_X 10010000

static int erathosphen_flag = 0;
static int init_flag = 0;
static int primes[MAX_X + 1];

//считает протые до числа (возможно не нужна, findNextPrime может выполнять эту функцию)
static void erathosphen(void)
{
    primes[0] = 1;
    primes[1] = 1;
    primes[2] = 0;
    for (int i = 2; i <= MAX_X; i++)
        if (!primes[i])
            for (int j = 2; i * j <= MAX_X; j++)
                primes[i * j] = 1;

    erathosphen_flag = 1;
}

static int init_arr[MAX_X + 1];

static int invert(int x)
{
    return x == 0 ? 1 : 0;
}

//выполнить подготовку массива: запускается один раз перед запусками Sum
//здесь arr[0..n) –- это массив A из входного файла
static void Init( int n)
{
    init_arr[0] = 0;
    init_arr[1] = invert(primes[0]);
    for (int i = 2; i < n + 1; i++)
    {
        init_arr[i] = invert(primes[i - 1]) + init_arr[i - 1];
    }
    init_flag = 1;
}

//найти сумму элементов A на отрезке [l..r)
//использует данные, посчитанные функцией Init
static int Sum(int l, int r)
{
    return init_arr[r] - init_arr[l]; //уточнить
}


// returns: 1 if x is prime number, 0 otherwise
int isPrime(int x)
{
    //досчитать решето
    if (!erathosphen_flag)
    {
        erathosphen();
    }

    return primes[x] == 0 ? 1 : 0;
}

// returns minimal prime number p such that p >= x
int findNextPrime(int x)
{
    //досчитать решето
    if (!erathosphen_flag)
    {
        erathosphen();
    }

    //ищем следующее простое
    for (int i = x; i <= MAX_X; i++)
    {
        if (primes[i] == 0)
            return i;
    }
    return 0;
}

// returns the number of primes x such that l <= x < r
int getPrimesCount(int l, int r)
{
    //досчитать решето
    if (!erathosphen_flag)
    {
        erathosphen();
    }

    if (!init_flag)
        Init(MAX_X);

    return Sum(l, r);
}