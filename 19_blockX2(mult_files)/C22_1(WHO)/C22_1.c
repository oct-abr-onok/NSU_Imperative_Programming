#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

long long m_add(long long a, long long b, long long m)
{
    long long res = ((a % m) + (b % m)) % m;
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

int main(void)
{
    long long k, P = 1, C, X = 0;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%lld", &k); //читаем переменные из файла
    long long *M = malloc(sizeof(long long) * k);
    long long *A = malloc(sizeof(long long) * k);
    for (long long i = 0; i < k; i++)
    {
        scanf("%lld", &M[i]);
    }
    for (long long i = 0; i < k; i++)
    {
        scanf("%lld", &A[i]);
    }

    //вычисления
    for (long long i = 0; i < k; i++)
    {
        P *= M[i];
    }
    for (long long i = 0; i < k; i++)
    {
        X += m_mult(inv(P / M[i], M[i]), A[i], M[i]) * (P / M[i]);
        //printf("%lld\n", inv(P / M[i], M[i]));
    }
    X = m_add(X, P, P);

    //вывод
    printf("%lld", X);

    return 0;
}