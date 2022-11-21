#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void)
{
    int Hour, Minute, Second, HoursN, MinutesN, SecondsN; 
    int ExtraSeconds, TotalSeconds;
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanf("%d", &Hour);    //читаем переменные из файла
    scanf("%d", &Minute);
    scanf("%d", &Second);
    scanf("%d", &ExtraSeconds);

    TotalSeconds = (Hour * 3600 + Minute * 60 + Second + ExtraSeconds) % (24 * 3600); //считаем время, которое будут показывать часы в секундах

    HoursN = TotalSeconds / 3600;
    TotalSeconds %= 3600;
    MinutesN = TotalSeconds / 60;
    TotalSeconds %= 60;
    SecondsN = TotalSeconds;

    printf("%ld ", HoursN);
    printf("%ld ", MinutesN);
    printf("%ld ", SecondsN);

    return 0;
}