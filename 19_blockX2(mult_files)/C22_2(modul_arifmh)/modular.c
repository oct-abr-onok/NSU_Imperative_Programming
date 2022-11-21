#include "modular.h"
#include "stdlib.h"

int MOD;

int pnorm(int a)
{
    a %= MOD;
    return (a >= 0 ? a : a + MOD);
}

int padd(int a, int b)
{
    a = pnorm(a);
    b = pnorm(b);
    int res = ((a % MOD) + (b % MOD)) % MOD;
    return (res >= 0 ? res : res + MOD);
}

int psub(int a, int b)
{
    a = pnorm(a);
    b = pnorm(b);
    int res = ((a % MOD) - (b % MOD)) % MOD;
    return (res >= 0 ? res : res + MOD);
}

int pmul(int a, int b)
{
    a = pnorm(a);
    b = pnorm(b);
    return pnorm((int)(((long long)a * (long long)b) % MOD));
}

int *euclid(int a, int m, int *res) //работает?!!
{
    int mem;
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

int inv(int a)
{
    int mem;
    int *res = malloc(sizeof(int) * 3);
    res = euclid(a, MOD, res);
    mem = res[1];
    free(res);
    return (mem >= 0 ? mem : mem + MOD);
}

int pdiv(int a, int b)
{
    a = pnorm(a);
    b = pnorm(b);
    int res = pmul(a, inv(b));
    return res;
}
