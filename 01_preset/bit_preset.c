#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fin = fopen("input.txt", "rb");
    FILE *fout = fopen("output.txt", "wb");

    //разметка
    int N;

    //читаем переменные из файла
    fread(&N, sizeof(int), 1, fin);
    fprintf(fout, "%d", N);

    //гарбач коллектор(-_-)
    fclose(fin);
    fclose(fout);
}