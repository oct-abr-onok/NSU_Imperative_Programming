#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int primes[1000000000000];

int main(void)
{
    int N, Q;
    long long mem;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &N); //читаем переменные из файла
    scanf("%d", &Q);

    primes[0] = 1; //решето
    primes[1] = 1;
    primes[2] = 0;
    for (int i = 2; i < N; i++)
    {
        if (!primes[i])
        {
            for (int j = 2; i * j <= N; j++)
            {
                primes[i * j] = 1;
            }
        }
    }

    for (int i = 0; i < Q; i++) //вывод
    {
        scanf("%lld", &mem);
        if (primes[mem])
        {
            printf("%d not\n", mem);
        }
        else
        {
            printf("%d prime\n", mem);
        }
    }

    return 0;
}