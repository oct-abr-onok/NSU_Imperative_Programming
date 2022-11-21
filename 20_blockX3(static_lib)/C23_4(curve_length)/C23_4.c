#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIMP_ACC 250

typedef struct Polynomial
{
    double c[4];
} Polynomial;

typedef struct Span
{
    double l, r;
    Polynomial coord[3];
} Span;

//𝑝(𝑡) = 𝑐0 + 𝑐1(𝑡 − 𝑙) + 𝑐2(𝑡 − 𝑙)^2 + 𝑐3(𝑡 − 𝑙)^3
double func(Span span, int coor_num, double t)
{
    return span.coord[coor_num].c[0] + span.coord[coor_num].c[1] * (t - span.l) + span.coord[coor_num].c[2] * (t - span.l) * (t - span.l) + span.coord[coor_num].c[3] * (t - span.l) * (t - span.l) * (t - span.l);
}

double dif(Span span, int coor_num, double t)
{
    return span.coord[coor_num].c[1] + 2 * span.coord[coor_num].c[2] * (t - span.l) + 3 * span.coord[coor_num].c[3] * (t - span.l) * (t - span.l);
}

// sqrt(𝑥˙^2(𝑡) + ˙𝑦^2(𝑡) + ˙𝑧^2(𝑡))
double under_integral_span_length(Span span, double t)
{
    return sqrt(dif(span, 0, t) * dif(span, 0, t) + dif(span, 1, t) * dif(span, 1, t) + dif(span, 2, t) * dif(span, 2, t));
}

//переделать
double span_length(Span span)
{
    double res = 0;
    double step = (span.r - span.l) / SIMP_ACC;

    for (int k = 1; k <= SIMP_ACC - 1; k += 2)
    {
        res += under_integral_span_length(span, span.l + (k - 1) * step) + 4 * under_integral_span_length(span, span.l + k * step) + under_integral_span_length(span, span.l + (k + 1) * step);
    }
    res *= step / 3;

    return res;
}

int main(void)
{
    int N;
    double length = 0;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &N); //читаем переменные из файла
    Span *curve = malloc(sizeof(Span) * N);
    for (int i = 0; i < N; i++)
    {
        scanf("%lf %lf", &curve[i].l, &curve[i].r);
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 4; k++)
                scanf("%lf", &curve[i].coord[j].c[k]);
    }

    //тест сканирования
    /*for (int i = 0; i < N; i++)
    {
        printf("%.2lf %.2lf\n", curve[i].l, curve[i].r);
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 4; k++)
                printf("%.2lf ", curve[i].coord[j].c[k]);
        printf("\n");
        }
    }*/

    //подсчёты
    for (int i = 0; i < N; i++)
    {
        length += span_length(curve[i]);
    }

    //вывод
    printf("%.16lf", length);

    return 0;
}