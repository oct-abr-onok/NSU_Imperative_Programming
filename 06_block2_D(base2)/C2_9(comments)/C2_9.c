#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    int N;
    char mem, mem1, left, right;
    
    FILE* input = freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    while (1) 
    {
        if (scanf("%c", &mem) != 1)
            break ;
        if (mem == '/')
        {
            mem1 = mem;
            scanf("%c", &mem);
            if (feof(input))
            {
                printf("/");
                goto end;
            }

            switch (mem)
            {
            case '/': //случай однострочного комментария
                while (mem != '\n')
                {
                    //scanf("%c", &mem);
                    if (scanf("%c", &mem) != 1)
                    {
                        goto end;
                    }
                }
                break;
            
            case '*': //случай блочного комментария
                //scanf("%c", &mem);
                while (1)
                {
                    scanf("%c", &mem);
                    if (feof(input))
                    {
                        goto end;
                    }
                    if (mem == '\n')
                    {
                        printf("%c", mem);
                    }
                    starif:
                    if (mem == '*')
                    {
                        scanf("%c", &mem);
                        if (feof(input))
                        {
                            goto end;
                        }
                        if (mem == '/')
                        {
                            
                            if (feof(input))
                            {
                                goto end;
                            }
                            break;
                        }
                        else
                            goto starif;
                    }
                }
                break;

            default:
                
                printf("%c", mem1);
                break;
            }          
        }
        if (mem == '/')
        {
            ;
        }
        else
            printf("%c", mem); 
    }

    end:
    return 0;
} 