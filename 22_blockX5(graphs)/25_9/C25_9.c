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

Vector res;

typedef struct
{
    int color;
    int mark; // 0 - white, 1 - gray, 2 -balck
    Vector adj;
} Vertex;

int dfs(Vertex *vars, int x)
{
    if (vars[x].mark == 0)
    {
        vars[x].mark = 1;
        for (int i = 0; i < vars[x].adj.cnt; i++)
        {
            dfs(vars, vars[x].adj.arr[i]);
        }
        push(&res, x);
        vars[x].mark = 2;
    }
    return 0;
}

int dfs_color(Vertex *vars, int x, int color)
{
    if (vars[x].mark == 0)
    {
        vars[x].mark = 1;
        for (int i = 0; i < vars[x].adj.cnt; i++)
        {
            dfs_color(vars, vars[x].adj.arr[i], color);
        }
        vars[x].color = color;
        vars[x].mark = 2;
        return 1;
    }
    else
    {
        return 0;
    }
}

int main(void)
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int m, n, flag = 0, color = 1;
    scanf("%d %d", &n, &m);

    res.cap = 1;
    res.cnt = 0;
    res.arr = malloc(sizeof(int));

    int *from = malloc(sizeof(int) * m);
    int *to = malloc(sizeof(int) * m);

    Vertex *vertx = calloc(n, sizeof(Vertex));
    for (int i = 0; i < n; i++)
    {
        vertx[i].adj.cap = 1;
        vertx[i].adj.cnt = 0;
        vertx[i].adj.arr = malloc(sizeof(int));
    }

    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &from[i], &to[i]);
        from[i]--;
        to[i]--;
        push(&vertx[from[i]].adj, to[i]);
    }

    // 1
    for (int i = 0; i < n; i++)
    {
        dfs(vertx, i);
    }

    // 2
    for (int i = 0; i < n; i++)
    {
        free(vertx[i].adj.arr);
        vertx[i].adj.cap = 1;
        vertx[i].adj.cnt = 0;
        vertx[i].adj.arr = malloc(sizeof(int));
    }
    for (int i = 0; i < m; i++)
    {
        push(&vertx[to[i]].adj, from[i]);
    }

    // 3
    for (int i = 0; i < n; i++)
    {
        vertx[i].mark = 0;
    }

    // 4
    for (int i = res.cnt - 1; i >= 0; i--)
    {
        color += dfs_color(vertx, res.arr[i], color);
    }

    printf("%d\n", color - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vertx[i].color);
    }

    return 0;
}