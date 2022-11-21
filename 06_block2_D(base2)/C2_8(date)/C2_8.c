#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    int Day, Month, Year, Day1, Month1, Year1, ExtraDays;
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanf("%d", &Day);    //читаем переменные из файла
    scanf("%d", &Month);
    scanf("%d", &Year);
    scanf("%d", &ExtraDays);

    for (int i = 0; i < ExtraDays; i++)
    {
        switch (Day)  //добавляем по дню, и смотрим, должен ли смениться месяц в этот день
        {
        case 28:
            if (Month == 2 && !((Year % 400 == 0) || ((Year % 4 == 0) && !(Year % 100 == 0))))  //случай февраля обычного года
            {
                Month++;
                Day = 1;
            }
            else
            {
                Day++;
            }
            break;
        
        case 29:
            if (Month == 2 && ((Year % 400 == 0) || ((Year % 4 == 0) && !(Year % 100 == 0)))) //случай февраля високосного года
            {
                Month++;
                Day = 1;
            }
            else
            {
                Day++;
            }
            break;

        case 30:
            if (Month == 4 || Month == 6 || Month == 9 || Month == 11)  //случай 30-тидневных месяцев
            {
                Month++;
                Day = 1;
            }
            else
            {
                Day++;
            }
            break;
        
        case 31:
            if (Month == 1 || Month == 3 || Month == 5 || Month == 7 || Month == 8 || Month == 10)  //случай 31-дневных месяцев
            {
                Month++;
                Day = 1;
            }
            else
            {
                if (Month == 12) //Декабрь - переход на следубщий год
                {
                    Day = 1;
                    Month = 1;
                    Year++;
                }
                else //Да, теоретически программа предполагает 32ое число)
                {
                    Day++;
                }
            }
            break;

        default:
            Day++;
            break;
        }
    }
    
    printf("%d ", Day);
    printf("%d ", Month);
    printf("%d", Year);

    return 0;
}