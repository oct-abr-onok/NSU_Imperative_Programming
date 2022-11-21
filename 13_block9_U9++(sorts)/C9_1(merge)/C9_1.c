#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//merges sorted arrays a[0..ak-1] and b[0..bk-1] into
//one sorted array res[0..rk-1], returning rk from function
int merge(const int *a, int ak, const int *b, int bk, int *res)
{
    int i = 0, j = 0;
    for (; i + j < ak + bk;)
    {
        if (a[i] <= b[j])
        {
            if (i == ak)
            {
                res[i + j] = b[j];
                j++;
            }
            else
            {
                res[i + j] = a[i];
                i++;
            }
        }
        else
        {
            if (j == bk)
            {
                res[i + j] = a[i];
                i++;
            }
            else
            {
                res[i + j] = b[j];
                j++;
            }
        }
    }

    return ak + bk;
}

int main(void)
{
    int N, M;

    FILE *fi = fopen("input.txt", "rb");
    FILE *fo = fopen("output.txt", "wb");

    //читаем переменные из файла
    fread(&N, sizeof(int), 1, fi);
    fread(&M, sizeof(int), 1, fi);

    //слияние
    int *a = malloc(N * sizeof(int));
    int *b = malloc(M * sizeof(int));
    int *res = malloc((N + M) * sizeof(int));
    fread(a, sizeof(int), N, fi);
    fread(b, sizeof(int), M, fi);

    merge(a, N, b, M, res);

    //вывод
    fwrite(res, sizeof(int), N + M, fo);

    free(a);
    free(b);
    free(res);
    fclose(fi);
    fclose(fo);
}