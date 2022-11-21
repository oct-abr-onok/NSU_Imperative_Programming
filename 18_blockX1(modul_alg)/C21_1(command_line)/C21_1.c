#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int mflag = 0, oper_flag = -1, oper;
    long long m = 1000000000000000000, par[2], res;

    if (argc < 4) //программа запускается без параметров
    {
        fprintf(stderr, "No parameters specified.");
        return 13;
    }
    else
    {
        for (int i = 1; i < argc; i++) //чтение параметров
        {
            if (mflag == 1)
            {
                sscanf(argv[i], "%lld", &m);
                mflag = -1;
            }
            if (oper_flag == 0 || oper_flag == 1)
            {
                sscanf(argv[i], "%lld", &par[oper_flag]);
                oper_flag++;
            }
            if (strcmp(argv[i], "-m") == 0)
            {
                mflag = 1;
            }
            if (strcmp(argv[i], "add") == 0 || strcmp(argv[i], "sub") == 0 || strcmp(argv[i], "mul") == 0)
            {
                oper_flag = 0;
                if (strcmp(argv[i], "add") == 0)
                {
                    oper = 0;
                }
                if (strcmp(argv[i], "sub") == 0)
                {
                    oper = 1;
                }
                if (strcmp(argv[i], "mul") == 0)
                {
                    oper = 2;
                }
            }
        }

        switch (oper) //исчисление
        {
        case 0:
            res = (par[0] % m) + (par[1] % m);
            break;

        case 1:
            res = (par[0] % m) - (par[1] % m);
            break;

        case 2:
            res = (par[0] % m) * (par[1] % m);
            break;

        default:
            break;
        }
        res %= m;
        if (res < 0 && mflag == -1)
        {
            res += m;
        }

        printf("%lld", res); //вывод

        return 0;
    }
}