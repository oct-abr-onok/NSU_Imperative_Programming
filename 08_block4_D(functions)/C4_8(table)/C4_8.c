#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct Video_s
{
    int numOfFrags, duration;
} Video;

void emptyLine(int maxIdR, int maxFragR, int maxDurR)
{
    printf("+-");
    for (int i = 0; i < maxIdR; i++)
    {
        printf("-");
    }
    printf("-+-");
    for (int i = 0; i < maxFragR; i++)
    {
        printf("-");
    }
    printf("-+-");
    for (int i = 0; i < maxDurR; i++)
    {
        printf("-");
    }
    printf("-+\n");
}

void line(int maxIdR, int maxFragR, int maxDurR, int id, int frag, int dur)
{
    //считаем количество разрядов, чтобы поставить нужное кол-во отступов
    int idR = 0, fragR = 0, durR = 0;
    for (int i = id; i > 0; i /= 10)
    {
        idR++;
    }
    if (!idR)
    {
        idR++;
    }
    for (int i = frag; i > 0; i /= 10)
    {
        fragR++;
    }
    if (!fragR)
    {
        fragR++;
    }
    for (int i = dur; i > 0; i /= 10)
    {
        durR++;
    }
    if (!durR)
    {
        durR++;
    }
    

    //вывод
    printf("| ");
    for (int i = 0; i < (maxIdR - idR); i++)
    {
        printf(" ");
    }
    printf("%d", id);
    printf(" | ");
    for (int i = 0; i < (maxFragR - fragR); i++)
    {
        printf(" ");
    }
    printf("%d", frag);
    printf(" | ");
    for (int i = 0; i < (maxDurR - durR); i++)
    {
        printf(" ");
    }
    printf("%d", dur);
    printf(" |\n");
}

int main(void)
{
    Video videos[1001] = {0};
    int numberOfFragments, id, mem, maxIdR = 0, maxFragR = 0, maxDurR = 0, maxId = 0, maxFrag = 0, maxDur = 0;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    //читаем переменные из файла
    scanf("%d", &numberOfFragments);
    for (int i = 0; i < numberOfFragments; i++)
    {
        scanf("%d", &id);
        scanf("%d", &mem);
        videos[id].duration += mem;
        videos[id].numOfFrags++;

        //расчёты для составления таблицы
        if (id > maxId)
        {
            maxId = id;
        }
        if (videos[id].duration > maxDur)
        {
            maxDur = videos[id].duration;
        }
        if (videos[id].numOfFrags > maxFrag)
        {
            maxFrag = videos[id].numOfFrags;
        }
    }

    //вывод таблицы
    for (; maxId > 0; maxId /= 10)
    {
        maxIdR++;
    }
    for (; maxFrag > 0; maxFrag /= 10)
    {
        maxFragR++;
    }
    for (; maxDur > 0; maxDur /= 10)
    {
        maxDurR++;
    }
    emptyLine(maxIdR, maxFragR, maxDurR);
    for (int i = 0; i <= 1000; i++)
    {
        if (videos[i].numOfFrags > 0)
        {
            line(maxIdR, maxFragR, maxDurR, i, videos[i].numOfFrags, videos[i].duration);
            emptyLine(maxIdR, maxFragR, maxDurR);
        }
    }

    return 0;
}