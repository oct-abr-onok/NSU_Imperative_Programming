#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MOD 1000000007

long long m_add(long long a, long long b, long long m)
{
    long long res = ((a % m) + (b % m)) % m;
    return (res >= 0 ? res : res + m);
}

long long m_sub(long long a, long long b, long long m)
{
    long long res = ((a % m) - (b % m)) % m;
    return (res >= 0 ? res : res + m);
}

long long m_mult(long long a, long long b, long long m)
{
    long long res = ((a % m) * (b % m)) % m;
    return (res >= 0 ? res : res + m);
}

long long *euclid(long long a, long long m, long long *res) //работает?!!
{
    long long mem;
    if (m == 0)
    {
        res[0] = a;
        res[1] = 1;
        res[2] = 0;
    }
    else
    {
        res = euclid(m, a % m, res); // x1 y1 (всё наоборот(Ловушка Гатилова))
        mem = res[1];
        res[1] = res[2];                 // x = y1 + (a / b) * y
        res[2] = mem - (a / m) * res[2]; // y = x1
    }
    return res;
}

long long inv(long long a, long long m)
{
    long long mem;
    long long *res = malloc(sizeof(long long) * 3);
    res = euclid(a, m, res);
    mem = res[1];
    free(res);
    return mem;
}

long long m_div(long long a, long long b, long long m)
{
    long long res = m_mult(a, inv(b, m), m);
    return (res >= 0 ? res : res + m);
}

long long *m_factorial(long long m, long long bound)
{
    long long *res = malloc(sizeof(long long) * bound);

    res[0] = 1;
    for (long long i = 1; i <= bound; i++)
    {
        res[i] = ((i % m) * res[i - 1]) % m;
    }

    return res;
}

int main(void)
{
    long long T, N, K;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%lld", &T); //читаем переменные из файла

    long long *m_factorials = m_factorial(MOD, 1000000); //считаем факториалы

    for (long long i = 0; i < T; i++)
    {
        scanf("%lld %lld", &N, &K);
        printf("%lld\n", m_div(m_factorials[N], m_mult(m_factorials[K], m_factorials[N - K], MOD), MOD));
    }

    return 0;
}