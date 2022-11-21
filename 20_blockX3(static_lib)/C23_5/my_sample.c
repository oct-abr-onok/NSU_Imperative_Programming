#include "sample.h"
#include <assert.h>
#define TYPE double
#define NAME vector
#include "array_def.h"
#define TYPE int
#define NAME indices
#include "array_def.h"
#include <stdio.h>

int main()
{
    vector values;
    vector_init(&values);
    for (int i = 0; i < values.n; i++)
    {
        printf("%lf", values.arr[i]);
    }
    printf("n:%d c:%d", values.n, values.cap);
    printf("\n");

    printf("%d\n", vector_push(&values, 30));
    for (int i = 0; i < values.n; i++)
    {
        printf("%.0lf ", values.arr[i]);
    }
    printf("(n:%d c:%d)", values.n, values.cap);
    printf("\n");

        printf("%d\n", vector_push(&values, 30));
    for (int i = 0; i < values.n; i++)
    {
        printf("%.0lf ", values.arr[i]);
    }
    printf("(n:%d c:%d)", values.n, values.cap);
    printf("\n");


        printf("%d\n", vector_push(&values, 29));
    for (int i = 0; i < values.n; i++)
    {
        printf("%.0lf ", values.arr[i]);
    }
    printf("(n:%d c:%d)", values.n, values.cap);
    printf("\n");

        printf("%.0lf\n", vector_pop(&values));
    for (int i = 0; i < values.n; i++)
    {
        printf("%.0lf ", values.arr[i]);
    }
    printf("(n:%d c:%d)", values.n, values.cap);
    printf("\n");

        printf("%.0lf\n", vector_pop(&values));
    for (int i = 0; i < values.n; i++)
    {
        printf("%.0lf ", values.arr[i]);
    }
    printf("(n:%d c:%d)", values.n, values.cap);
    printf("\n");


    vector_reserve(&values, 16);
    for (int i = 0; i < values.n; i++)
    {
        printf("%.0lf ", values.arr[i]);
    }
    printf("(n:%d c:%d)", values.n, values.cap);
    printf("\n");

    vector_reserve(&values, 0);
    for (int i = 0; i < values.n; i++)
    {
        printf("%.0lf ", values.arr[i]);
    }
    printf("(n:%d c:%d)", values.n, values.cap);
    printf("\n");

        vector_resize(&values,16 ,0);
    for (int i = 0; i < values.n; i++)
    {
        printf("%.0lf ", values.arr[i]);
    }
    printf("(n:%d c:%d)", values.n, values.cap);
    printf("\n");



    double arr[6] = {7,8,7,8,7,8};
    vector_insert(&values, 16, arr, 4);
    for (int i = 0; i < values.n; i++)
    {
        printf("%.0lf ", values.arr[i]);
    }
    printf("(n:%d c:%d)insert", values.n, values.cap);
    printf("\n");

        vector_erase(&values, 16, 4);
    for (int i = 0; i < values.n; i++)
    {
        printf("%.0lf ", values.arr[i]);
    }
    printf("(n:%d c:%d)erase", values.n, values.cap);
    printf("\n");


    return 0;
}