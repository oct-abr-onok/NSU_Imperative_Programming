#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node_s
{
    int ind;
    double value;
} Node;

int main(void)
{
    Node *arr = malloc(sizeof(Node) * 100000);
    int N, F;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &N); //читаем переменные из файла
    scanf("%d", &F);

    for (int i = 0; i < N; i++) //читаем список
    {
        scanf("%lf", &arr[i].value);
        scanf("%d", &arr[i].ind);
    }
    for (int i = 0; F != -1; i++) //выводим список
    {
        printf("%0.3lf\n", arr[F].value);
        F = arr[F].ind;
    }

    free(arr);

    return 0;
}