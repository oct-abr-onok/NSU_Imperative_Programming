#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void)
{
    int N, M, M_entr, M_floor, TotalFloors, N_entr, N_floor, FlatsOnFloor;
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanf("%d", &N);    //читаем переменные из файла
    scanf("%d", &M);
    scanf("%d", &M_entr);
    scanf("%d", &M_floor);
    scanf("%d", &TotalFloors);

    FlatsOnFloor = M / ((M_entr - 1) * TotalFloors + (M_floor - 1)); //вычисляем количество квартир на этаже

    N_entr = N / (TotalFloors * FlatsOnFloor);  //вычисляем номер подъезда
    if (N % (TotalFloors * FlatsOnFloor) != 0)
    {
        N_entr += 1;
    }
    
    N_floor = (N - ((N_entr - 1) * TotalFloors * FlatsOnFloor)) / FlatsOnFloor; //вычисляем номер этажа
    if ((N - ((N_entr - 1) * TotalFloors * FlatsOnFloor)) % FlatsOnFloor != 0)
    {
        N_floor += 1;
    }

    printf("%d ", N_entr);  //выводим результат
    printf("%d ", N_floor);

    return 0;
}