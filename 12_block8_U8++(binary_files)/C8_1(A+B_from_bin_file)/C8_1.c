#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a, b, t = INT_MAX;
    long long sum;

    FILE *fi = fopen("input.txt", "rb");
    FILE *fo = fopen("output.txt", "wb");

    fread(&a, sizeof(int), 1, fi); //читаем переменные из файла
    fread(&b, sizeof(int), 1, fi);

    sum = (long long)a + (long long)b;
    if (sum >= 0) //округление вниз
    {
        sum /= 2;
    }
    else
    {
        if (sum % 2 != 0)
        {
            sum /= 2;
            sum--;
        }
        else
        {
            sum /= 2;
        }
    }

    if (sum == 0 && a < 0 && b < 0) //крайние случаи
    {
        sum = INT_MIN;
    }

    fwrite(&sum, sizeof(int), 1, fo);

    fclose(fi);
    fclose(fo);
    return 0;
}