#pragma comment(linker, "/STACK:50000000")
#include <stdio.h>
#include <stdlib.h>

int **init_maze(int n)
{
    int **maze = calloc(n, sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        maze[i] = calloc(n, sizeof(int));
    }

    return maze;
}

void paint_over_area(int **maze, int n, int x, int y)
{
    if (maze[x][y] == 0)
    {
        maze[x][y] = 1;
        if (x + 1 < n)
            paint_over_area(maze, n, x + 1, y);
        if (y + 1 < n)
            paint_over_area(maze, n, x, y + 1);
        if (x - 1 >= 0)
            paint_over_area(maze, n, x - 1, y);
        if (y - 1 >= 0)
            paint_over_area(maze, n, x, y - 1);
    }
}

int blocked_cnt_maze(int **maze, int n)
{
    int res = 0;

    //вход
    for (int j = 0; j < n; j++)
    {
        paint_over_area(maze, n, 0, j);
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (maze[i][j] == 0)
            {
                paint_over_area(maze, n, i, j);
                res++;
            }
        }
    }

    return res;
}

int main(void)
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N;
    scanf("%d", &N);

    //чтение лабиринта
    int **maze = init_maze(N);
    char ch;
    scanf(" ");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%c", &ch);
            if (ch == '*')
                maze[i][j] = 1;
            else
                maze[i][j] = 0;
        }
        scanf(" ");
    }

    printf("%d", blocked_cnt_maze(maze, N));

    return 0;
}