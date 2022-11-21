#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define min(a, b) a < b ? a : b

typedef struct node_s
{
    int flow;
    int cap;
} node;

typedef struct vert_s
{
    int mark;
    int f;
} vert;

int main(void)
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N, K;
    scanf("%d %d", &N, &K);

    node **matrix = calloc(N, sizeof(node *));
    for (int i = 0; i < N; i++)
    {
        matrix[i] = calloc(N, sizeof(node));
    }

    int from, to;
    for (int i = 0; i < K; i++)
    {
        scanf("%d %d", &from, &to);
        scanf(" %d", &matrix[from - 1][to - 1].cap);
        matrix[to - 1][from - 1].cap = matrix[from - 1][to - 1].cap;
    }

    vert *nodes = calloc(N, sizeof(vert));
    int flow = 0;
    while (1)
    {
        // part1: BFS
        for (int i = 1; i < N; i++)
        {
            nodes[i].mark = 0;
        }
        nodes[0].mark = 1;
        int Qsize = 1;
        int *Qarr = malloc(sizeof(int) * N);
        Qarr[0] = 0;
        for (int i = 0; i < Qsize; i++)
        {
            int u = Qarr[i];
            for (int j = 0; j < N; j++)
            {
                if (matrix[u][j].cap - matrix[u][j].flow > 0 && !nodes[j].mark) //проверяем cf(uv) -- остаточную проп. спос-сть
                {
                    nodes[j].mark = 1;
                    Qarr[Qsize++] = j;
                    nodes[j].f = u;
                }
            }
        }

        if (nodes[N - 1].mark == 0)
        {
            break; //нет дополняющего пути
        }

        // part2: how much?
        int CP = INT_MAX;
        int x = N - 1;
        while (x != 0)
        {
            int y = nodes[x].f;
            CP = min(CP, matrix[y][x].cap - matrix[y][x].flow);
            x = y;
        }

        // part 3: push flow
        x = N - 1;
        while (x != 0)
        {
            int y = nodes[x].f;
            matrix[y][x].flow += CP;
            matrix[x][y].flow -= CP;
            x = y;
        }
    }

    for (int i = 0; i < N; i++)
    {
        flow += matrix[i][N - 1].flow;
    }

    printf("%d", flow);

    return 0;
}