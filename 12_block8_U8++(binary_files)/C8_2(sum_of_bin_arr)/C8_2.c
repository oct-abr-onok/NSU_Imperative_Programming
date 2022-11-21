#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N, be_sum = 0, le_sum = 0, real_N = 0, le_mem = 0, be_mem = 0;
    unsigned char mem;

    FILE *fi = fopen("input.txt", "rb");
    FILE *fo = fopen("output.txt", "wb");

    fread(&N, sizeof(int), 1, fi); //читаем переменные из файла

    while (fread(&mem, sizeof(char), 1, fi)) //считаем сумму для big-endian и little-endian
    {
        le_mem += (int)mem * (1 << (8 * (real_N % 4)));
        be_mem += (int)mem * (1 << (8 * (3 - (real_N % 4))));
        if (real_N % 4 == 3)
        {
            le_sum += le_mem;
            be_sum += be_mem;
            le_mem = 0;
            be_mem = 0;
        }
        real_N++;
    }
    real_N /= 4;

    if (real_N == N) //выбираем, какой ответ выводить
    {
        fwrite(&le_sum, sizeof(int), 1, fo);
    }
    else //вывод в формате big-endian
    {
        char byte_mem;
        for (int i = 3; i >= 0; i--)
        {
            byte_mem = 0;
            for (int j = 0; j < 8; j++)
            {
                byte_mem += (be_sum & (1 << (i * 8 + j))) >> (i * 8);
            }
            fwrite(&byte_mem, sizeof(char), 1, fo);
        }
    }

    fclose(fi);
    fclose(fo);
    return 0;
}