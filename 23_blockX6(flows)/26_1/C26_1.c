#include <stdlib.h>
#include <stdio.h>

int *col;
int *hasV, *hasS, *hasD;
int **matrix;
int M, N;

void print(void)
{
    printf("YES\n");
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (col[i] == j)
            {
                printf("X ");
            }
            else
            {
                printf(". ");
            }
        }
        printf("\n");
    }
}

int Rec(int r)
{
    if (r == M)
    {
        print();
        return 0;
    }
    for (int c = 0; c < N; c++)
    {
        if (hasV[c] || hasS[r + c] || hasD[r - c + N] || matrix[r][c]) //отсечение: если вертикаль или диагонали уже бьются
            continue;                                                  //           тогда ставить ферзя НЕ будем

        col[r] = c;                                  //ставим ферзя в клетку
        hasV[c] = hasS[r + c] = hasD[r - c + N] = 1; //обновляем глобальное состояние

        if (Rec(r + 1) == 0) //запускаем перебор всех вариантов для r+1 и последующих строк
            return 0;
        hasV[c] = hasS[r + c] = hasD[r - c + N] = 0; //откатываем изменения, возвращая в точности состояние до установки ферзя
        col[r] = c;                                  //(мы уверены, что hasX[?] все имели значение 0 до того, как мы записали туда 1)
    }
    return 1;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d %d", &M, &N);

    col = malloc(sizeof(int) * M);
    hasV = calloc(N, sizeof(int));
    hasD = calloc((N + M), sizeof(int));
    hasS = calloc((N + M), sizeof(int));
    matrix = calloc(M, sizeof(int *));
    for (int i = 0; i < M; i++)
    {
        matrix[i] = calloc(N, sizeof(int));
    }

    scanf(" ");
    char cur_ch;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%c", &cur_ch);
            if (cur_ch == '.')
                matrix[i][j] = 1;
        }
        scanf(" ");
    }

    if (Rec(0))
        printf("NO\n");

    return 0;
}