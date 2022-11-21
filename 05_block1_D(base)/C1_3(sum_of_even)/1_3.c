#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void)
{
    int N, sum = 0, mem;
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanf("%d", &N);    //читаем переменные из файла
    
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &mem);
        if (mem % 2 == 0)
        {
            sum += mem;  //считаем сумму всех чётных элементов
        }
    }
    
    printf("%d", sum);

    return 0;
}