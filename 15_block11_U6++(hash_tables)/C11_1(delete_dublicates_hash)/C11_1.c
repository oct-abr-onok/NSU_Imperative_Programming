#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TABLE_SIZE 10000000

typedef struct Vector_s
{
    int *arr;
    int cnt;
    int cap;
} Vector;

void push(Vector *V, int x)
{
    if (V->cnt == V->cap)
    {
        V->arr = realloc(V->arr, V->cap * 2 * sizeof(int));
        V->cap *= 2;
    }
    V->arr[V->cnt++] = x;
}

unsigned int jenkins_one_at_a_time_hash(int *key, int len)
{
    unsigned int hash, i;
    for (hash = i = 0; i < len; ++i)
    {
        hash += key[i];
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    return hash;
}

void add(int *k, int x, int *table)
{
    int i;
    for (i = jenkins_one_at_a_time_hash(k, 1) % TABLE_SIZE;; i = (i + 1) % TABLE_SIZE) //open adressing
    {
        if (table[i] == INT_MAX)
        {
            break;
        }
    }
    table[i] = x;
}

int isInTable(int *k, int *table)
{
    for (int i = (jenkins_one_at_a_time_hash(k, 1) % TABLE_SIZE); table[i] != INT_MAX; i = (i + 1) % TABLE_SIZE)
    {
        if (table[i] == *k)
        {
            return 1;
        }
    }
    return 0;
}

void delete (int *k, int *table)
{
    table[jenkins_one_at_a_time_hash(k, 1) % TABLE_SIZE] = INT_MIN; //tombstone
}

int main(void)
{
    FILE *fin = fopen("input.bin", "rb");
    FILE *fout = fopen("output.bin", "wb");

    //разметка
    int *hashTable = calloc(TABLE_SIZE, sizeof(int));
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hashTable[i] = INT_MAX;
    }
    int N, mem, cnt;
    Vector outArr;
    outArr.arr = calloc(1, sizeof(int));
    outArr.cap = 1;
    outArr.cnt = 0;

    //читаем переменные из файла
    fread(&N, sizeof(int), 1, fin);

    //записываем значения в хэш таблицу, проверяем, не было ли такое же значение ранее
    for (int i = 0; i < N; i++)
    {
        fread(&mem, sizeof(int), 1, fin);
        if (!isInTable(&mem, hashTable))
        {
            push(&outArr, mem);
            add(&mem, mem, hashTable);
        }
    }

    //вывод
    fwrite(&outArr.cnt, sizeof(int), 1, fout);
    for (int i = 0; i < outArr.cnt; i++)
    {
        fwrite(&outArr.arr[i], sizeof(int), 1, fout);
    }

    //гарбач коллектор -_-
    free(hashTable);
    free(outArr.arr);
    fclose(fin);
    fclose(fout);
}