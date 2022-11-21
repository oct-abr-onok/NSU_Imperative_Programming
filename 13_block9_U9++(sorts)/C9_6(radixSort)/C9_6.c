#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct el_s
{
    unsigned char key[4];
    unsigned int value;
} el;

unsigned int sumOfGistos(unsigned char curr, unsigned int *gisto)
{
    unsigned int sum = 0;
    for (int i = 0; i < curr; i++)
    {
        sum += gisto[i];
    }
    return sum;
}

int main(void)
{
    unsigned int N;
    unsigned int *gisto = calloc(256, sizeof(int));
    unsigned int *last = calloc(256, sizeof(int));

    FILE *fin = fopen("input.txt", "rb");
    FILE *fout = fopen("output.txt", "wb");

    fread(&N, sizeof(unsigned int), 1, fin);
    if (N != 0)
    {
        //читаем данные
        el *storage1 = calloc(N, sizeof(el));
        el *storage2 = calloc(N, sizeof(el));
        fread(storage1, sizeof(el), N, fin);

        //сортировка
        for (int radix = 0; radix < 4; radix++)
        {
            for (unsigned int i = 0; i < N; i++) //создаём гистограмму
            {
                gisto[storage1[i].key[radix]]++;
            }
            for (unsigned int i = 0; i < 256; i++)
            {
                last[i] = sumOfGistos(i, gisto);
            }

            for (unsigned int i = 0; i < N; i++) //перемещение storage1->storage2 в с сортированном по разряду виде
            {
                storage2[last[storage1[i].key[radix]]] = storage1[i];
                last[storage1[i].key[radix]]++;
            }

            for (unsigned int i = 0; i < 256; i++) //обнуление
            {
                gisto[i] = 0;
                last[i] = 0;
            }
            for (unsigned int i = 0; i < N; i++) //storage2->storage1
            {
                storage1[i] = storage2[i];
            }
        }

        //вывод
        fwrite(storage1, sizeof(el), N, fout);

        free(storage1);
        free(storage2);
    }

    free(last);
    free(gisto);
    fclose(fin);
    fclose(fout);
}