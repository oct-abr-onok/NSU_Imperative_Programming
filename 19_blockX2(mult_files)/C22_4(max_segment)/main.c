#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int64_t init_arr[100001];
int len;

void Init(const int *arr, int n);
int64_t Sum(int l, int r);
int Query(int l, int64_t sum);

int main(void)
{
    int N, L, M;
    long long S;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    //читаем переменные из файла
    scanf("%d %d", &N, &M);
    len = N;
    int *A = malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }

    //вычисление
    Init(A, N);
    for (int i = 0; i < M; i++)
    {
        scanf("%d %lld", &L, &S);
        printf("%d\n", Query(L, S));
    }
    return 0;
}