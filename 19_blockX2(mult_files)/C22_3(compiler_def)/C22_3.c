#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    printf("Compiler: ");
#if defined(__GNUC__) && !defined(__clang__)
    printf("GCC\n");
#endif 
#if defined(_MSC_VER) && !defined(__clang__)
    printf("MSVC\n");
#endif
#ifdef __clang__
    printf("clang\n");
#endif
#ifdef __TINYC__
    printf("TCC\n");
#endif

    printf("Bitness: %d\n", sizeof(void *) * 8);

    printf("Asserts: ");
#ifdef NDEBUG
    printf("disabled\n");
#endif
#ifndef NDEBUG
    printf("enabled\n");
#endif

    return 0;
}