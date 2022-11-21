#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    int N_A, N_B, mem_A[100001] = {0}, mem_B[100001] = {0}, mem, cnt = 0, result_mem[100001] = {0};

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &N_A); //читаем значения А
    for (int i = 0; i < N_A; i++)
    {
        scanf("%d", &mem);
        mem_A[mem]++;
    }
    scanf("%d", &N_B); //читаем значения B
    for (int i = 0; i < N_B; i++)
    {
        scanf("%d", &mem);
        mem_B[mem]++;
    }

    for (int i = 0; i < 100001; i++) //смотрим, сколько значений удовлетворяющих условию, и запоминаем их
    {
        if (mem_A[i] && !mem_B[i])
        {
            cnt++;
            result_mem[i] = 1;
        }
    }

    printf("%d\n", cnt);
    for (int i = 0; i < 100001; i++) //выводим результат
    {
        if (result_mem[i] == 1)
        {
            printf("%d ", i);
        }
    }

    return 0;
}