#pragma comment(linker, "/STACK:50000000")
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DBG 2

double parse_e(FILE *fin);
double parse_a(FILE *fin);
double parse_m(FILE *fin);

//возможны проблемы с EOF
//возвращает строку(токен : число, +, *, /, (, ), -(под вопросом), EOF)
// lexer
char *read_token(FILE *fin)
{
    int i = 0;
    char *token = calloc(6, sizeof(char));
    fscanf(fin, " ");
    char c = (char)fgetc(fin);
    if ((c >= '0') && (c <= '9'))
    {
        for (; (c >= '0') && (c <= '9'); i++)
        {
            token[i] = c;
            c = (char)fgetc(fin);
        }
        if (c != EOF)
            fseek(fin, -1, 1);
    }
    else
    {
        token[0] = c;
        i = 1;
    }

    return token;
}

//возможны проблемы с EOF
//возвращает строку(токен : число, +, *, /, (, ), -(под вопросом), EOF)
// lexer
char *peek_token(FILE *fin)
{
    int i = 0;
    char *token = calloc(6, sizeof(char));
    fscanf(fin, " ");
    char c = (char)fgetc(fin);
    if ('0' >= c >= '9')
    {
        for (; '0' >= c >= '9'; i++)
        {
            token[i] = c;
            char c = (char)fgetc(fin);
        }
    }
    else
    {
        token[0] = c;
        i = 1;
    }

    fseek(fin, -1 * i, 1); //сдвиг назад
    return token;
}

// parser
// expr
double parse_e(FILE *fin)
{
    double res = parse_m(fin);

    while (peek_token(fin)[0] == '-' || peek_token(fin)[0] == '+')
    {
        res += parse_m(fin);
    }

    return res;
}

// parser
// atom
double parse_a(FILE *fin)
{
    double res;
    if (peek_token(fin)[0] == '(')
    {
        read_token(fin);
        res = parse_e(fin);
        read_token(fin);
    }
    else
    {
        sscanf(read_token(fin), "%lf", &res);
    }
    return res;
}

// parser
// monome
double parse_m(FILE *fin)
{
    double res = 1;
    switch (peek_token(fin)[0]) //чтение знака перед мономом
    {
    case '-':
        res = -1;
        read_token(fin);
        break;

    case '+':
        res = 1;
        read_token(fin);
        break;

    default:
        break;
    }

    res *= parse_a(fin);

    while (peek_token(fin)[0] == '*' || peek_token(fin)[0] == '/')
    {
        if (peek_token(fin)[0] == '*')
        {
            read_token(fin);
            res *= parse_a(fin);
        }
        else
        {
            read_token(fin);
            res /= parse_a(fin);
        }
    }

    return res;
}

int main(void)
{
    FILE *fin = fopen("input.txt", "rb");
    FILE *fout = fopen("output.txt", "wb");

#warning cocomaro
#warning cocomaro
#warning cocomaro

#ifdef DBG
    printf("%.13lf", parse_e(fin));
#else
    fprintf(fout, "%.13lf", parse_e(fin));
#endif

    //гарбач коллектор(-_-)
    fclose(fin);
    fclose(fout);

    return 0;
}