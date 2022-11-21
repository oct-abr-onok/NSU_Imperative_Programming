#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fin = fopen("input.txt", "rt");
    FILE *fout = fopen("output.txt", "wt");

    int N;

    //читаем переменные из файла
    fscanf(fin, "%d", &N);
    int **matrix = malloc(N * sizeof(int *)); //создаём матрицу
    for (int i = 0; i < N; i++)
    {
        matrix[i] = malloc(N * sizeof(int));
    }
    for (int i = 0; i < N; i++) //сканируем матрицу
    {
        for (int j = 0; j < N; j++)
        {
            fscanf(fin, "%1d", &matrix[i][j]);
        }
    }

    //установка рефлексивности
    for (int i = 0; i < N; i++)
    {
        matrix[i][i] = 1;
    }

    //установка транзитивности
    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (matrix[i][k] == 1 && matrix[k][j] == 1)
                {
                    matrix[i][j] = 1;
                    continue;
                }
            }
        }
    }

    //вывод
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