#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

char *addstr(int length)
{
    char *arr = malloc((length + 1) * sizeof(char));
    scanf("%s", arr);
    return arr;
}

void prtstr(char *arr)
{
    for (int i = 0; arr[i] != 0; i++)
    {
        printf("%c", arr[i]);
    }
    printf("\n");
}

void delstr(char *arr)
{
    free(&arr[0]);
}

void cntstr(char *arr, char *symb)
{
    int acc = 0;
    for (int i = 0; arr[i] != 0; i++)
    {
        if (*symb == arr[i])
        {
            acc++;
        }
    }

    printf("%d\n", acc);
}

int main(void)
{
    int N, mem, id_mem = 0;
    char symb;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &N);                          //читаем переменные из файла
    char **strs = malloc(N * sizeof(char *)); //база указателей на строки(по факту - двумерный динамический массив)
    int *gisto = malloc(N * sizeof(int));

    for (int i = 0; i < N; i++) //очевидно(выбор команды)
    {

        scanf("%d", &mem);
        switch (mem)
        {
        case 0:
            scanf("%d", &mem);
            strs[id_mem] = addstr(mem);
            id_mem++;
            break;

        case 1:
            scanf("%d", &mem);
            free(strs[mem]);
            gisto[mem] = 1;
            break;

        case 2:
            scanf("%d", &mem);
            prtstr(strs[mem]);
            break;

        case 3:
            scanf("%d", &mem);
            scanf(" ");
            scanf("%c", &symb);
            cntstr(strs[mem], &symb);
            break;

        default:
            break;
        }
    }

    for (int i = 0; i < id_mem; i++) //освобождаем все строки
    {
        if (gisto[i] != 1)
            free(strs[i]);
    }

    return 0;
}