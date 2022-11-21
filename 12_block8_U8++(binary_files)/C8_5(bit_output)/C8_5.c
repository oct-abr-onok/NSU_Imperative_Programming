#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N, current_bit = 0, M;
    unsigned short word;
    char byte = 0;

    FILE *fi = fopen("input.txt", "rb");
    FILE *fo = fopen("output.txt", "wb");

    //чтение значений алфавита
    fread(&N, sizeof(int), 1, fi); //читаем переменные из файла
    int *arr_length = malloc(N * sizeof(int));
    char **bit = malloc(N * sizeof(char *)); //двумерный массив под биты
    for (int i = 0; i < N; i++)
    {
        fread(&arr_length[i], sizeof(int), 1, fi);
        bit[i] = malloc(arr_length[i] * sizeof(char));
        for (int j = 0; j < arr_length[i]; j++)
        {
            fread(&bit[i][j], sizeof(char), 1, fi);
        }
    }

    //выводим битовый массив
    fread(&M, sizeof(int), 1, fi);
    for (int i = 0; i < M; i++)
    {
        fread(&word, sizeof(unsigned short), 1, fi);
        for (int j = 0; j < arr_length[word]; j++)
        {
            byte += (1 << (current_bit % 8)) * bit[word][j];
            current_bit++;
            if (current_bit % 8 == 0) //переход к новому байту
            {
                fwrite(&byte, sizeof(char), 1, fo);
                byte = 0;
            }
        }
    }
    if (current_bit % 8 != 0) //выводим остатки
    {
        fwrite(&byte, sizeof(char), 1, fo);
    }

    //очистка
    for (int i = 0; i < N; i++)
    {
        free(bit[i]);
    }
    free(bit);
    fclose(fi);
    fclose(fo);
}