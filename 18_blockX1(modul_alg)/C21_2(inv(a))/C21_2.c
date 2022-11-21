#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int quick_int_pow(int a, int ind)
{
    int res = 1;

    for (int i = 0; i < 16; i++)
    {
        if ((ind & (1 << i)) > 0)
        {
            res *= a;
        }
        a *= a;
    }
    return res;
}

long long quick_long_mod_pow(long long a, long long ind, long long m)
{
    long long res = 1;

    for (int i = 0; i < 32; i++)
    {
        if ((ind & (1 << i)) > 0)
        {
            res *= a;
            res %= m;
        }
        a *= a;
        a %= m;
    }
    return res;
}

int main(void)
{
    long long T, M, A, B;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%lld", &T); //читаем переменные из файла
    scanf("%lld", &M);

    //код программы
    for (long long i = 0; i < T; i++)
    {
        scanf("%lld", &A);
        if (A == 0) //проверка на деление на 0
        {
            B = -1;
        }
        else
        {
            B = quick_int_mod_pow(A, (M - 2), M);
        }
        printf("%lld\n", B);
    }

    return 0;
}