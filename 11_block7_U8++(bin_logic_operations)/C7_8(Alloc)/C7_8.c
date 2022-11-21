#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

double *idToHeap[301000];

typedef struct Free_block_s
{
    double value;
    Free_block *next;
} Free_block;

typedef struct MyDoubleHeap_s
{
    Free_block *first; //можно хранить здесь всякие данные
} MyDoubleHeap;

//создать новый аллокатор с массивом на slotsCount блоков
MyDoubleHeap initAllocator(int slotsCount)
{
    MyDoubleHeap allocator;
    allocator->first = malloc(sizeof(Free_block) * slotsCount);

    for (int i = 0; i < slotsCount; i++)
    {
        if (i == slotsCount - 1)
        {
            first[i].next = 0;
        }
        else
        {
            first[i].next = &first[i + 1];
        }
    }
}

int main(void)
{
    int N;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &N); //читаем переменные из файла

    //место под код

    printf("%d", N);

    return 0;
}