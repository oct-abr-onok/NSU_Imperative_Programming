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
    int color; // 0 - white, 1 - gray, 2 -balck
    Vector adj;
} Vertex;

int dfs(Vertex *vars, int x)
{
    int lres;
    if (vars[x].color == 1)
    {
        push(&res, x + 1);
        vars[x].color = 2;
        return -1;
    }
    else if (vars[x].color == 0)
    {
        vars[x].color = 1;
        for (int i = 0; i < vars[x].adj.cnt; i++)
        {
            lres = dfs(vars, vars[x].adj.arr[i]); 
            if (lres == -1)
            {
                if (vars[x].color == 2)
                    return -2;
                push(&res, x + 1);
                vars[x].color = 2;
                return -1;
            }
            else if (lres == -2)
            {
                return -2;
            }
        }
        vars[x].color = 2;
    }
    return 0;
}

int main(void)
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int m, n, flag = 0, flag2 = 0;
    scanf("%d %d", &n, &m);

    res.cap = 1;
    res.cnt = 0;
    res.arr = malloc(sizeof(int));

    int from, to;
    Vertex *vertx = calloc(n, sizeof(Vertex));
    for (int i = 0; i < n; i++)
    {
        vertx[i].adj.cap = 1;
        vertx[i].adj.cnt = 0;
        vertx[i].adj.arr = malloc(sizeof(int));
    }

    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &from, &to);
        from--;
        to--;
        push(&vertx[from].adj, to);
    }

    for (int i = 0; i < n; i++)
    {
        if (dfs(vertx, i) < 0)
        {
            printf("%d\n", res.cnt);
            for (int j = res.cnt - 1; j >= 0; j--)
            {
                printf("%d ", res.arr[j]);
            }
            return 0;
        }
    }

    printf("-1");

    return 0;
}