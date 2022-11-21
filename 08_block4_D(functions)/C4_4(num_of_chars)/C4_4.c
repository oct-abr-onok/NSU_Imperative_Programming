#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*char test[6] = {'0', '9', 'a', 'z', 'A', 'Z'};*/

int calcLetters(char *iStr, int *oLowerCnt, int *oUpperCnt, int *oDigitsCnt)
{
    int len = 0;
    *oLowerCnt = 0, *oUpperCnt = 0, *oDigitsCnt = 0;

    for (int i = 0;; i++) //чекаем все символы и считаем нужные категории
    {
        if (iStr[i] == 0)
        {
            len = i;
            break;
        }

        if (iStr[i] >= 48 && iStr[i] <= 57)
        {
            *oDigitsCnt += 1;
        }
        if (iStr[i] >= 97 && iStr[i] <= 122)
        {
            *oLowerCnt += 1;
        }
        if (iStr[i] >= 65 && iStr[i] <= 90)
        {
            *oUpperCnt += 1;
        }
    }

    return len;
}

int main(void)
{
    int N = 0, oLowerCnt, oUpperCnt, oDigitsCnt, len;
    char str[101];

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (gets(&str[0])) //очевидно ʕ ᵔᴥᵔ ʔ
    {
        N++;
        len = calcLetters(&str[0], &oLowerCnt, &oUpperCnt, &oDigitsCnt);
        printf("Line %d has %d chars: %d are letters (%d lower, %d upper), %d are digits.\n", N, len, oLowerCnt + oUpperCnt, oLowerCnt, oUpperCnt, oDigitsCnt);
    }

    return 0;
}