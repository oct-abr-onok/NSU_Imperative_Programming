#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void)
{
    int a, b;
    
    scanf("%d", &a);
    scanf("%d", &b);
    printf("%d\n", a * b);
    printf("%d ", a % b);
    printf("%d", b % a);

    return 0;
}