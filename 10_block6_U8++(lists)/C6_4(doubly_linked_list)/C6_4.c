#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct Node_s
{
    int next, prev, value;
} Node;
int last;
Node list[210000];

void AddAfter(int id, int newval)
{
    list[last].value = newval; //записываем само значение

    list[last].prev = id;
    list[last].next = list[id + 1].next;

    list[list[id + 1].next + 1].prev = last - 1;
    list[id + 1].next = last - 1;
}

void AddBefore(int id, int newval)
{
    list[last].value = newval; //записываем само значение

    list[last].prev = list[id + 1].prev;
    list[last].next = id;

    list[list[id + 1].prev + 1].next = last - 1;
    list[id + 1].prev = last - 1;
}

void Delete(int id)
{
    printf("%d\n", list[id + 1].value);

    list[list[id + 1].next + 1].prev = list[id + 1].prev;
    list[list[id + 1].prev + 1].next = list[id + 1].next;
}

void test(void)
{

    int N, Q, F, L;

    scanf("%d", &N); //читаем переменные из файла
    scanf("%d", &F);
    scanf("%d", &L);
    scanf("%d", &Q);

    list[0].next = F;
    list[0].prev = L;
    for (int i = 1; i <= N; i++) //читаем список
    {
        scanf("%d", &list[i].value);
        scanf("%d", &list[i].next);
        scanf("%d", &list[i].prev);
        last = i + 1;
    }

    for (int i = 0; i < Q; i++) //применяем команды + выводим результаты исполнения
    {
        int mem, memval;
        scanf("%d", &mem);

        switch (mem)
        {
        case -1:
            scanf("%d", &mem);
            scanf("%d", &memval);
            AddBefore(mem, memval);
            printf("%d\n", last - 1);
            last++;
            break;

        case 1:
            scanf("%d", &mem);
            scanf("%d", &memval);
            AddAfter(mem, memval);
            printf("%d\n", last - 1);
            last++;
            break;

        case 0:
            scanf("%d", &mem);
            Delete(mem);
            break;

        default:
            break;
        }
    }
    printf("===\n");

    //printf("%d\n", list[0].next);
    for (int i = list[0].next; i != -1;) //выводим полученный список
    {
        printf("%d\n", list[i + 1].value);
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