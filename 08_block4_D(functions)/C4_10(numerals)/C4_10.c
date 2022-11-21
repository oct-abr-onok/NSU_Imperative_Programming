#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//ochen’ vesyolaya zadacha
int main(void)
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    //char test = '';
    int N, number, type;
    int mem[9] = {0};

    scanf("%d", &N); //читаем переменные из файла
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &number); //читаем число
        for (int i = 0; i < 9; i++)
        {
            mem[i] = number % 10;
            number /= 10;
        }

        for (int k = 0; k < 3; k++)
        {
            type = -1;

            switch (mem[8 - k * 3]) //сотни
            {
            case 0:

                break;

            case 1:
                type = 0;
                printf("sto ");
                break;

            case 2:
                type = 0;
                printf("dvesti ");
                break;

            case 3:
                type = 0;
                printf("trista ");
                break;

            case 4:
                type = 0;
                printf("chetyresta ");
                break;

            case 5:
                type = 0;
                printf("pyat'sot ");
                break;

            case 6:
                type = 0;
                printf("shest'sot ");
                break;

            case 7:
                type = 0;
                printf("sem'sot ");
                break;

            case 8:
                type = 0;
                printf("vosem'sot ");
                break;

            case 9:
                type = 0;
                printf("devyat'sot ");
                break;

            default:
                break;
            }

            if (mem[7 - k * 3] == 1) //10-19
            {
                type = 0;
                switch (mem[6 - k * 3])
                {
                case 0:
                    printf("desyat' ");
                    break;

                case 1:
                    printf("odinnadtsat' ");
                    break;

                case 2:
                    printf("dvenadtsat' ");
                    break;

                case 3:
                    printf("trinadtsat' ");
                    break;

                case 4:
                    printf("chetyrnadtsat' ");
                    break;

                case 5:
                    printf("pyatnadtsat' ");
                    break;

                case 6:
                    printf("shestnadtsat' ");
                    break;

                case 7:
                    printf("semnadtsat' ");
                    break;

                case 8:
                    printf("vosemnadtsat' ");
                    break;

                case 9:
                    printf("devyatnadtsat' ");
                    break;

                default:
                    break;
                }
            }
            else
            {
                switch (mem[7 - k * 3]) //десятки
                {
                case 0:
                    break;

                case 2:
                    type = 0;
                    printf("dvadtsat' ");
                    break;

                case 3:
                    type = 0;
                    printf("tridtsat' ");
                    break;

                case 4:
                    type = 0;
                    printf("sorok ");
                    break;

                case 5:
                    type = 0;
                    printf("pyat'desyat ");
                    break;

                case 6:
                    type = 0;
                    printf("shest'desyat ");
                    break;

                case 7:
                    type = 0;
                    printf("sem'desyat ");
                    break;

                case 8:
                    type = 0;
                    printf("vosem'desyat ");
                    break;

                case 9:
                    type = 0;
                    printf("devyanosto ");
                    break;

                default:
                    break;
                }

                switch (mem[6 - k * 3]) //единицы
                {
                case 0:
                    break;

                case 1:
                    type = 1;
                    if (k == 0)
                    {
                        printf("odin ");
                    }
                    else
                    {
                        printf("odna ");
                    }
                    break;

                case 2:
                    type = 2;
                    if (k == 0)
                    {
                        printf("dva ");
                    }
                    else
                    {
                        printf("dve ");
                    }
                    break;

                case 3:
                    type = 2;
                    printf("tri ");
                    break;

                case 4:
                    type = 2;
                    printf("chetyre ");
                    break;

                case 5:
                    type = 0;
                    printf("pyat' ");
                    break;

                case 6:
                    type = 0;
                    printf("shest' ");
                    break;

                case 7:
                    type = 0;
                    printf("sem' ");
                    break;

                case 8:
                    type = 0;
                    printf("vosem' ");
                    break;

                case 9:
                    type = 0;
                    printf("devyat' ");
                    break;

                default:
                    break;
                }
            }

            switch (k)
            {
            case 0:
                switch (type) //окончание
                {
                case 0:
                    printf("millionov ");
                    break;

                case 1:
                    printf("million ");
                    break;

                case 2:
                    printf("milliona ");
                    break;

                default:
                    break;
                }
                break;

            case 1:
                switch (type) //окончание
                {
                case 0:
                    printf("tysyach ");
                    break;

                case 1:
                    printf("tysyacha ");
                    break;

                case 2:
                    printf("tysyachi ");
                    break;

                default:
                    break;
                }
                break;

            case 2:
                switch (type) //окончание
                {
                case -1:
                    printf("strok");
                    break;

                case 0:
                    printf("strok");
                    break;

                case 1:
                    printf("stroka");
                    break;

                case 2:
                    printf("stroki");
                    break;

                default:
                    break;
                }
                break;

            default:
                break;
            }
        }
        if (i != N - 1)
        {
            printf("\n");
        }
    }
    return 0;
}
//HELP ME PLEASE!!!