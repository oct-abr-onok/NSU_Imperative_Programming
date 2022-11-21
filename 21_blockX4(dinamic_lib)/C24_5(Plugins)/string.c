#include "string_decls.h"
#include <string.h>
#include <stdlib.h>

typedef struct Vector_s
{
    char *arr;
    int cnt;
    int cap;
} Vector;

void push(Vector *V, char x)
{
    if (V->cnt == V->cap)
    {
        V->arr = realloc(V->arr, V->cap * 2 * sizeof(char));
        V->cap *= 2;
    }
    V->arr[V->cnt++] = x;
}

// loads string A from I-th register ([idx0] contains its index)
// loads string B from J-th register ([idx1] contains its index)
// then stores concatenation of A and B into I-th register
// BEWARE: [idx0] and [idx1] are allowed to be equal indices
void concat_2(State *state, char *idx0, char *idx1)
{
    int len0 = strlen(state->regs[*idx0]), len1 = strlen(state->regs[*idx1]);
    char *A = calloc(len0 + len1 + 1, sizeof(char));
    memcpy(A, state->regs[*idx0], sizeof(char) * len0);
    memcpy(&A[len0], state->regs[*idx1], sizeof(char) * len1);
    state->regs[*idx0] = calloc(len1 + len0 + 1, sizeof(char));
    memcpy(state->regs[*idx0], A, sizeof(char) * (len1 + len0 + 1));
    free(A);
}

// extracts sequence of tokens/words separated by underscore character from string [arg]
// puts K –- number of tokens into 0-th register
// puts the tokens into 1-th, 2-th, ..., K-th registers (in correct order)
void tokenize_1(State *state, char *arg)
{
    int K = 1;
    int flag;
    Vector cur_token;

    cur_token.arr = calloc(1, sizeof(char));
    cur_token.cap = 1;
    cur_token.cnt = 0;
    for (int i = 0; arg[i] != 0;)
    {
        flag = 0;
        for (int j = 0; arg[i] != '_' && arg[i] != 0; j++)
        {
            push(&cur_token, arg[i]);
            flag++;
            i++;
        }
        if (arg[i] == '_')
        {
            i++;
        }
        if (flag == 1)
        {
            state->regs[K] = calloc(cur_token.cnt + 1, sizeof(char));
            memcpy(state->regs[K], cur_token.arr, sizeof(char) * cur_token.cnt);
            free(cur_token.arr);
            K++;
            flag = 0;
            cur_token.arr = calloc(1, sizeof(char));
            cur_token.cap = 1;
            cur_token.cnt = 0;
        }
    }
    state->regs[0] = calloc(2, sizeof(char));
    state->regs[0][0] = (char)(K + 47);
}