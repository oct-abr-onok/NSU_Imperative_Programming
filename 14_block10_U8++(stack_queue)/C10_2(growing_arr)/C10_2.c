#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SIZEOF_ARR 1000001

typedef struct Vector_s
{
    char **arr;
    int cnt;
    int cap;
} Vector;

void push(Vector *V, char *x)
{
    if (V->cnt == V->cap)
    {
        V->arr = realloc(V->arr, V->cap * 2 * sizeof(int));
        V->cap *= 2;
    }
    V->arr[V->cnt++] = x;
}

int main(void)
{
    FILE *fin = fopen("input.txt", "rt");
    FILE *fout = fopen("output.txt", "wt");

    int N, mem;
    Vector *storage = malloc(sizeof(Vector) * SIZEOF_ARR); //заводим массивы
    for (int i = 0; i < SIZEOF_ARR; i++)
    {
        storage[i].cap = 1;
        storage[i].cnt = 0;
        storage[i].arr = malloc(sizeof(char *));
    }

    //заносим значения в массивы
    fscanf(fin, "%d", &N);
    for (int i = 0; i < N; i++)
    {
        fscanf(fin, "%d", &mem);
        fscanf(fin, " ");
        char *mems = calloc(8, sizeof(char));
        fscanf(fin, "%s", mems);
        push(&storage[mem], &mems[0]);
    }

    //вывод
    for (int i = 0; i < SIZEOF_ARR; i++)
    {
        for (int j = 0; j < storage[i].cnt; j++)
        {
            fprintf(fout, "%d ", i);
            fprintf(fout, "%s", storage[i].arr[j]);
            free(storage[i].arr[j]);
            fprintf(fout, "\n");
        }
    }

    //гарбач коллектор -_-
    for (int i = 0; i < SIZEOF_ARR; i++)
    {
        free(storage[i].arr);
    }
    free(storage);
    fclose(fin);
    fclose(fout);
}