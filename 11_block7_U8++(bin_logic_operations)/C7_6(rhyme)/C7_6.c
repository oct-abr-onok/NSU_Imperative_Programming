#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node_s
{
    int num;
    int next;
} Node;

int main(void)
{
    int N, K;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &N); //читаем переменные из файла
    scanf("%d", &K);
    Node *arr = malloc(sizeof(Node) * N);
    for (int i = 0; i < N - 1; i++) //создаём зацикленный список
    {
        arr[i].next = i + 1;
        arr[i].num = i + 1;
    }
    arr[N - 1].num = N;
    arr[N - 1].next = 0;

    int selected = N - 1; //считалка
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < K; j++)
        {
            selected = arr[selected].next;
            while (arr[selected].num == 0) //вот, до чего доводит нежелание делать двусвязный список)
            {
                selected = arr[selected].next;
            }
        }
        printf("%d\n", arr[selected].num);
        arr[selected].num = 0;
    }

    return 0;
}