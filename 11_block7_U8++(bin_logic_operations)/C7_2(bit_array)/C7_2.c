#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef unsigned int bitword;

//bitword *bitset[1250000];

void bitsetZero(bitword *arr, int num)
{
    for (int i = 0; i <= num / 32; i++)
    {
        arr[i] = 0;
    }
}

int bitsetGet(const bitword *arr, int idx)
{
    if (arr[idx / 32] & (1 << (idx % 32)))
        return 1;
    else
        return 0;
}

void bitsetSet(bitword *arr, int idx, int newval)
{
    if (newval)
        arr[idx / 32] |= 1 << (idx % 32);
    else
        arr[idx / 32] &= ~(1 << (idx % 32));
}

int bitsetAny(const bitword *arr, int left, int right)
{
    int flag = 0, leftbyte = left / 32, rightbyte = right / 32;

    for (int i = left; i < right && i < (leftbyte + 1) * 32; i++)
    {
        if ((arr[i / 32] & (1 << (i % 32))) > 0) //СТУЧИМ К БИТАМ 😑
        {
            flag = 1;
            break;
        }
    }
    for (int i = leftbyte + 1; i < rightbyte; i++)
    {
        if (arr[i] > 0)
        {
            flag = 1;
            break;
        }
    }
    for (int i = rightbyte * 32; i < right && i > left; i++)
    {
        if ((arr[i / 32] & (1 << (i % 32))) > 0) //СТУЧИМ К БИТАМ 😑
        {
            flag = 1;
            break;
        }
    }
    

    return flag;
}

int main(void)
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    bitword *bitset = malloc(sizeof(bitword) * 625000);

    int N, mem, mem1;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &mem);
        switch (mem)
        {
        case 0:
            scanf("%d", &mem);
            bitsetZero(bitset, mem);
            break;

        case 1:
            scanf("%d", &mem);
            printf("%d\n", bitsetGet(bitset, mem));
            break;

        case 2:
            scanf("%d", &mem);
            scanf("%d", &mem1);
            bitsetSet(bitset, mem, mem1);
            break;

        case 3:
            scanf("%d", &mem);
            scanf("%d", &mem1);
            if (bitsetAny(bitset, mem, mem1))
                printf("some\n");
            else
                printf("none\n");
            break;

        default:
            break;
        }
    }
    free(bitset);

    return 0;
}