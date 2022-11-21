#include "sol.h"
#include <stdlib.h>
#include <stdio.h>

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

typedef struct
{
    int inc_cnt;
    Vector *inc_edge;
} Incidents;

Incidents *incidents;

Edge edge_reverse(Edge edge)
{
    Edge rev_edge;
    rev_edge.from = edge.to;
    rev_edge.to = edge.from;
    rev_edge.weight = edge.weight;
    return rev_edge;
}

void init()
{
    int N = getVerticesCount();
    Edge *cur_edge = malloc(sizeof(Edge));
    incidents = calloc(N, sizeof(Incidents));
    for (int i = 0; i < N; i++)
    {
        incidents[i].inc_edge = malloc(sizeof(Vector)); //заводим массивы
        incidents[i].inc_edge->cap = 1;
        incidents[i].inc_edge->cnt = 0;
        incidents[i].inc_edge->arr = malloc(sizeof(Edge));
    }

    for (int i = 0; readEdge(cur_edge) != 0; i++)
    {
        incidents[cur_edge->from].inc_cnt++;
        push(incidents[cur_edge->from].inc_edge, *cur_edge);
        incidents[cur_edge->to].inc_cnt++;
        push(incidents[cur_edge->to].inc_edge, edge_reverse(*cur_edge));
    }
}

int getEdgesCount(int iVertex)
{
    return incidents[iVertex].inc_cnt;
}

Edge getIncidentEdge(int iVertex, int iIndex)
{
    return incidents[iVertex].inc_edge->arr[iIndex];
}

///////////////////////////
/*
int cur = 0;

static int getVerticesCount()
{
    return 5;
}

static int readEdge(Edge *oEdge)
{
    switch (cur)
    {
    case 0:
        oEdge->from = 0;
        oEdge->to = 2;
        oEdge->weight = 178;
        break;
    case 1:
        oEdge->from = 3;
        oEdge->to = 4;
        oEdge->weight = 207;
        break;
    case 2:
        oEdge->from = 1;
        oEdge->to = 1;
        oEdge->weight = 356;
        break;
    case 3:
        oEdge->from = 2;
        oEdge->to = 0;
        oEdge->weight = 101;
        break;
    case 4:
        oEdge->from = 4;
        oEdge->to = 1;
        oEdge->weight = 286;
        break;
    case 5:
        oEdge->from = 4;
        oEdge->to = 1;
        oEdge->weight = 213;
        break;

    default:
        return 0;
        break;
    }
    cur++;
    return 1;
}

void printEdge(Edge edge)
{
    printf("[%d, %d, %d]\n", edge.from, edge.to, edge.weight);
}

void main(void)
{
    Edge edg;
    init();
    printf("%d\n", getEdgesCount(0));
    printEdge(getIncidentEdge(0, 0));
    printEdge(getIncidentEdge(0, 1));

    printf("%d\n", getEdgesCount(1));
    printEdge(getIncidentEdge(1, 0));
    printEdge(getIncidentEdge(1, 3));
    printEdge(getIncidentEdge(1, 2));
    printEdge(getIncidentEdge(1, 1));

    printf("%d\n", getEdgesCount(2));
    printEdge(getIncidentEdge(2, 0));
    printEdge(getIncidentEdge(2, 1));

    printf("%d\n", getEdgesCount(3));
    printEdge(getIncidentEdge(3, 0));

    printf("%d\n", getEdgesCount(4));
    printEdge(getIncidentEdge(4, 2));
    printEdge(getIncidentEdge(4, 0));
    printEdge(getIncidentEdge(4, 1));
}
*/