#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "integerset.h"

int main(void)
{
    int N;
    
    N = CreateSet((int*)0, 4)->x;
    
    printf("%d", N);

    return 0;
}