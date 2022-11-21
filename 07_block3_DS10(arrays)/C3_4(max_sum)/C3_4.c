#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    int N, a[5000], L, R, maxsum[3] = {0, 0, -10001};
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanf("%d", &N);    //читаем переменные из файла
    
    for (int i = 0; i < N; i++)
        scanf("%d", &a[i]); //заполняем массив

    for (L = 0; L < N; L++) //ну тут всё в принципе всё очевидно ಠ_ಠ
    {
        int sum = 0;
        for (R = L; R < N; R++)
        {
            sum += a[R];
            if (sum > maxsum[2])
            {
                maxsum[0] = L;  
                maxsum[1] = R;
                maxsum[2] = sum;
            }
        }
    }
    
    for (int i = 0; i < 3; i++)
    {
        printf("%d ", maxsum[i]); //Нажми на кнопку - получишь результат И твоя мечта осуществится! Нажми на кнопку, но что же ты не рад? Тебе больше не к чему стремиться
    }
    
    return 0;
}