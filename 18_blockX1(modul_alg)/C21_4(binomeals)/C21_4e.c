#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long long binomeal[2001][2001];

long long m_add(long long a, long long b, long long m)
{
    long long res = ((a % m) + (b % m)) % m;
    return (res >= 0 ? res : res + m);
}

int main(void)
{
    int T, M;
    int n_mem, k_mem;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d %d", &M, &T); //читаем переменные из файла

    for (int n = 0; n <= 2000; n++) //заполняем края треугольника
    {
        binomeal[n][0] = 1;
        binomeal[n][n] = 1;
    }
    for (int n = 1; n <= 2000; n++) //считаем все коэффиценты
    {
        for (int k = 1; k <= n / 2 + 1; k++)
        {
            binomeal[n][k] = m_add(binomeal[n - 1][k], binomeal[n - 1][k - 1], M);
            binomeal[n][n - k] = m_add(binomeal[n - 1][k], binomeal[n - 1][k - 1], M);
        }
    }

    for (int i = 0; i < T; i++) //выводим нужные
    {
        scanf("%d %d", &n_mem, &k_mem);
        if (k_mem > n_mem || k_mem < 0)
        {
            printf("0\n");
        }
        else
        {
            printf("%lld\n", binomeal[n_mem][k_mem]);
        }
    }

    return 0;
}