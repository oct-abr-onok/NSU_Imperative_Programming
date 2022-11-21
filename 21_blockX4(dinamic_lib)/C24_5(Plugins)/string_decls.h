#ifndef STRING_DLL_239
#define STRING_DLL_239
#ifdef _WIN32
#define DLL __declspec(dllexport)
#else
#define DLL __attribute__((visibility("default")))
#endif

typedef struct State
{
    char *regs[256];
} State;

// loads string A from I-th register ([idx0] contains its index)
// loads string B from J-th register ([idx1] contains its index)
// then stores concatenation of A and B into I-th register
// BEWARE: [idx0] and [idx1] are allowed to be equal indices
void concat_2(State *state, char *idx0, char *idx1);
// extracts sequence of tokens/words separated by underscore character from string [arg]
// puts K –- number of tokens into 0-th register
// puts the tokens into 1-th, 2-th, ..., K-th registers (in correct order)
void tokenize_1(State *state, char *arg);

#endif