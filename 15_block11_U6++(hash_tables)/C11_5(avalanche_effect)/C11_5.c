#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
//
//32 767

unsigned long long A, B, M, R, S;
unsigned int hashFunc(unsigned int x)
{
    return (((A * x + B) % M) % R) / S;
}

unsigned int rand_32(void)
{
    int mem = 0;
    mem += (unsigned int)rand();
    mem = mem << 17;
    mem += (unsigned int)rand();
    return mem;
}

void tst(double *table, unsigned int i)
{
    unsigned int bit_i = 1 << i, bit_o, hash_unch, hash_ch, num_unch, num_ch;
    double cnt_t = 100000;
    for (int k = 0; k < cnt_t; k++)
    {
        num_unch = rand_32();
        num_ch = num_unch ^ bit_i;
        hash_unch = hashFunc(num_unch);
        hash_ch = hashFunc(num_ch);
        for (int j = 0; j < 32; j++)
        {
            bit_o = 1 << j;
            if ((bit_o & hash_unch) != (bit_o & hash_ch))
            {
                table[j] += 1;
            }
        }
    }

    for (int j = 0; j < 32; j++)
    {
        table[j] /= cnt_t;
    }
}

int main(void)
{
    FILE *fin = fopen("input.txt", "rt");
    FILE *fout = fopen("output.txt", "wt");

    //разметка
    double table[32][32] = {0};
    double percents = 0;

    //читаем переменные из файла
    fscanf(fin, "%llu", &A);
    fscanf(fin, "%llu", &B);
    fscanf(fin, "%llu", &M);
    fscanf(fin, "%llu", &R);
    fscanf(fin, "%llu", &S);

    //считаем лавинный эффект
    for (unsigned int i = 0; i < 32; i++)
    {
        srand(time(NULL));
        tst(table[i], i);
    }

    //вывод
    for (int i = 0; i < 32; i++)
    {
        for (int j = 0; j < 32; j++)
        {
            table[i][j] *= 100;
            table[i][j] = round(table[i][j]);
            fprintf(fout, "%3d ", (int)table[i][j]);
        }
        fprintf(fout, "\n");
    }

    //гарбач коллектор-_-
    fclose(fin);
    fclose(fout);
}