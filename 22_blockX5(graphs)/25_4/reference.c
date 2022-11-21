#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

typedef struct Node_s
{
    int to;
    struct Node_s *next;
} Node;

void addNode(Node **list, int index, int path_to)
{
    Node *tmp = list[index];
    if (tmp == NULL)
    {
        list[index] = calloc(1, sizeof(Node));
        list[index]->next = NULL;
        list[index]->to = path_to;
    }
    else
    {
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = calloc(1, sizeof(Node));
        tmp->next->to = path_to;
    }
}

int funct(Node **list, int index, int size, int *colors, int result, int *result_list)
{
    colors[index] = 1;

    Node *tmp = list[index];
    while ((tmp != NULL) && (result != -2))
    {
        if (colors[tmp->to] == 0)
        {
            result = funct(list, tmp->to, size, colors, result, result_list);
        }
        else if (colors[tmp->to] == 1)
        {
            return -2;
        }
        if (result == -2)
        {
            return -2;
        }
        tmp = tmp->next;
    }
    result_list[index] = result;
    colors[index] = 2;

    return result - 1;
}

int main(void)
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m;

    scanf("%d %d\n", &n, &m);
    int result = n - 1;

    Node **list = calloc(n, sizeof(Node *));
    for (int i = 0; i < n; i++)
    {
        list[i] = NULL;
    }
    int *colors = calloc(n, sizeof(int));
    int *result_list = calloc(n, sizeof(int));
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d %d\n", &a, &b);
        addNode(list, a - 1, b - 1);
    }

    //
    for (int i = 0; i < n; i++)
    {
        if (colors[i] == 0)
        {
            result = funct(list, i, n, colors, result, result_list);
            if (result == -2)
            {
                printf("NO");
                return 0;
            }
        }
    }

    //вывод ответа
    printf("YES\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", result_list[i] + 1);
    }
    return 0;
}