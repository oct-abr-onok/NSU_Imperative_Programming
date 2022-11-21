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

typedef struct
{
    int dst;
    Vector adj;
} Vertex;

int main(void)
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N, M;
    scanf("%d %d", &N, &M);

    Vertex *graph = malloc(sizeof(Vertex) * N); //создаём граф
    for (int i = 0; i < N; i++)
    {
        graph[i].dst = -1;
        graph[i].adj.arr = malloc(sizeof(int));
        graph[i].adj.cnt = 0;
        graph[i].adj.cap = 1;
    }

    int from, to; //заносим дуги
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &from, &to);
        push(&graph[from - 1].adj, to - 1);
    }


    //обход bfs
    int Qsize;
    int *Qarr = malloc(sizeof(int) * N);

    graph[0].dst = 0;
    Qarr[0] = 0;
    Qsize = 1;

    for (int i = 0; i < Qsize; i++)
    {
        int u = Qarr[i];
        for (int j = 0; j < graph[u].adj.cnt; j++)
        {
            if (graph[graph[u].adj.arr[j]].dst == -1)
            {
                Qarr[Qsize++] = graph[u].adj.arr[j];
                graph[graph[u].adj.arr[j]].dst = graph[u].dst + 1;
            }
        }
    }

    //возвращаем значения
    for (int i = 0; i < N; i++)
    {
        printf("%d\n", graph[i].dst);
    }

    return 0;
}