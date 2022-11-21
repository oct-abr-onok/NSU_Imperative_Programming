#include <stdio.h>
#include <stdlib.h>

typedef struct State
{
    char *regs[256];
} State;

int main()
{
    char cur_str[1001];

    gets(cur_str);
#define TEST cur_str
    TEST;
    fflush(stdout);

    return 0;
}
