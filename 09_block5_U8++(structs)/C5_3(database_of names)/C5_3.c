#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct Label_s
{
    char name[16]; //имя автора (заканчивается нулём)
    int age;       //возраст автора (сколько лет)
} Label;

typedef struct NameStats_s
{
    int cntTotal; //сколько всего подписей
    int cntLong;  //сколько подписей с именами длиннее 10 букв
} NameStats;

typedef struct AgeStats_s
{
    int cntTotal;  //сколько всего подписей
    int cntAdults; //сколько подписей взрослых (хотя бы 18 лет)
    int cntKids;   //сколько подписей детей (меньше 14 лет)
} AgeStats;

int strlen_mine(char *start) //считаем кол-во элементов в строке
{
    int i = 0;
    while (*(start + i) != 0)
    {
        i++;
    }
    return i;
}

void calcStats(const Label *arr, int cnt, NameStats *oNames, AgeStats *oAges)
{
    oNames->cntTotal = cnt;
    oAges->cntTotal = cnt;

    for (int i = 0; i < cnt; i++) //в зависимости от значений в массиве считаем нужные показатели
    {
        if (arr[i].age >= 18)
        {
            oAges->cntAdults += 1;
        }
        if (arr[i].age < 14)
        {
            oAges->cntKids += 1;
        }
        if (strlen_mine(&arr[i].name) > 10)
        {
            oNames->cntLong += 1;
        }
    }
}

int main(void)
{
    int N;
    char trashbox[4];
    Label list[1000];
    NameStats Names;
    AgeStats Ages;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &N); //читаем переменные из файла
    for (int i = 0; i < N; i++)
    {
        scanf("%s", list[i].name);
        scanf("%d", &list[i].age);
        scanf("%s", trashbox);
        scanf(" ");
    }

    calcStats(&list[0], N, &Names, &Ages); //вызываем ф-ю

    printf("names: total = %d\n", Names.cntTotal); //вывод
    printf("names: long = %d\n", Names.cntLong);
    printf("ages: total = %d\n", Ages.cntTotal);
    printf("ages: adult = %d\n", Ages.cntAdults);
    printf("ages: kid = %d\n", Ages.cntKids);
    return 0;
}