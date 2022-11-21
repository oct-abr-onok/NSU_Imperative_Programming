#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void)
{
    int start, end, elements, cnt = 0;
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanf("%d", &start);
    scanf("%d", &end);
    scanf("%d", &elements);    //читаем переменные из файла
    
    end -= start;

    for (end; end > 0; end--) //для для каждого отрезка находим количество делителей, для которых будет нужное количество делимых на отрезке
    {
        for (int i = 1; i <= end; i++) 
        {
            if (end / i == elements - 1)
            {
                cnt++; //складываем
            }
        }
    }

    printf("%d", cnt); //выводим результат

    return 0;
}