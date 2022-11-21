#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Vector_s
{
    int *arr;
    int cnt;
    int cap;
    int realCnt;
} Vector;

void push(Vector *V, int x)
{
    if (V->cnt == V->cap)
    {
        V->arr = realloc(V->arr, V->cap * 2 * sizeof(int));
        V->cap *= 2;
    }
    V->arr[V->cnt++] = x;
    V->realCnt++;
}

int isInRes(int *res, int resN, int x)
{
    for (int i = 0; i < resN; i++)
    {
        if (res[i] == x)
        {
            return 1;
        }
    }
    return 0;
}

void removeLec(int **lections, int *cnt, int lectionsN, int x)
{
    for (int i = 0; i < lectionsN; i++)
    {
        if (lections[i][x - 1] == 1)
        {
            cnt[i]--;
            lections[i][x - 1] = 0;
        }
    }
}

int main(void)
{
    FILE *fin = fopen("input.txt", "rt");
    FILE *fout = fopen("output.txt", "wt");

    int N, M, mem, curr_lec;

    //читаем переменные из файла
    fscanf(fin, "%d", &N);
    fscanf(fin, "%d", &M);

    //разметка
    int **lections = malloc(N * sizeof(int *));
    int *cnt = calloc(N, sizeof(int));
    int *res_gisto = calloc(N, sizeof(int));
    for (int i = 0; i < N; i++)
    {
        lections[i] = calloc(N, sizeof(int));
    }
    int *res = malloc(N * sizeof(int));
    int flag = N;

    //заносим зависимости
    for (int i = 0; i < M; i++)
    {
        fscanf(fin, "%d", &mem);
        fscanf(fin, "%d", &curr_lec);
        if (lections[curr_lec - 1][mem - 1] == 0)
        {
            lections[curr_lec - 1][mem - 1] = 1;
            cnt[curr_lec - 1]++;
        }
    }

    //сортировка по алгоритму Кана
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (cnt[j] == 0 && !res_gisto[j])
            {
                res[i] = j + 1;
                res_gisto[j] = 1;
                removeLec(lections, cnt, N, j + 1);
                flag--;
                break;
            }
        }
    }

    //вывод
    if (flag)
    {
        fprintf(fout, "bad course");
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            fprintf(fout, "%d ", res[i]);
        }
    }

    //проверка ДЛЯ СЕБЯ
    /*fprintf(fout, "\n");
    for (int i = 0; i < N; i++)
    {
        fprintf(fout, "%d\t", i + 1);
        for (int j = 0; j < N; j++)
        {
            fprintf(fout, "%d ", lections[i][j]);
        }
        fprintf(fout, "\n");
    }*/

    //важные всякие штуки
    for (int i = 0; i < N; i++)
    {
        free(lections[i]);
    }
    free(res_gisto);
    free(cnt);
    free(lections);
    free(res);
    fclose(fin);
    fclose(fout);
}