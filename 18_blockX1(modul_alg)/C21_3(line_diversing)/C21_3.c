#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char str[101];

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    gets(str);

    for (int i = 0; str[i] != 0; )
    {
        if (str[i] == 32)
        {
            i++;
            continue;
        }
        if (str[i] == 34) //в кавычках
        {
            printf("[");
            i++;
            while (str[i] != 34)
            {
                printf("%c", str[i]);
                i++;
            }
            printf("]\n");
        }
        else //без кавычек
        {
            printf("[");
            while (str[i] != 32 && str[i] != 0)
            {
                if (str[i] == 0)
                {
                    break;
                }
                printf("%c", str[i]);
                i++;
            }
            printf("]\n");
            if (str[i] == 0)
            {
                break;
            }
        }
        i++;
    }

    return 0;
}