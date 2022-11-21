#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node_s
{
    int next;
    char value[8];
    int first_flag;
} Node;
Node list[210000];
int last;

void AddNode(int id, char *addVal) //как-то надо передать сам список в функцию
{
    for (int i = 0; i < 8; i++)
    {
        list[last].value[i] = addVal[i]; //записываем само значение
    }

    list[last].next = list[id + 1].next;

    list[id + 1].next = last - 1;
}

void DelNode(int id)
{
    printf("%s\n", list[list[id + 1].next + 1].value);

    list[id + 1].next = list[list[id + 1].next + 1].next;
}

void test(void)
{
    int N, Q, F;

    scanf("%d", &N); //читаем переменные из файла
    scanf("%d", &F);
    scanf("%d", &Q);

    list[0].next = F; //помечаем первый элемент

    for (int i = 1; i <= N; i++) //читаем список
    {
        scanf("%s", list[i].value);
        scanf("%d", &list[i].next);
        last = i + 1;
    }

    for (int i = 0; i < Q; i++) //применяем команды + выводим результаты исполнения
    {
        int command, funcInd;
        char addValue[8];
        scanf("%d", &command);
        if (command)
        {
            scanf("%d", &funcInd);
            DelNode(funcInd);
        }
        else
        {
            scanf("%d", &funcInd);
            scanf("%s", addValue);
            AddNode(funcInd, &addValue[0]);
            printf("%d\n", last - 1);
            last++;
        }
    }
    printf("===\n");

    for (int i = list[0].next; i != -1;) //выводим полученный список
    {
        printf("%s\n", list[i + 1].value);
        i = list[i + 1].next;
    }
    printf("===\n");
}

int main(void)
{
    int T;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        test();
    }

    return 0;
}