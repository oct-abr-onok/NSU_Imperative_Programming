#include <stdint.h>

extern int64_t init_arr[100001];

//выполнить подготовку массива: запускается один раз перед запусками Sum
//здесь arr[0..n) –- это массив A из входного файла
void Init(const int *arr, int n)
{
    init_arr[0] = 0;
    init_arr[1] = arr[0];
    for (int i = 2; i < n + 1; i++)
    {
        init_arr[i] = (int64_t)arr[i - 1] + (int64_t)init_arr[i - 1];
    }
}

//найти сумму элементов A на отрезке [l..r)
//использует данные, посчитанные функцией Init
int64_t Sum(int l, int r)
{
    return init_arr[r] - init_arr[l]; //уточнить
}
