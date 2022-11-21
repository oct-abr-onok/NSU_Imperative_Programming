#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int gcd(int a, int b)
{
    return (b == 0 ? a : gcd(b, a % b));
}

int main(void)
{
    int T, A, B;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &T); //читаем переменные из файла

    for (int i = 0; i < T; i++)
    {
        scanf("%d", &A);
        scanf("%d", &B);

        printf("%d\n", gcd(A, B));
    }

    return 0;
}