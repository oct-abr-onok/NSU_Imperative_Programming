#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define ACCURACY 0.0000000000001

long long factorial(long long arg)
{
    if (arg == 0 || arg == 1)
    {
        return 1;
    }
    else
    {
        return arg * factorial(arg - 1);
    }
}

double expon(double arg, long long pow)
{
    double res = 1;
    for (; pow > 0; pow--)
    {
        res *= arg;
    }
    return res;
}

double absol(double arg)
{
    return arg < 0 ? -arg : arg;
}

int main(void)
{
    FILE *fin = fopen("input.txt", "rt");
    FILE *fout = fopen("output.txt", "wt");

    int N;
    double arg, val, addval = 1;

    fscanf(fin, "%d", &N);
    for (int i = 0; i < N; i++)
    {
        val = 0;
        addval = 1;
        fscanf(fin, "%lf", &arg);
        for (long long k = 0; /* absol(addval) > ACCURACY */ k < 100; k++) //ряд Тейлора
        {
            addval = expon(-1, k) * expon(arg, 2 * k + 1) / (double)factorial(2 * k + 1);
            val += addval; 
        }
        fprintf(fout, "%0.15lf\n", val); //вывод результата
    }

    fclose(fin);
    fclose(fout);
}