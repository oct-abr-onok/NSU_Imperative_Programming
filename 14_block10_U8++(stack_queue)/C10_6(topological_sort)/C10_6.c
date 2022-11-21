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

void removeLec(Vector **lections, int lectionsN, int x)
{
    for (int i = 0; i < lectionsN; i++)
    {
        for (int j = 0; j < lections[i]->cnt; j++)
        {
            if (lections[i]->arr[j] == x)
            {
                lections[i]->arr[j] = 0;
                lections[i]->realCnt--;
            }
        }
    }
}

int main(void)
{
    FILE *fin = fopen("input.txt", "rt");
    FILE *fout = fopen("output.txt", "wt");

    int N, M, cur_lec, mem, flag;

    //читаем переменные из файла
    fscanf(fin, "%d", &N);
    fscanf(fin, "%d", &M);

    //разметка
    Vector **lections = malloc(sizeof(Vector *) * N);
    flag = N;
    for (int i = 0; i < N; i++)
    {
        lections[i] = malloc(sizeof(Vector));
        lections[i]->arr = calloc(1, sizeof(int));
        lections[i]->cnt = 0;
        lections[i]->realCnt = 0;
        lections[i]->cap = 1;
    }
    int *res = calloc(N, sizeof(int));

    //ячейка с массива с индексом cur_lec хранит номера лекций, от которых зависит лекция cur_lec + 1
    for (int i = 0; i < M; i++)
    {
        fscanf(fin, "%d", &mem);
        fscanf(fin, "%d", &cur_lec);
        push(lections[cur_lec - 1], mem);
    }

    //сортировка по алгоритму Кана
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (lections[j]->realCnt == 0 && !isInRes(res, N, j + 1))
            {
                res[i] = j + 1;
                removeLec(lections, N, j + 1);
                flag--;
                break;
            }
        }
    }

    //ПРОВЕРКА ДЛЯ СЕБЯ
    /*for (int i = 0; i < N; i++)
    {
        fprintf(fout, "%d\t", i + 1);
        for (int j = 0; j < lections[i]->cnt; j++)
        {
            fprintf(fout, "%d ", lections[i]->arr[j]);
        }
        fprintf(fout, "\n");
    }*/

    //вывод;
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

    for (int i = 0; i < N; i++)
    {
        free(lections[i]->arr);
        free(lections[i]);
    }
    free(lections);
    free(res);
    fclose(fin);
    fclose(fout);
}