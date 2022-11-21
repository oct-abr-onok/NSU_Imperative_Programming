#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    char mem;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (1)
    {
        if (scanf("%c", &mem) != 1)
            break;

        if (mem == '/')
        {
            if (scanf("%c", &mem) != 1)
            {
                printf("/");
                break;
            }
            if (mem == '/') //случай '//'
            {
                while (1)
                {
                    if (scanf("%c", &mem) != 1)
                    {
                        break;
                    }
                    if (mem == '\n')
                    {
                        printf("\n");
                        break;
                    }
                }
            }
            else
            {
                if (mem == '*') //случай '/**/'
                {
                    while (1)
                    {
                        if (scanf("%c", &mem) != 1)
                            break;
                    flag:
                        if (mem == '\n')
                        {
                            printf("\n");
                        }
                        if (mem == '*')
                        {
                            if (scanf("%c", &mem) != 1)
                            {
                                break;
                            }
                            if (mem == '/')
                            {
                                break;
                            }
                            goto flag;
                        }
                    }
                }
                else
                {
                    printf("/");
                    printf("%c", mem);
                }
            }
        }
        else
        {
            printf("%c", mem);
        }
    }

    return 0;
}