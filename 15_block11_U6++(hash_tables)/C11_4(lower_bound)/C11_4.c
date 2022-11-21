#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int int_cmp(const void *a, const void *b)
{
    long long x = *(long long *)a;
    long long y = *(long long *)b;
    return (x == y ? 0 : (x < y ? -1 : 1));
}

int string_cmp(const void *a, const void *b)
{
    char *x = *(char **)a;
    char *y = *(char **)b;
    for (int i = 0; i < 32; i++)
    {
        if (x[i] == y[i])
        {
            if (x[i] == 0)
            {
                return 0;
            }
            continue;
        }
        else
        {
            return (x[i] < y[i] ? -1 : 1);
        }
    }
    return 0;
}

typedef int (*cmp_func)(const void *, const void *);
int lower_bound(void *arr, int lenght, void *X, size_t el_size, cmp_func cmp)
{
    int centr, first = 0, last = lenght - 1, res = -1;
    while (1)
    {
        centr = (first + last) / 2;
        if (cmp(X, arr + centr * el_size) == -1 || cmp(X, arr + centr * el_size) == 0)
        {
            last = centr;
        }
        else
        {
            if (cmp(X, arr + centr * el_size) == 0)
            {
                res = centr;
            }
            first = centr;
        }
        if (last - first < 2)
        {
            if (cmp(arr + first * el_size, X) == 0 || cmp(arr + first * el_size, X) == 1)
            {
                res = first;
            }
            else
            {
                if (cmp(arr + last * el_size, X) == 0 || cmp(arr + last * el_size, X) == 1)
                {
                    res = last;
                }
                else
                {
                    res = last + 1;
                }
            }
            return res;
        }
    }
}

int main(void)
{
    FILE *fin = fopen("input.txt", "rt");
    FILE *fout = fopen("output.txt", "wt");

    //разметка
    //чтение массивов + сортировка
    int int_arr_size; //int
    fscanf(fin, "%d", &int_arr_size);
    long long *int_arr = malloc(sizeof(long long) * int_arr_size);
    for (int i = 0; i < int_arr_size; i++)
    {
        fscanf(fin, "%lld", &int_arr[i]);
    }
    qsort(int_arr, int_arr_size, sizeof(long long), int_cmp);
    int string_arr_size; //string
    fscanf(fin, "%d", &string_arr_size);
    char **string_arr = malloc(sizeof(char *) * string_arr_size);
    for (int i = 0; i < string_arr_size; i++)
    {
        string_arr[i] = malloc(sizeof(char) * 32);
        fscanf(fin, "%s", string_arr[i]);
    }
    qsort(string_arr, string_arr_size, sizeof(char *), string_cmp);

    //обработка запросов
    int int_req_cnt; //int
    long long int_to_find;
    fscanf(fin, "%d", &int_req_cnt);
    for (int i = 0; i < int_req_cnt; i++)
    {
        fscanf(fin, "%lld", &int_to_find);
        fprintf(fout, "%d\n", lower_bound(int_arr, int_arr_size, &int_to_find, sizeof(long long), int_cmp));
    }
    int string_req_cnt; //string
    char *string_to_find = calloc(32, sizeof(char));
    fscanf(fin, "%d", &string_req_cnt);
    for (int i = 0; i < string_req_cnt; i++)
    {
        fscanf(fin, "%s", string_to_find);
        fprintf(fout, "%d\n", lower_bound(string_arr, string_arr_size, &string_to_find, sizeof(char *), string_cmp));
    }

    //тестовый вывод
    /*for (int i = 0; i < int_arr_size; i++)
    {
        fprintf(fout, "%lld\n", int_arr[i]);
    }
    for (int i = 0; i < string_arr_size; i++)
    {
        fprintf(fout, "%s\n", string_arr[i]);
    }*/

    //гарбач коллектор-_-
    free(int_arr);
    for (int i = 0; i < string_arr_size; i++)
    {
        free(string_arr[i]);
    }
    free(string_arr);
    fclose(fin);
    fclose(fout);
}