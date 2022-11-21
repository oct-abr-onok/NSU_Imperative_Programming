#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10000000

unsigned int jenkins_one_at_a_time_hash(unsigned long long *key, int len)
{
    unsigned long long hash, i;
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

void add(unsigned long long *k, unsigned long long x, unsigned long long *table)
{
    int i;
    for (i = jenkins_one_at_a_time_hash(k, 1) % TABLE_SIZE;; i = (i + 1) % TABLE_SIZE) //open adressing
    {
        if (table[i] == LONG_MAX)
        {
            break;
        }
    }
    table[i] = x;
}

int isInTable(unsigned long long *k, unsigned long long *table)
{
    for (int i = (jenkins_one_at_a_time_hash(k, 1) % TABLE_SIZE); table[i] != LONG_MAX; i = (i + 1) % TABLE_SIZE)
    {
        if (table[i] == *k)
        {
            return 1;
        }
    }
    return 0;
}

void delete (unsigned long long *k, unsigned long long *table)
{
    table[jenkins_one_at_a_time_hash(k, 1) % TABLE_SIZE] = LONG_MIN; //tombstone
}

unsigned long long func(unsigned long long s, int a, int b, int c, unsigned long long M)
{
    return (s * s * a + s * b + c) % M;
}

int main(void)
{
    FILE *fin = fopen("input.txt", "rt");
    FILE *fout = fopen("output.txt", "wt");

    //разметка
    unsigned long long state = 1, state_r, M;
    int a, b, c, r, l = 0, curr = 0;
    unsigned long long *hashTable = calloc(TABLE_SIZE, sizeof(unsigned long long));
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hashTable[i] = LONG_MAX;
    }

    //чтение из файла
    fscanf(fin, "%llu", &M);
    fscanf(fin, "%d", &a);
    fscanf(fin, "%d", &b);
    fscanf(fin, "%d", &c);

    //ищем r
    while (1)
    {
        if (isInTable(&state, hashTable))
        {
            r = curr;
            break;
        }

        add(&state, state, hashTable);
        curr++;
        state = func(state, a, b, c, M);
    }
    state_r = state;
    state = 1;

    //ищем l
    for (int i = 0; state != state_r; i++)
    {
        state = func(state, a, b, c, M);
        l++;
    }

    //вывод
    fprintf(fout, "%d ", l);
    fprintf(fout, "%d ", r);

    //гарбач коллектор-_-
    free(hashTable);
    fclose(fin);
    fclose(fout);
}