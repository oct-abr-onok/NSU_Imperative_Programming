#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct pair_s
{
    int x;
    int y;
} pair;

int main(void)
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int M, N;
    scanf("%d %d", &M, &N);

    // maze init
    int **maze = calloc(M, sizeof(int *));
    for (int i = 0; i < M; i++)
    {
        maze[i] = calloc(N, sizeof(int));
    }

    //заполнение maze
    int Qsize = 1;
    pair *Qarr = malloc(sizeof(pair) * M * N);

    scanf(" ");
    char cur_val;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%c", &cur_val);
            switch (cur_val)
            {
            case 'S':
                Qarr[0].x = i;
                Qarr[0].y = j;
                maze[i][j] = 0;
                break;

            case 'X':
                maze[i][j] = -2;
                break;

            case 'F':
                maze[i][j] = -3;
                break;

            default:
                maze[i][j] = -1;
                break;
            }
        }
        scanf(" ");
    }

    // bfs
    int flag = 0;
    for (int i = 0; i < Qsize; i++)
    {
        pair u = Qarr[i];
        if (u.x + 1 < M)
        {
            if (maze[u.x + 1][u.y] == -3)
            {
                flag++;
                printf("%d", maze[u.x][u.y] + 1);
                break;
            }
            if (maze[u.x + 1][u.y] == -1)
            {
                Qarr[Qsize].x = u.x + 1;
                Qarr[Qsize++].y = u.y;
                maze[u.x + 1][u.y] = maze[u.x][u.y] + 1;
            }
        }
        if (u.y + 1 < N)
        {
            if (maze[u.x][u.y + 1] == -3)
            {
                flag++;
                printf("%d", maze[u.x][u.y] + 1);
                break;
            }
            if (maze[u.x][u.y + 1] == -1)
            {
                Qarr[Qsize].x = u.x;
                Qarr[Qsize++].y = u.y + 1;
                maze[u.x][u.y + 1] = maze[u.x][u.y] + 1;
            }
        }
        if (u.x - 1 >= 0)
        {
            if (maze[u.x - 1][u.y] == -3)
            {
                flag++;
                printf("%d", maze[u.x][u.y] + 1);
                break;
            }
            if (maze[u.x - 1][u.y] == -1)
            {
                Qarr[Qsize].x = u.x - 1;
                Qarr[Qsize++].y = u.y;
                maze[u.x - 1][u.y] = maze[u.x][u.y] + 1;
            }
        }
        if (u.y - 1 >= 0)
        {
            if (maze[u.x][u.y - 1] == -3)
            {
                flag++;
                printf("%d", maze[u.x][u.y] + 1);
                break;
            }
            if (maze[u.x][u.y - 1] == -1)
            {
                Qarr[Qsize].x = u.x;
                Qarr[Qsize++].y = u.y - 1;
                maze[u.x][u.y - 1] = maze[u.x][u.y] + 1;
            }
        }
    }

    if (!flag)
    {
        printf("-1");
    }

    return 0;
}