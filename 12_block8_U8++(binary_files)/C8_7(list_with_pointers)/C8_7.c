#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct Node
{
    struct Node *prev, *next;
    double value;
} Node;

//создаёт пустой список
//возвращает указатель на value в голове списка (вспом. узел)
double *initList(void)
{
    Node *list = malloc(sizeof(Node));
    list->next = list;
    list->prev = list;
    list->value = 0;

    return &list->value;
}

//полностью освобождает память списка
//принимает указатель на value голове списка (вспом. узел)
void freeList(double *head)
{
    Node *mem;
    for (Node *i = ((Node *)((long long)head - offsetof(Node, value)))->next; i->next != ((Node *)((long long)head - offsetof(Node, value)))->next; i = mem)
    {
        mem = i->next;
        free(i);
    }
    free((Node *)((long long)head - offsetof(Node, value)));
}

//определяет следующий элемент после заданного
//(для вспом. узла возвращает первый элемент)
double *getNext(double *curr)
{
    return &(((Node *)((long long)curr - offsetof(Node, value)))->next->value);
}

//определяет предыдущий элемент перед заданным
//(для вспом. узла возвращает последний элемент)
double *getPrev(double *curr)
{
    return &(((Node *)((long long)curr - offsetof(Node, value)))->prev->value);
}

//создаёт и вставляет узел со значением newval сразу после узла where
double *addAfter(double *where, double newval)
{
    //создаём новый узел
    Node *newNode = malloc(sizeof(Node));
    newNode->value = newval;
    newNode->prev = ((Node *)((long long)where - offsetof(Node, value)));
    newNode->next = ((Node *)((long long)where - offsetof(Node, value)))->next;

    //вставляем после узла node
    ((Node *)((long long)where - offsetof(Node, value)))->next->prev = newNode;
    ((Node *)((long long)where - offsetof(Node, value)))->next = newNode;

    return &newNode->value;
}

//создаёт и вставляет узел со значением newval сразу перед узлом where
double *addBefore(double *where, double newval)
{
    //создаём новый узел
    Node *newNode = malloc(sizeof(Node));
    newNode->value = newval;
    newNode->prev = ((Node *)((long long)where - offsetof(Node, value)))->prev;
    newNode->next = ((Node *)((long long)where - offsetof(Node, value)));

    //вставляем перед узлом node
    ((Node *)((long long)where - offsetof(Node, value)))->prev->next = newNode;
    ((Node *)((long long)where - offsetof(Node, value)))->prev = newNode;

    return &newNode->value;
}

//удаляет и освобождает заданный узел
void erase(double *what)
{
    ((Node *)((long long)what - offsetof(Node, value)))->prev->next = ((Node *)((long long)what - offsetof(Node, value)))->next;
    ((Node *)((long long)what - offsetof(Node, value)))->next->prev = ((Node *)((long long)what - offsetof(Node, value)))->prev;
    free((Node *)((long long)what - offsetof(Node, value)));
}

void test(FILE *fi, FILE *fo)
{
    int operationsNum;

    double *startPointer = initList();

    //обработка операций
    fscanf(fi, "%d", &operationsNum);
    int lastId = 0, id = 0;
    double doubleMem;
    double **pointersToValues = malloc(sizeof(double *) * operationsNum);
    for (int i = 0; i < operationsNum; i++)
    {
        char operation;
        fscanf(fi, "%d", &operation);
        switch (operation) //исполняем запрашиваемую операцию
        {
        case 1: //добавление спереди
            fscanf(fi, "%d", &id);
            fscanf(fi, "%lf", &doubleMem);

            if (id == -1) //проверка случая с добавлением элемента к дополнительному узлу
            {
                pointersToValues[lastId] = addAfter(startPointer, doubleMem);
            }
            else
            {
                pointersToValues[lastId] = addAfter(pointersToValues[id], doubleMem);
            }
            lastId++;
            break;

        case -1: //добавление сзади
            fscanf(fi, "%d", &id);
            fscanf(fi, "%lf", &doubleMem);

            if (id == -1) //проверка случая с добавлением элемента к дополнительному узлу
            {
                pointersToValues[lastId] = addBefore(startPointer, doubleMem);
            }
            else
            {
                pointersToValues[lastId] = addBefore(pointersToValues[id], doubleMem);
            }
            lastId++;
            break;

        case 0: //удаление
            fscanf(fi, "%d", &id);

            fprintf(fo, "%0.3lf\n", *pointersToValues[id]);
            erase(pointersToValues[id]);
            break;

        default:
            break;
        }
    }
    fprintf(fo, "===\n");

    //вывод списка
    for (Node *i = ((Node *)((long long)startPointer - offsetof(Node, value)))->next; i->next != ((Node *)((long long)startPointer - offsetof(Node, value)))->next; i = i->next)
    {
        fprintf(fo, "%0.3lf\n", i->value);
    }
    fprintf(fo, "===\n");

    freeList(startPointer);
    free(pointersToValues);
}

int main(void)
{
    int testsNum;

    FILE *fi = fopen("input.txt", "rt");
    FILE *fo = fopen("output.txt", "wt");

    fscanf(fi, "%d", &testsNum);
    for (int i = 0; i < testsNum; i++)
    {
        test(fi, fo);
    }

    fclose(fi);
    fclose(fo);
}