#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double binomeal[1001][1001];

int main(void)
{
    int Q;
    int n_mem, k_mem;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int n = 0; n <= 1000; n++) //заполняем края треугольника
    {
        binomeal[n][0] = 1;
        binomeal[n][n] = 1;
    }
    for (int n = 1; n <= 1000; n++) //считаем все коэффиценты
    {
        for (int k = 1; k <= n / 2 + 1; k++)
        {
            binomeal[n][k] = binomeal[n - 1][k] + binomeal[n - 1][k - 1];
            binomeal[n][n - k] = binomeal[n - 1][k] + binomeal[n - 1][k - 1];
        }
    }

    scanf("%d", &Q);            //читаем переменные из файла
    for (int i = 0; i < Q; i++) //выводим нужные
    {
        scanf("%d %d", &n_mem, &k_mem);
        printf("%0.10g\n", binomeal[n_mem][k_mem]);
    }

    return 0;
}