#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    long long mem, outpLL;
    long long *inpLL;
    //double* outp;
    int N;
    double P, Q, inp, outp;
    char trashbox[4];

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &N); //читаем переменные из файла

    for (int i = 0; i < N; i++)
    {
        scanf("%lg", &P); //сканируем
        scanf("%c", &trashbox[0]);
        scanf("%lg", &Q);
        scanf(" ");
        scanf("%s", trashbox);
        scanf(" ");
        scanf("%llx", &mem);

        inp = P / Q; //^-^

        inpLL = (long long *)&inp; //обманываем битовый xor, чтобы он думал, что inp - типа long long
        outpLL = *inpLL ^ mem;
        //оказалось, что можно даже ничего не переводить
        printf("%0.15g\n", outpLL);
    }

    return 0;
}