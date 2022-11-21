#include "hashmap.h"
#include <stdlib.h>

HashMap HM_Init(EqualFunc ef, HashFunc hf, int size)
{
    //создаём таблицу(open addressng массив)
    HashMap hashmap;
    hashmap.elems = calloc(size, sizeof(Elem));
    hashmap.size = size;
    hashmap.hf = hf;
    hashmap.ef = ef;

    return hashmap;
}

void HM_Destroy(HashMap *self)
{
    free(self->elems);
}

cpvoid HM_Get(const HashMap *self, cpvoid key)
{
    uint32_t i;
    for (i = self->hf(key) % self->size;; i = (i + 1) % self->size) // open addressing
    {
        if (self->elems[i].key == NULL)
        {
            return NULL;
        }
        int t = self->ef(key, self->elems[i].key);
        if (self->ef(key, self->elems[i].key) == 1)
        {
            break;
        }
    }
    return self->elems[i].value;
}

void HM_Set(HashMap *self, cpvoid key, cpvoid value)
{
    uint32_t i;
    for (i = self->hf(key) % self->size;; i = (i + 1) % self->size) // open addressing
    {
        if (self->elems[i].key == NULL || self->ef(key, self->elems[i].key) == 1) //абьюз лейзи вычислений
        {
            break;
        }
    }
    self->elems[i].value = value;
    self->elems[i].key = key;
}