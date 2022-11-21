#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int check(char *slovo)
{
    if (!strcmp(slovo, "-m"))
        return 0;
    if (!strcmp(slovo, "add"))
        return 1;
    if (!strcmp(slovo, "sub"))
        return 2;
    if (!strcmp(slovo, "mul"))
        return 3;
    return -1;
}

int main(int argc, char **argv)
{
    long long int m = 0, x = 0;
    if (argc <= 1)
    {
        fprintf(stderr, "No parameters specified.");
        return 13;
    }
    for (int i = 1; i < argc; i += 2)
    {
        switch (check(argv[i]))
        {
        case 0:
            m = atoll(argv[i + 1]);
            break;
        case 1:
            x = atoll(argv[1 + i]) + atoll(argv[2 + i]);
            i++;
            break;
        case 2:
            x = atoll(argv[1 + i]) - atoll(argv[2 + i]);
            i++;
            break;
        case 3:
            x = atoll(argv[1 + i]) * atoll(argv[2 + i]);
            i++;
            break;
        }
    }
    if (m)
        x = (x % m + m) % m;
    fprintf(stdout, "%lld", x);
    return 0;
}
