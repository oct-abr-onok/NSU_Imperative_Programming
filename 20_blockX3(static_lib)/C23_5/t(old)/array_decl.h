#define TCAT2(a, b) a##_##b
#define CAT2(a, b) TCAT2(a, b)

typedef struct NAME
{
    int n;     // number of elements in array
    TYPE *arr; // points to the array of elements
    int cap;   // any other members can be added here
} NAME;

// initializes members of [vec] structure for empty array
void CAT2(NAME, init)(NAME *vec);//

// makes array [vec] empty and frees its array buffer [vec->arr]
// note: this function can be called many times
void CAT2(NAME, destroy)(NAME *vec);//

// adds element [value] to the end of array [vec]
// returns index of the added element
int CAT2(NAME, push)(NAME *vec, TYPE value);//

// removes the last element from array [vec]
// returns removed element
TYPE CAT2(NAME, pop)(NAME *vec);//

// ensures that array [vec] has enough storage for [capacity] elements
// note: address of elements surely won’t change before [vec->n] exceeds capacity
void CAT2(NAME, reserve)(NAME *vec, int capacity);//

// changes number of elements in array [vec] to [newCnt]
// if the number increases, new elements get value [fill]
// if the number decreases, some elements at the end are removed
void CAT2(NAME, resize)(NAME *vec, int newCnt, TYPE fill);//

// inserts elements [arr[0]], [arr[1]], [arr[2]], ..., [arr[num-1]]
// in-between elements [vec->arr[where-1]] and [vec->arr[where]]
// note: the whole array [arr] cannot be part of array [vec]
//[where] may vary from 0 to [vec->n], [num] can also be zero
void CAT2(NAME, insert)(NAME *vec, int where, TYPE *arr, int num);//

// removes elements [vec->arr[k]] for k = [where], [where+1], ..., [where+num-1]
// all the elements starting from [where+num]-th are shifted left by [num] positions
void CAT2(NAME, erase)(NAME *vec, int where, int num);//
