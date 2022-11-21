#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "primes.h"
#define TEST_CNT 1000
#define T_MAX 10000001

void swap(int *a, int *b)
{
    int mem = *a;
    *a = *b;
    *b = mem;
}

int main(void)
{
    srand(time(NULL));
    freopen("main.c", "w", stdout);

    printf("#include \"primes.h\"\n#include <assert.h>\n#include <stdio.h>\n\nint main()\n{\n");
    for (int i = 0; i < TEST_CNT; i++)
    {
        //переменные для тестов
        int x = (rand() * rand()) % T_MAX;
        int l = (rand() * rand()) % T_MAX;
        int r = (rand() * rand()) % T_MAX;
        if (l > r)
            swap(&l, &r);

        //тесты
        printf("\t//test #%d\n", i + 1);
        printf("\tassert(isPrime(%d) == %d);\n", x, isPrime(x));
        printf("\tassert(getPrimesCount(%d, %d) == %d);\n", l, r, getPrimesCount(l, r));
        printf("\tassert(findNextPrime(%d) == %d);\n\n", x, findNextPrime(x));
    }
    //cпециальные тесты
    for (int i = 0; i < 10; i++)
    {
        //переменные для тестов
        int x = rand() % 3;
        int l = (rand() * rand()) % T_MAX;
        int r = l;
        if (l > r)
            swap(&l, &r);

        //тесты
        printf("\t//special test #%d\n", i + 1);
        printf("\tassert(isPrime(%d) == %d);\n", x, isPrime(x));
        printf("\tassert(getPrimesCount(%d, %d) == %d);\n", l, r, getPrimesCount(l, r));
        printf("\tassert(findNextPrime(%d) == %d);\n\n", x, findNextPrime(x));
    }
    //cпециальные тесты 2
    for (int i = 0; i < 10; i++)
    {
        //переменные для тестов
        int x = (rand() % 2) * 10000000;
        int l = (rand() % 2) * 10000000;
        int r = (rand() % 2) * 10000000;
        if (l > r)
            swap(&l, &r);

        //тесты
        printf("\t//special test2 #%d\n", i + 1);
        printf("\tassert(isPrime(%d) == %d);\n", x, isPrime(x));
        printf("\tassert(getPrimesCount(%d, %d) == %d);\n", l, r, getPrimesCount(l, r));
        printf("\tassert(findNextPrime(%d) == %d);\n\n", x, findNextPrime(x));
    }

    printf("\treturn 0;\n}");

    return 0;
}