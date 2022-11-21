#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define min(a, b) (a < b ? a : b)
#define MOD 1000000007

int main(void)
{
    int N;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &N);

    int **res = malloc(sizeof(int *) * (N + 1));
    for (int i = 0; i < N + 1; i++)
    {
        res[i] = malloc(sizeof(int) * (N + 1));
    }
    for (int Sum = N; Sum >= 0; Sum--)
    {
        for (int Last = 0; Last <= N; Last++)
        {
            if (Sum == N)
                res[Sum][Last] = 1;
            else
            {
                res[Sum][Last] = 0;
                for (int x = 1; x <= min(Last, N - Sum); x++)
                    res[Sum][Last] = (res[Sum][Last] + res[Sum + x][x]) % MOD;
            }
        }
    }

    printf("%d", res[0][N]);

    return 0;
}