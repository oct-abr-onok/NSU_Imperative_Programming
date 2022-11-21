#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap(int *a, int *b)
{
    int mem;
    mem = *a;
    *a = *b;
    *b = mem;
}

void sift_up(int curr, int *heap)
{
    if (heap[curr] < heap[(curr - 1) / 2])
    {
        swap(&heap[curr], &heap[(curr - 1) / 2]);
        sift_up((curr - 1) / 2, heap);
    }
}

void add_to_heap(int X, int *k, int *heap)
{
    heap[*k] = X; //добавляем элемент новым листом в конец массива
    *k = *k + 1;
    sift_up(*k - 1, heap);
}

void sift_down(int curr, int *k, int *heap)
{
    int lesser;
    if ((curr * 2 + 1 < *k) && (curr * 2 + 2 < *k))
    {
        lesser = ((heap[curr * 2 + 1] < heap[curr * 2 + 2]) ? (curr * 2 + 1) : (curr * 2 + 2));
    }
    else
    {
        if (curr * 2 + 1 < *k)
        {
            lesser = curr * 2 + 1;
        }
        else
        {
            lesser = curr;
        }
    }
    if (heap[curr] > heap[lesser])
    {
        swap(&heap[curr], &heap[lesser]);
        sift_down(lesser, k, heap);
    }
}

int extract_min_from_heap(int *k, int *heap)
{
    int res;
    res = heap[0];                 //корень всегда имеет номер 0
    swap(&heap[0], &heap[*k - 1]); //меняем корень с самым правым листом (он является последним)
    *k = *k - 1;                   //удаляем этот лист
    sift_down(0, k, heap);
    return res;
}

int main(void)
{
    FILE *fin = fopen("input.bin", "rb");
    FILE *fout = fopen("output.bin", "wb");

    //разметка
    int arr_size;
    fread(&arr_size, 4, 1, fin);
    int *arr = malloc(arr_size * sizeof(int));
    fread(arr, 4, arr_size, fin);
    int heap_cnt = 0;
    int *heap = malloc(arr_size * sizeof(int));

    //заносим в кучу
    for (int i = 0; i < arr_size; i++)
    {
        add_to_heap(arr[i], &heap_cnt, heap); //+
    }

    //выносим из кучи
    for (int i = 0; i < arr_size; i++)
    {
        arr[i] = extract_min_from_heap(&heap_cnt, heap);
    }

    //вывод
    fwrite(arr, 4, arr_size, fout);

    //гарбач коллектор(-_-)
    free(arr);
    free(heap);
    fclose(fin);
    fclose(fout);
}