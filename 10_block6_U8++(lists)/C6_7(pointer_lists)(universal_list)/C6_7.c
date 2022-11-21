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

//создаёт новый узел со значением ptr и вставляет его перед узлом node
//возвращает указатель на созданный узел
Node *addBefore(Node *node, void *ptr)
{
    //создаём новый узел
    Node *newNode = malloc(sizeof(Node));
    newNode->value = ptr;
    newNode->prev = node->prev;
    newNode->next = node;

    //вставляем перед узлом node
    node->prev->next = newNode;
    node->prev = newNode;

    return newNode;
}

//удаляет заданный узел, возвращая значение, которое в нём лежало
void *erase(Node *node)
{
    void *mem;

    node->prev->next = node->next;
    node->next->prev = node->prev;
    mem = node->value;
    free(node);

    return mem;
}

void test(void)
{
    int operationsNum;

    //создаём список
    List *list = malloc(sizeof(List));
    initList(list);

    //обработка операций
    scanf("%d", &operationsNum);
    Node **pointersToNodes = malloc(sizeof(Node *) * operationsNum); //хранилище указателей, в ячейках под индексом индекса из условия
    int *valueStorage = malloc(sizeof(int) * operationsNum);
    int lastId = 0, id;
    for (int i = 0; i < operationsNum; i++)
    {
        char operation;
        scanf("%d", &operation);
        switch (operation) //исполняем запрашиваемую операцию
        {
        case 1: //добавление спереди
            scanf("%d", &id);
            scanf("%d", &valueStorage[lastId]);

            if (id == -1) //проверка случая с добавлением элемента к дополнительному узлу
            {
                pointersToNodes[lastId] = addAfter(list, &valueStorage[lastId]);
            }
            else
            {
                pointersToNodes[lastId] = addAfter(pointersToNodes[id], &valueStorage[lastId]);
            }
            lastId++;
            break;

        case -1: //добавление сзади
            scanf("%d", &id);
            scanf("%d", &valueStorage[lastId]);

            if (id == -1) //проверка случая с добавлением элемента к дополнительному узлу
            {
                pointersToNodes[lastId] = addBefore(list, &valueStorage[lastId]);
            }
            else
            {
                pointersToNodes[lastId] = addBefore(pointersToNodes[id], &valueStorage[lastId]);
            }
            lastId++;
            break;

        case 0: //удаление
            scanf("%d", &id);

            erase(pointersToNodes[id]);
            break;

        default:
            break;
        }
    }

    //вывод списка
    for (Node *i = list->next; i->next != list->next; i = i->next)
    {
        printf("%d\n", *((int *)(i->value)));
    }
    printf("===\n");

    free(valueStorage);
    free(list);
    free(pointersToNodes);
}

int main(void)
{
    int testsNum;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &testsNum);
    for (int i = 0; i < testsNum; i++)
    {
        test();
    }

    return 0;
}