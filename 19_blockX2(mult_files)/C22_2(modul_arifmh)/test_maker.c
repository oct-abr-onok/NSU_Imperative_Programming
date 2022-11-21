#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "modular.h"
#define TEST_CNT 1000
#define PRIMES_CNT 1000000001

int is_prime(int *primes, int x)
{
    if (primes[x])
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int rand_prime(int *primes, int min, int max)
{
    int x;
    while (1)
    {
        x = min + ((rand() * rand()) % (max - min));
        if (is_prime(primes, x))
            return x;
    }
}

int main(void)
{
    int *primes = calloc(PRIMES_CNT, sizeof(int));
    primes[0] = 1; //решето
    primes[1] = 1;
    primes[2] = 0;
    for (int i = 2; i < PRIMES_CNT; i++)
    {
        if (!primes[i])
        {
            for (int j = 2; i * j <= PRIMES_CNT; j++)
            {
                primes[i * j] = 1;
            }
        }
    }

    srand(time(NULL));
    freopen("main.c", "w", stdout);

    printf("#include \"modular.h\" //в этом хедере должны быть объявления\n#include <assert.h>\n#include <stdio.h>\n\nint main()\n{\n");
    for (int i = 0; i < TEST_CNT; i++)
    {
        int prime = rand_prime(primes, 0, 50000000);
        MOD = prime;
        printf("\tMOD = %d; //light test #%d\n", prime, i + 1);
        int x = ((rand() * rand()) % 1000000001);
        if (rand() % 2)
        {
            x *= -1;
        }

        printf("\tassert(pnorm(%d) == %d);\n", x, pnorm(x));
        int a = (rand() * rand()) % prime;
        int b = (rand() * rand()) % prime;
        int c = ((rand() * rand()) % (prime - 1)) + 1;
        printf("\tassert(padd(%d, %d) == %d);\n", a, b, padd(a, b));
        printf("\tassert(psub(%d, %d) == %d);\n", a, b, psub(a, b));
        printf("\tassert(pmul(%d, %d) == %d);\n", a, b, pmul(a, b));
        printf("\tassert(pdiv(%d, %d) == %d);\n\n", a, c, pdiv(a, c));
    }


    for (int i = 0; i < 20; i++)
    {
        int prime = rand_prime(primes, 999999000, 1000000000);
        MOD = prime;
        printf("\tMOD = %d; //hard test #%d\n", prime, i + 1);
        int x = ((rand() * rand()) % 1000000001);
        if (rand() % 2)
        {
            x *= -1;
        }

        printf("\tassert(pnorm(%d) == %d);\n", x, pnorm(x));
        int a = (rand() * rand()) % prime;
        int b = (rand() * rand()) % prime;
        int c = ((rand() * rand()) % (prime - 1)) + 1;
        printf("\tassert(padd(%d, %d) == %d);\n", a, b, padd(a, b));
        printf("\tassert(psub(%d, %d) == %d);\n", a, b, psub(a, b));
        printf("\tassert(pmul(%d, %d) == %d);\n", a, b, pmul(a, b));
        printf("\tassert(pdiv(%d, %d) == %d);\n\n", a, c, pdiv(a, c));
    }
    printf("\treturn 0;\n}");

    return 0;
}