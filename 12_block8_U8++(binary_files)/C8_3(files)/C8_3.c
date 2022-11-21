#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct File_data_s
{
    char name[21];
    long long size;
    char isDirectory;
    long long created;
    long long changed;
    char isHidden;
} File_data;

char fileCmp(File_data *a, File_data *b) //лексиграфическое сравнение
{
    for (int i = 0; i < 20; i++)
    {
        if (a->name[i] < b->name[i])
        {
            return 1;
        }
        if (a->name[i] > b->name[i])
        {
            return 0;
        }
    }
    return 0;
}

void fileSwap(File_data *a, File_data *b)
{
    File_data mem;

    mem = *a;
    *a = *b;
    *b = mem;
}

int main(void)
{
    char test = 'P', test2 = 'p';
    int N;
    long long created_after, changed_before;

    FILE *fi = fopen("input.txt", "rb");
    FILE *fo = fopen("output.txt", "wb");

    fread(&N, sizeof(int), 1, fi); //читаем переменные из файла
    fread(&created_after, sizeof(long long), 1, fi);
    fread(&changed_before, sizeof(long long), 1, fi);

    File_data *arr = malloc(sizeof(File_data) * N);

    for (int i = 0; i < N; i++) //чтение данных
    {
        fread(arr[i].name, sizeof(char), 21, fi);
        fread(&arr[i].size, sizeof(long long), 1, fi);
        fread(&arr[i].isDirectory, sizeof(char), 1, fi);
        fread(&arr[i].created, sizeof(long long), 1, fi);
        fread(&arr[i].changed, sizeof(long long), 1, fi);
        fread(&arr[i].isHidden, sizeof(char), 1, fi);
    }

    for (int i = 0; i < N; i++) //сортировка по имени
    {
        for (int j = 0; j < N; j++)
        {
            if (fileCmp(&arr[i], &arr[j]))
            {
                fileSwap(&arr[i], &arr[j]);
            }
        }
    }

    for (int i = 0; i < N; i++) //вывод данных
    {
        if (!arr[i].isDirectory && !arr[i].isHidden && (arr[i].created >= created_after) && (arr[i].changed <= changed_before))
        {
            fwrite(arr[i].name, sizeof(char), 21, fo);
            fwrite(&arr[i].size, sizeof(long long), 1, fo);
            fwrite(&arr[i].isDirectory, sizeof(char), 1, fo);
            fwrite(&arr[i].created, sizeof(long long), 1, fo);
            fwrite(&arr[i].changed, sizeof(long long), 1, fo);
            fwrite(&arr[i].isHidden, sizeof(char), 1, fo);
        }
    }

    fclose(fi);
    fclose(fo);
    free(arr);
}