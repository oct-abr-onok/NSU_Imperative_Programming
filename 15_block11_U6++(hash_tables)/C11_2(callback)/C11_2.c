#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node_s
{
    struct Node_s *prev, *next;
    void *value;
} Node;
//List –- вспомогательный узел, являющийся головой списка
typedef Node List;

//инициализирует поля структуры *list значениями для пустого списка
void initList(List *list)
{
    list->next = list;
    list->prev = list;
    list->value = 0;
}

//создаёт новый узел со значением ptr и вставляет его после узла node
//возвращает указатель на созданный узел
Node *addAfter(Node *node, void *ptr)
{
    //создаём новый узел
    Node *newNode = malloc(sizeof(Node));
    newNode->value = ptr;
    newNode->prev = node;
    newNode->next = node->next;

    //вставляем после узла node
    node->next->prev = newNode;
    node->next = newNode;

    return newNode;
}

typedef void (*callback)(void *, int *);

void arrayForeach(void *ctx, callback func, int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        func(ctx, &arr[i]);
    }
}

void listForeach(void *ctx, callback func, List *list)
{
    for (Node *i = list->next; i->next != list->next; i = i->next)
    {
        func(ctx, (int *)i->value);
    }
}

void sumEven(void *ctx, int *value)
{
    if (*value % 2 == 0)
    {
        (*(int *)ctx) += *value;
    }
}

int main(void)
{
    FILE *fin = fopen("input.txt", "rt");
    FILE *fout = fopen("output.txt", "wt");

    //разметка
    int N;
    int res = 0;
    fscanf(fin, "%d", &N);
    int *arr = malloc(N * sizeof(int));
    callback sumE = sumEven;
    List *list = malloc(sizeof(List)); //создаём список
    List *last = list;
    initList(list);

    //читаем переменные
    for (int i = 0; i < N; i++)
    {
        fscanf(fin, "%d", &arr[i]); //в массив
        addAfter(last, &arr[i]);    //в список
        last = last->next;
    }

    //массив
    {
        //применяем функцию
        arrayForeach(&res, sumE, arr, N);

        //вывод результата
        fprintf(fout, "%d ", res);
        res = 0;
    }

    //список
    {
        //применяем функцию
        listForeach(&res, sumE, list);

        //вывод результата
        fprintf(fout, "%d ", res);
        res = 0;
    }

    //гарбач коллектор-_-
    free(list); //не забыть очистить сам список!
    free(arr);
    fclose(fin);
    fclose(fout);
}