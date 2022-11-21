#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Tokens_s
{
    int num;    //количество слов в строке
    char **arr; //массив слов (каждый элемент –- строка, т.е. char*)
} Tokens;

void tokensSplit(Tokens *tokens, const char *str, const char *delims)
{
    //проверка, стоит ли записывать слова
    char only_num_flag = 0, mem, word_size_mem, isNewWord = 1, ignore_flag;
    int current_char = 0;
    char *word_mem = calloc(1000000, sizeof(char));
    if (tokens->arr == 0)
    {
        only_num_flag++;
    }

    tokens->num = 0;
    mem = str[0];
    for (int i = 1; mem != 0; i++)
    {
        //проверка, не является ли символ одним из разделительных
        ignore_flag = 0;
        for (int j = 0; delims[j] != 0; j++)
        {
            if (mem == delims[j])
            {
                ignore_flag++;
                if (!isNewWord)
                {
                    isNewWord++;
                }
            }
        }

        //прибавление новых слов
        if (isNewWord && !ignore_flag)
        {
            if (current_char && !only_num_flag) //отправляем слово в структуру
            {
                word_mem[current_char] = 0;
                tokens->arr[tokens->num - 1] = calloc(current_char + 1, sizeof(char));
                for (int i = 0; i <= current_char; i++)
                {
                    tokens->arr[tokens->num - 1][i] = word_mem[i];
                }
            }

            tokens->num += 1;
            isNewWord = 0;
            current_char = 0;
        }

        //запись слов
        if (!ignore_flag && !only_num_flag)
        {
            word_mem[current_char] = mem;
            current_char++;
        }

        mem = str[i];
    }
    //доотправляем, если было слово на конце строки
    if (current_char && !only_num_flag)
    {
        word_mem[current_char] = 0;
        tokens->arr[tokens->num - 1] = calloc(current_char + 1, sizeof(char));
        for (int i = 0; i <= current_char; i++)
        {
            tokens->arr[tokens->num - 1][i] = word_mem[i];
        }
    }

    free(word_mem);
}

void tokensFree(Tokens *tokens)
{
    //очистка памяти, если ещё не была очищена
    if (tokens->num)
    {

        tokens->num = 0;
        for (int i = 0; i < tokens->num; i++)
        {
            free(tokens->arr[i]);
        }
        free(tokens->arr);
    }
}

int main(void)
{
    int N;
    char *str = calloc(1000000, sizeof(char));

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    //чтение строки
    scanf("%s", str);

    //первый вызов
    Tokens token1;
    token1.num = 0;
    token1.arr = 0;
    char delims[5] = {'.', ',', ':', ';', 0};
    tokensSplit(&token1, str, &delims[0]);
    printf("%d\n", token1.num);

    //создаём массив под слова
    token1.arr = calloc(token1.num, sizeof(char *));

    //второй вызов функции
    tokensSplit(&token1, str, &delims[0]);
    for (int i = 0; i < token1.num; i++)
    {
        printf("%s\n", token1.arr[i]);
    }

    free(str);
    tokensFree(&token1);

    return 0;
}