#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Vector_s
{
    int *arr;
    int cnt;
    int cap;
} Vector;

void push(Vector *V, int x)
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

    //читаем переменные из файла
    fscanf(fin, "%d", &N);
    int **matrix = malloc(N * sizeof(int *)); //создаём матрицу O(N^2)
    Vector *base = malloc(N * sizeof(Vector));
    for (int i = 0; i < N; i++)
    {
        base[i].cap = 1;
        base[i].cnt = 0;
        base[i].arr = malloc(sizeof(int));
        matrix[i] = malloc(N * sizeof(int));
    }
    for (int i = 0; i < N; i++) //сканируем матрицу
    {
        for (int j = 0; j < N; j++)
        {
            fscanf(fin, "%1d", &matrix[i][j]);
            if (matrix[i][j] == 1)
            {
                push(&base[i], j);
            }
        }
    }

    //вывод ДЛЯ СЕБЯ
    /*for (int i = 0; i < N; i++)
    {
        fprintf(fout, "%d\t", i);
        for (int j = 0; j < base[i].cnt; j++)
        {
            fprintf(fout, "%d ", base[i].arr[j]);
        }
        fprintf(fout, "\n");
    }*/

    //установка транзитивности O(N^3) (использовать bsearch для N^2 * log N)
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < base[i].cnt; j++)
        {
            for (int k = 0; k < base[base[i].arr[j]].cnt; k++)
            {
                if (!matrix[i][base[base[i].arr[j]].arr[k]])
                {
                    matrix[i][base[base[i].arr[j]].arr[k]] = 1;
                    push(&base[i], base[base[i].arr[j]].arr[k]);
                }
            }
        }
    }

    //установка рефлексивности O(N)
    for (int i = 0; i < N; i++)
    {
        matrix[i][i] = 1;
    }

    //вывод O(N^2)
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            fprintf(fout, "%d", matrix[i][j]);
        }
        fprintf(fout, "\n");
    }

    for (int i = 0; i < N; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
    fclose(fin);
    fclose(fout);
}