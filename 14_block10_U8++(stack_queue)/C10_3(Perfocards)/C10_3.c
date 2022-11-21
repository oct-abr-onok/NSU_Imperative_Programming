#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct CircleBuf_s
{
    int *arr;
    int beg, end;
    int length;
    int arrLength;
} CircleBuf;

void pushBack(CircleBuf *buf, int x)
{
    buf->arrLength++;
    buf->arr[buf->end++] = x;
    if (buf->end == buf->length)
        buf->end = 0;
};

void pushFront(CircleBuf *buf, int x)
{
    buf->arrLength++;
    --buf->beg;
    if (buf->beg == -1)
        buf->beg = buf->length - 1;
    buf->arr[buf->beg] = x;
};

int popBack(CircleBuf *buf)
{
    buf->arrLength--;
    int x;
    --buf->end;
    if (buf->end == -1)
        buf->end = buf->length - 1;
    x = buf->arr[buf->end];
    return x;
};

int popFront(CircleBuf *buf)
{
    buf->arrLength--;
    int x;
    x = buf->arr[buf->beg++];
    if (buf->beg == buf->length)
        buf->beg = 0;
    return x;
};

int main(void)
{

    FILE *fin = fopen("input.txt", "rt");
    FILE *fout = fopen("output.txt", "wt");

    int N, M, card;
    char mem;

    //читаем переменные из файла
    fscanf(fin, "%d", &N);
    fscanf(fin, "%d", &M);
    CircleBuf perfocards[2]; //заводим кольцевые буферы
    for (int i = 0; i < 2; i++)
    {
        perfocards[i].arr = malloc((2 * N + 1) * sizeof(int));
        perfocards[i].beg = 0;
        perfocards[i].end = 0;
        perfocards[i].length = 2 * N + 1;
        perfocards[i].arrLength = 0;
    }

    for (int i = 1; i <= N; i++) //заполняем буферы
    {
        pushBack(&perfocards[0], i);
        pushBack(&perfocards[1], -i);
    }

    //обработка операций
    fscanf(fin, " ");
    for (int i = 0; i < M; i++)
    {
        char from, to, isFromBack, isToBack;

        fscanf(fin, "%c", &mem);
        //приведение в десятичный вид
        if (mem <= '9')
        {
            mem -= 48;
        }
        else
        {
            mem -= 55;
        }

        //чтение операции
        if (mem & 8)
            from = 1;
        else
            from = 0;
        if (mem & 2)
            to = 1;
        else
            to = 0;
        if (mem & 4)
            isFromBack = 1;
        else
            isFromBack = 0;
        if (mem & 1)
            isToBack = 1;
        else
            isToBack = 0;

        //выполнение операции
        if (perfocards[from].arrLength)
        {
            if (isFromBack)
                card = popBack(&perfocards[from]);
            else
                card = popFront(&perfocards[from]);
            if (isToBack)
                pushBack(&perfocards[to], card);
            else
                pushFront(&perfocards[to], card);
        }
    }

    //вывод
    for (int i = 0; i < 2; i++)
    {
        fprintf(fout, "%d  ", perfocards[i].arrLength);
        while (perfocards[i].arrLength)
        {
            fprintf(fout, "%d ", popFront(&perfocards[i]));
        }
        free(perfocards[i].arr);
        fprintf(fout, "\n");
    }

    fclose(fin);
    fclose(fout);
}