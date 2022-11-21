typedef struct IntegerSet_s
{
    int *val;
    int cnt;
} IntegerSet;

#ifdef _WIN32
__declspec(dllexport)
#else
__attribute__((visibility("default")))
#endif
    IntegerSet *CreateSet(int *arr, int cnt);

#ifdef _WIN32
__declspec(dllexport)
#else
__attribute__((visibility("default")))
#endif
    int IsInSet(IntegerSet *set, int x);