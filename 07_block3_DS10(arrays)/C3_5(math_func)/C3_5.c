#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    int N, M, feature[5] = {1, 1, 1, 1}, mem_x[300] = {0}, mem_y[300] = {0}, mem;
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanf("%d", &N);    //читаем переменные из файла
    scanf("%d", &M);
    
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &mem);
        mem_x[mem - 1]++; 
        scanf("%d", &mem);
        mem_y[mem - 1]++;
    }
    
    for (int i = 0; i < N; i++) //стоит проверить, могут ли встречаться одинаковые пары в отношении
    {                           //проверка на то, что отношение является функцией
        if (mem_x[i] > 1)
        {
            feature[0] = 0;
        }
    }

    for (int i = 0; i < N; i++) //проверка на всюду-определённость
    {
        if (mem_x[i] < 1)
        {
            feature[1] = 0;
        }
    }
    
    for (int i = 0; i < N; i++) //проверка на инъективность
    {                           
        if (mem_y[i] > 1)
        {
            feature[2] = 0;
        }
    }

    for (int i = 0; i < N; i++) //проверка на сюръективность
    {
        if (mem_y[i] < 1)
        {
            feature[3] = 0;
        }
    }

    if (feature[2] && feature[3]) //проверка на биективность
    {
        feature[4] = 1;
    }
    
    if (feature[0] == 0) //выводим результат в соответствии с требованиями
    {
        printf("0");
    }
    else
    {
        for (int i = 0; i < 5; i++)
        {
            if (feature[i] == 1)
            {
                printf("%d ", i + 1);
            }
        }
    }
    
    /*printf("%d ", feature[0]);
    printf("%d ", feature[1]);
    printf("%d ", feature[2]);
    printf("%d ", feature[3]);
    printf("%d ", feature[4]);*/

    return 0;
}