#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct actor_bio_s
{
    char name[33];
    int birth_year;
    char country[13];
} actor_bio;

typedef struct actor_in_movie_s
{
    char actor_name[33];
    char movie_name[23];
} actor_in_movie;

typedef struct inner_join_s //а нужно ли оно вообще будет?)
{
    char name[33];
    int birth_year;
    char country[13];
    char actor_name[33];
    char movie_name[23];
} inner_join;

void fscstring(FILE *file, char *str)
{
    fscanf(file, " "); //macro
    for (int j = 0, flag = 0; flag < 2; j++)
    {
        str[j] = getc(file);
        if (str[j] == 34)
        {
            flag++;
        }
    }
}

int main(void)
{
    FILE *fin = fopen("input.txt", "rt");
    FILE *fout = fopen("output.txt", "wt");

    //разметка + чтение(доделать нормально)
    int actor_bio_cnt, actor_in_movie_cnt;
    fscanf(fin, "%d", &actor_bio_cnt);
    actor_bio *bios = calloc(actor_bio_cnt, sizeof(actor_bio)); //Я ДАМ ВАМ ПАРАБЕЛЛУМ
    for (int i = 0; i < actor_bio_cnt; i++)
    {
        fscstring(fin, bios[i].name);
        fscanf(fin, "%d", &bios[i].birth_year);
        fscstring(fin, bios[i].country);
    }
    fscanf(fin, "%d", &actor_in_movie_cnt);
    actor_in_movie *movios = calloc(actor_in_movie_cnt, sizeof(actor_in_movie)); //300 рублей будет достаточно, чтобы спасти гиганта мысли?
    for (int i = 0; i < actor_in_movie_cnt; i++)
    {
        fscstring(fin, movios[i].actor_name);
        fscstring(fin, movios[i].movie_name);
    }

    //понятно, что делать
    for (int i = 0; i < actor_bio_cnt; i++) //Я ДУМАЮ: ТОРГ ЗДЕСЬ НЕ УМЕСТЕН!
    {
        for (int j = 0; j < actor_in_movie_cnt; j++)
        {
            if (strcmp(bios[i].name, movios[j].actor_name) == 0)
            {
                fprintf(fout, "%s %d %s %s %s\n", bios[i].name, bios[i].birth_year, bios[i].country, movios[j].actor_name, movios[j].movie_name);
            }
        }
    }

    //гарбач коллектор(-_-)
    free(bios);
    free(movios);
    fclose(fin);
    fclose(fout);
}