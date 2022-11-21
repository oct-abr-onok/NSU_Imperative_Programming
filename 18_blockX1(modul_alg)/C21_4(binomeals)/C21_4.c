#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

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
    long long test[3];
    long long *res = malloc(sizeof(long long) * 3);
    res = euclid(a, m, res);
    test[0] = res[0];
    test[1] = res[1];
    test[2] = res[2];
    return res[1];
}

long long m_div(long long a, long long b, long long m)
{
    ;
}

long long m_factorial(long long a, long long m)
{
    ;
}

int main(void)
{
    long long T, M, N, K, bin;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    //считываем данные
    scanf("%lld", &M);
    scanf("%lld", &T);

    for (int i = 0; i < T; i++)
    {
        //считываем данные
        scanf("%lld", &N);
        scanf("%lld", &K);

        //вычисление
        if (K < 0 || K > N)
        {
            bin = 0;
        }
        else
        {
            //T = inv(8, 999983);
        }

        //вывод
        printf("%lld", bin);
    }

    return 0;
}