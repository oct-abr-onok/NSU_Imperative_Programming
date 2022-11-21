#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//#include <locale.h>

//setlocale(LC_ALL, ".UTF8");

int main(void)
{
    int bytes, current_bytes = 4, imem;
    char T, test = 34, cmem;
    long long llmem;

    FILE *fi = fopen("input.txt", "rb");
    FILE *fo = fopen("output.txt", "wt");

    fread(&bytes, sizeof(int), 1, fi); //читаем переменные из файла
    fprintf(fo, "{");


    while (current_bytes < bytes - 1)
    {
        if (current_bytes > 4) //разборки с запятыми и отступами
        {
            fprintf(fo, ",");    
        }
        fprintf(fo, "\n\t");

        fread(&T, sizeof(char), 1, fi); //читаем тип
        current_bytes++;

        fprintf(fo, "%c", test); //вывод имени
        for (int i = 0;; i++)
        {
            fread(&cmem, sizeof(char), 1, fi);
            current_bytes++;
            if (cmem == 0)
            {
                break;
            }
            fprintf(fo, "%c", cmem);    
        }
        fprintf(fo, "%c: ", test);

        switch (T) //вывод значения
        {
        case 1: //double
            fread(&llmem, sizeof(long long), 1, fi);
            current_bytes += 8;
            fprintf(fo, "%0.15g", llmem);
            break;
        case 2: //string
            fprintf(fo, "%c", test);
            fread(&imem, sizeof(int), 1, fi);
            char *string = malloc(sizeof(char) * imem);
            fread(string, sizeof(char), imem, fi);
            fprintf(fo, "%s", string);
            current_bytes += imem + 4;
            fprintf(fo, "%c", test);
            free(string);
            break;
        case 8: //bool
            fread(&cmem, sizeof(char), 1, fi);
            current_bytes++;
            if (cmem == 0)
            {
                fprintf(fo, "false");
            }
            else
            {
                fprintf(fo, "true");
            }
            break;
        case 10: //null
            fprintf(fo, "null");
            break;
        case 16: //int
            fread(&imem, sizeof(int), 1, fi);
            current_bytes += 4;
            fprintf(fo, "%d", imem);
            break;
        case 18: //long long
            fread(&llmem, sizeof(long long), 1, fi);
            current_bytes += 8;
            fprintf(fo, "%lld", llmem);
            break;
        default:
            break;
        }
    }

    fprintf(fo, "\n}");

    fclose(fi);
    fclose(fo);
}