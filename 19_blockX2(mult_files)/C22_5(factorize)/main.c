#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//структура, в которой хранится разложение на простые множители
typedef struct Factors
{
    int k;          //сколько различных простых в разложении
    int primes[32]; //различные простые в порядке возрастания
    int powers[32]; //в какие степени надо эти простые возводить
} Factors;

void Factorize(int X, Factors *res);

int main(void)
{
    int M, X;
    Factors factor;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &M); //читаем переменные из файла
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &X);
        Factorize(X, &factor);
        printf("%d = ", X);
        if (factor.k == 0)
        {
            printf("1\n");
        }
        else
        {
            for (int j = 0; factor.k > 0; j++)
            {
                if (factor.primes[j] != 0)
                {
                    printf("%d^%d ", factor.primes[j], factor.powers[j]);
                }
                factor.k--;
                if (factor.k > 0)
                {
                    printf("* ");
                }
            }
            printf("\n");
        }
    }

    return 0;
}