#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void)
{
    int cnt = 0, IsNewWord = 1;
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    char symbol;
    scanf ("%c", &symbol);

    while (symbol != '\n')
    {
        if (IsNewWord && (symbol != '.')) //считаем новое слово только, когда стоит символ, отличный от точки, после точки + считаем первое слово без точки
        {
            cnt++;
            IsNewWord = 0;
        }
        if (symbol == '.')
        {
            IsNewWord = 1;
        }
        scanf ("%c", &symbol);
    }
    
    printf("%d", cnt); //выводим результат

    return 0;
}