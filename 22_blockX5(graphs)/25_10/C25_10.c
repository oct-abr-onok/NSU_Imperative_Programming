#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define min(a, b) (a < b ? a : b)

int int_cmp(const void *a, const void *b)
{
    int x = *(int *)a;
    int y = *(int *)b;
    if (x > y)
        return 1;
    else if (x == y)
        return 0;
    else
        return -1;
}

typedef struct
{
    int number;
    int from, to;
    int type; // 0 - undefined, 1 - root edge, 2 - back edge, -1 - deleted
} Edge;

typedef struct Vector_s
{
    Edge *arr;
    int cnt;
    int cap;
} Vector;

void push(Vector *V, Edge x)
{
    if (V->cnt == V->cap)
    {
        V->arr = realloc(V->arr, V->cap * 2 * sizeof(Edge));
        V->cap *= 2;
    }
    V->arr[V->cnt++] = x;
}

typedef struct Vector_i_s
{
    int *arr;
    int cnt;
    int cap;
} Vector_i;

void push_i(Vector_i *V, int x)
{
    if (V->cnt == V->cap)
    {
        V->arr = realloc(V->arr, V->cap * 2 * sizeof(int));
        V->cap *= 2;
    }
    V->arr[V->cnt++] = x;
}

Vector_i res;

typedef struct
{
    int up;
    int level;
    int color;
    int mark; // 0 - white, 1 - gray, 2 - balck
    Vector inc;
} Vertex;

void swap(int *a, int *b)
{
    int buf;
    buf = *a;
    *a = *b;
    *b = buf;
}

int edge_cmp(const void *a, const void *b)
{
    Edge x = *(Edge *)a;
    Edge y = *(Edge *)b;
    if (x.to > y.to || y.type != 0)
        return 1;
    else if (x.to == y.to)
        return 0;
    else
        return -1;
}

//вполне вероятно F{F{F{F{{F{F{F{F{F{{FFFFFFFF}}}}}}}}}}}
void edge_delete(Vertex *graph, int from, int to)
{
    int i;
    Edge *to_find = malloc(sizeof(Edge));
    to_find->from = from;
    to_find->to = to;
    qsort(graph[from].inc.arr, graph[from].inc.cnt, sizeof(Edge), edge_cmp);
    to_find = (Edge *)bsearch(to_find, graph[from].inc.arr, graph[from].inc.cnt, sizeof(Edge), edge_cmp);
    if (to_find != NULL && to_find->type == 0)
    {

        to_find->to = -1;
        to_find->type = -1;
    }
}

//не думаю
int up(Vertex *graph, int vertex_number)
{
    int min_s = INT_MAX;
    int min_l = INT_MAX;
    for (int i = 0; i < graph[vertex_number].inc.cnt; i++)
    {
        if (graph[graph[vertex_number].inc.arr[i].to].up < min_s && graph[vertex_number].inc.arr[i].type == 1)
        {
            
            min_s = graph[graph[vertex_number].inc.arr[i].to].up;
        }
        else if (graph[graph[vertex_number].inc.arr[i].to].level < min_l && graph[vertex_number].inc.arr[i].type == 2)
        {
            min_l = graph[graph[vertex_number].inc.arr[i].to].level;
        }
    }
    return min(min_s, min_l);
}

void dfs_modified(Vertex *graph, int vertex_number, int level, int last_call)
{
    if (graph[vertex_number].mark == 0)
    {
        graph[vertex_number].level = level;
        graph[vertex_number].mark = 1;
        for (int i = 0; i < graph[vertex_number].inc.cnt; i++)
        {
            if (graph[vertex_number].inc.arr[i].type != -1)
            {
                if (graph[graph[vertex_number].inc.arr[i].to].mark == 1)
                {
                    // if (graph[vertex_number].inc.arr[i].to != last_call)
                    graph[vertex_number].inc.arr[i].type = 2;
                    // else
                    //     graph[vertex_number].inc.arr[i].type = -1;
                }
                else
                {
                    graph[vertex_number].inc.arr[i].type = 1;
                }
                //удалить-_-(как\/)Щ
                edge_delete(graph, graph[vertex_number].inc.arr[i].to, graph[vertex_number].inc.arr[i].from);
                dfs_modified(graph, graph[vertex_number].inc.arr[i].to, level + 1, vertex_number);
                if (graph[graph[vertex_number].inc.arr[i].to].up >= graph[graph[vertex_number].inc.arr[i].to].level && graph[vertex_number].inc.arr[i].type == 1)
                {
                    push_i(&res, graph[vertex_number].inc.arr[i].number);
                }
            }
        }
        graph[vertex_number].up = up(graph, vertex_number);
        graph[vertex_number].mark = 2;
    }
}

/*void graph_null(Vertex *graph, int vrtx_cnt)
{
    for (int i = 0; i < vrtx_cnt; i++)
    {
        graph[i].level = 10;
        graph[i].mark = 0;
        graph[i].up = 0;
        for (int j = 0; j < graph[i].inc.cnt; j++)
        {
            graph[i].inc.arr[j].type = 0;
        }
    }
}*/

int main(void)
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N, M;
    scanf("%d %d", &N, &M);
    Vertex *vertx = calloc(N, sizeof(Vertex));
    for (int i = 0; i < N; i++)
    {
        vertx[i].inc.arr = malloc(sizeof(Edge));
        vertx[i].inc.cnt = 0;
        vertx[i].inc.cap = 1;
    }
    //считываем рёбра
    int from, to;
    Edge cur_edge;
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &from, &to);
        from--;
        to--;
        cur_edge.number = i + 1;
        cur_edge.from = from;
        cur_edge.to = to;
        cur_edge.type = 0;
        push(&vertx[cur_edge.from].inc, cur_edge);
        swap(&cur_edge.from, &cur_edge.to);
        push(&vertx[cur_edge.from].inc, cur_edge);
    }

    res.arr = malloc(sizeof(int));
    res.cnt = 0;
    res.cap = 1;

    for (int i = 0; i < N; i++)
    {
        if (vertx[i].color == 0)
            dfs_modified(vertx, i, 0, -1);
    }

    /*for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < vertx[i].inc.cnt; j++)
        {
            printf("%d %d type:%d\n", vertx[i].inc.arr[j].from, vertx[i].inc.arr[j].to, vertx[i].inc.arr[j].type);
        }
    }*/

    qsort(res.arr, res.cnt, sizeof(int), int_cmp); //оно?) да не...
    printf("%d\n", res.cnt);
    for (int i = 0; i < res.cnt; i++)
    {
        printf("%d ", res.arr[i]);
    }

    return 0;
}