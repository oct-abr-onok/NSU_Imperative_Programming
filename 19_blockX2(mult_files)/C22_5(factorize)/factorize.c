//структура, в которой хранится разложение на простые множители
typedef struct Factors
{
    int k;          //сколько различных простых в разложении
    int primes[32]; //различные простые в порядке возрастания
    int powers[32]; //в какие степени надо эти простые возводить
} Factors;

//функция, которая находит разложение числа X и записывает его в структуру res
void Factorize(int X, Factors *res)
{
    //зануление
    res->k = 0;
    for (int i = 0; i < 32; i++)
    {
        res->powers[i] = 0;
        res->primes[i] = 0;
    }

    for (int i = 2; i * i <= X; i++)
    {
        if (X == 1)
            break;
        if (X % i == 0)
        {
            res->primes[res->k] = i;
            res->k = res->k + 1;
        }
        while (X % i == 0)
        {
            X /= i;
            res->powers[res->k - 1] = res->powers[res->k - 1] + 1;
        }
    }
    if (X > 1)
    {
        res->primes[res->k] = X;
        res->k = res->k + 1;
        res->powers[res->k - 1] = res->powers[res->k - 1] + 1;
    }
}