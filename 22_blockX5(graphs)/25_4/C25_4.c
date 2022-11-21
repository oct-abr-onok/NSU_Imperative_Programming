#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Vector_s
{
    int *arr;
    int cnt;
    int cap;
} Vector;

typedef struct my_res_s
{
    int *arr;
    int cnt;
    int cap;
} my_res;

my_res res;

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
    int color; // 0 - white, 1 - gray, 2 -balck
    Vector adj;
} Vertex;

int dfs(Vertex *vars, int x)
{
    if (vars[x].color == 1)
    {
        return -1;
    }
    else if (vars[x].color == 0)
    {
        vars[x].color = 1;
        for (int i = 0; i < vars[x].adj.cnt; i++)
        {
            if (dfs(vars, vars[x].adj.arr[i]) == -1)
                return -1;
        }
        res.arr[x] = ++res.cnt;
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

    res.cap = n;
    res.cnt = 0;
    res.arr = malloc(sizeof(int) * n);

    int from, to;
    Vertex *vars = calloc(n, sizeof(Vertex));
    int *is_nroot = calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        vars[i].adj.cap = 1;
        vars[i].adj.cnt = 0;
        vars[i].adj.arr = malloc(sizeof(int));
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &to, &from);
        from--;
        to--;
        is_nroot[to] = 1;
        push(&vars[from].adj, to);
    }

    for (int i = 0; i < n; i++)
    {
        if (is_nroot[i] == 0)
        {
            flag2++;
            if (dfs(vars, i) == -1)
                flag++;
        }
    }

    if (flag || !flag2 || res.cnt < n)
    {
        printf("NO\n");
    }
    else
    {
        printf("YES\n");
        for (int i = 0; i < res.cnt; i++)
        {
            printf("%d ", res.arr[i]);
        }
    }

    return 0;
}