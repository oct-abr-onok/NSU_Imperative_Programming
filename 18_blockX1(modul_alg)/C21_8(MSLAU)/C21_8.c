#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define RES_MOD 1000000007

long long m_add(long long a, long long b, long long m)
{
    long long res = ((a % m) + (b % m)) % m;
    return (res >= 0 ? res : res + m);
}

long long m_sub(long long a, long long b, long long m)
{
    long long res = ((a % m) - (b % m)) % m;
    return (res >= 0 ? res : res + m);
}

long long m_mult(long long a, long long b, long long m)
{
    long long res = ((a % m) * (b % m)) % m;
    return (res >= 0 ? res : res + m);
}

long long m_pow(long long a, long long n, long long m)
{
    long long res = 1;
    for (long long i = 0; i < n; i++)
    {
        res = m_mult(res, a, m);
    }
    return res;
}

long long *euclid(long long a, long long m, long long *res) //работает?!!
{
    long long mem;
    if (m == 0)
    {
        res[0] = a;
        res[1] = 1;
        res[2] = 0;
    }
    else
    {
        res = euclid(m, a % m, res); // x1 y1 (всё наоборот(Ловушка Гатилова))
        mem = res[1];
        res[1] = res[2];                 // x = y1 + (a / b) * y
        res[2] = mem - (a / m) * res[2]; // y = x1
    }
    return res;
}

long long inv(long long a, long long m)
{
    long long mem;
    long long *res = malloc(sizeof(long long) * 3);
    res = euclid(a, m, res);
    mem = res[1];
    free(res);
    return mem;
}

long long m_div(long long a, long long b, long long m)
{
    long long res = m_mult(a, inv(b, m), m);
    return (res >= 0 ? res : res + m);
}

//рабочая
void matrix_swap(long long **matrix, long long a, long long b, long long n)
{
    long long mem;
    for (long long i = 0; i < n + 1; i++)
    {
        mem = matrix[a][i];
        matrix[a][i] = matrix[b][i];
        matrix[b][i] = mem;
    }
}

long long first_in_line(long long **stepped_matrix, long long n, long long a)
{
    for (long long i = 0; i < n + 1; i++)
        if (stepped_matrix[a][i] != 0)
            return i;
    return n + 1;
}

//рабочая
void to_stepped(long long **matrix, long long k, long long n, long long mod)
{
    long long lock = 0;
    for (long long i = 0; i < n + 1; i++)
    {
        for (long long j = lock; j < k; j++)
        {
            if (matrix[j][i] == 0) //случай A
            {
                continue;
            }
            else //случай B
            {
                matrix_swap(matrix, lock, j, n);     //перeмещение
                lock++;                              //сдвиг
                for (long long q = lock; q < k; q++) //зануление
                {
                    long long first = first_in_line(matrix, n, lock - 1);
                    long long t = m_div(matrix[q][first], matrix[lock - 1][first], mod);

                    for (long long m = 0; m < n + 1; m++) //не забываем про дополнительный (n+1)-ый столбец!
                        matrix[q][m] = m_sub(matrix[q][m], m_mult(matrix[lock - 1][m], t, mod), mod);
                }
                break;
            }
        }
    }
}

long long *to_results(long long **stepped_matrix, long long k, long long n, long long mod, int *flag)
{
    // mod^free_var
    //считаем сначала кол-во пустых строк, нету -> классика с учётом возможности отсутствия решенеий, есть -> cчитаем кол-во + проверка на отсутствие
    long long free_vars = 0, zero_flag = 0;

    for (long long i = k - 1; i >= 0; i--)
    {
        if (first_in_line(stepped_matrix, n, i) == n + 1)
        {
            free_vars++;
        }
        else
        {
            if (first_in_line(stepped_matrix, n, i) == n)
            {
                zero_flag = 1;
            }
            break;
        }
    }

    if (zero_flag || m_pow(mod, m_sub(n, m_sub(k, free_vars, RES_MOD), RES_MOD), RES_MOD) > 1)
    {
        long long *res = malloc(2 * sizeof(long long));
        res[0] = 1;
        if (zero_flag)
        {
            res[1] = 0;
        }
        else
        {
            res[1] = m_pow(mod, m_sub(n, m_sub(k, free_vars, RES_MOD), RES_MOD), RES_MOD);
        }
        return res;
    }

    *flag = 1;
    long long *res = malloc((n + 1) * sizeof(long long));
    for (long long i = k - 1 - free_vars; i >= 0; i--)
    {
        long long sum = 0;
        long long first = first_in_line(stepped_matrix, n, i);
        for (long long j = first + 1; j < n + 1; j++)
        {
            if (j != n)
                sum = m_sub(sum, m_mult(stepped_matrix[i][j], res[j + 1], mod), mod);
            else
                sum = m_add(sum, m_mult(stepped_matrix[i][j], 1, mod), mod);
        }
        res[i + 1] = m_div(sum, stepped_matrix[i][i], mod);
    }
    res[0] = n;
    return res;
}

int main(void)
{
    long long n, k, P;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%lld %lld %lld", &n, &k, &P); //читаем переменные из файла

    long long **matrix = malloc(k * sizeof(long long)); //создаём матрицу уравнений
    for (int i = 0; i < k; i++)
    {
        matrix[i] = malloc((n + 1) * sizeof(long long));
    }

    //чтение уравнений
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            scanf("%lld", &matrix[i][j]);
        }
    }

    int flg = 0; //костыль
    to_stepped(matrix, k, n, P);                  //перевод в ступенчатый вид
    long long *res = to_results(matrix, k, n, P, &flg); //поиск решений

    //вывод ступенчатой
    /*for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            printf("%lld ", matrix[i][j]);
        }
        printf("\n");
    }*/

    //вывод ответов
    if (flg)
    {
        printf("1\n");
    }
    for (long long i = 1; i <= res[0]; i++)
    {
        printf("%lld\n", res[i]);
    }

    //гарбач коллектор -_0
    for (int i = 0; i < k; i++)
    {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}