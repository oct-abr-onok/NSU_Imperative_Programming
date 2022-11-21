#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define TABLE_SIZE 10000000

unsigned int jenkins_one_at_a_time_hash(unsigned int *key, int len)
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

void add(unsigned int *k, unsigned int x, unsigned int h, unsigned int **table)
{
    int i;
    for (i = jenkins_one_at_a_time_hash(k, 1) % TABLE_SIZE;; i = (i + 1) % TABLE_SIZE) //open adressing
    {
        if (table[i][0] == INT_MAX)
        {
            break;
        }
    }
    table[i][0] = x;
    table[i][1] = h;
}

unsigned int isInTable(unsigned int *k, unsigned int **table)
{
    for (unsigned int i = (jenkins_one_at_a_time_hash(k, 1) % TABLE_SIZE); table[i][0] != INT_MAX; i = (i + 1) % TABLE_SIZE)
    {
        if (table[i][0] == *k)
        {
            return table[i][1];
        }
    }
    return 0;
}

int main(void)
{
    //разметка
    unsigned int x, mem;
    srand(time(NULL));
    unsigned int **hash_table = malloc(TABLE_SIZE * sizeof(unsigned int **));
    for (unsigned int i = 0; i < TABLE_SIZE; i++)
    {
        hash_table[i] = malloc(2 * sizeof(unsigned int));
        hash_table[i][0] = INT_MAX;
    }

    //поиск коллизии
    while (1)
    {
        x = abs(rand()); 
        printf("eval %u\n", x);
        fflush(stdout);

        scanf("%u", &mem);
        if (isInTable(&mem, hash_table))
        {
            printf("answer %u %u\n", isInTable(&mem, hash_table), x);
            fflush(stdout);
            break;
        }
        add(&mem, mem, x, hash_table);
    }

    //гарбач коллектор-_-
    for (unsigned int i = 0; i < TABLE_SIZE; i++)
    {
        free(hash_table[i]);
    }
    free(hash_table);
}