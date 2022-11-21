#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node_s
{
    struct Node_s *next;
    char value[8];
} Node;

Node* addNewVal(Node *list, char *val)
{
    Node *next_mem = list;
    while (next_mem->next != 0)
    {
        next_mem = next_mem->next;
    }
    next_mem->next = calloc(1, sizeof(Node));
    next_mem = next_mem->next;
    next_mem->next = 0;
    for (int i = 0; i < 8; i++)
    {
        next_mem->value[i] = val[i];
    }
    return next_mem;
}

int main(void)
{
    int N, mem;
    char value[8];
    Node *list = calloc(1000001, sizeof(Node));
    Node *next_mem; //создаём списки
    Node **last = calloc(1000001, sizeof(Node*));
    for (int i = 0; i < 1000001; i++)
    {
        last[i] = &list[i];
    }
    

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    //чтение данных + расположение в соответствующие списки
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &mem);
        scanf(" ");
        scanf("%s", value);
        last[mem] = addNewVal(last[mem], &value[0]);
    }

    //вывод
    for (int i = 0; i < 1000001; i++)
    {
        next_mem = list[i].next;
        if (next_mem != 0)
        {
            for (; next_mem != 0; next_mem = next_mem->next)
            {
                printf("%d %s\n", i, next_mem->value);
            }
        }
    }

    return 0;
}