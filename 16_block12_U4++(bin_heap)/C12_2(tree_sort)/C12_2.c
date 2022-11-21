#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node_s
{
    int val;
    struct Node_s *l, *r;
} Node;

void swap(int *a, int *b)
{
    int mem;
    mem = *a;
    *a = *b;
    *b = mem;
}

unsigned int rand_32(void)
{
    int mem = 0;
    mem += (unsigned int)rand();
    mem = mem << 17;
    mem += (unsigned int)rand();
    return mem;
}

Node *add_to_tree(int x, Node *tree)
{
    if (tree == NULL)
    {
        tree = malloc(sizeof(Node));
        tree->val = x;
        tree->l = NULL;
        tree->r = NULL;
        return tree;
    }

    if (tree->val == x)
    {
        if (rand() % 2)
        {
            tree->l = add_to_tree(x, tree->l);
            return tree;
        }
        else
        {
            tree->r = add_to_tree(x, tree->r);
            return tree;
        }
    }
    if (x < tree->val)
    {
        tree->l = add_to_tree(x, tree->l);
        return tree;
    }
    if (x > tree->val)
    {
        tree->r = add_to_tree(x, tree->r);
        return tree;
    }
}

void random_shuffle(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int pos = abs((int)rand_32()) % (i + 1);
        swap(&arr[i], &arr[pos]);
    }
}

void free_tree(Node *tree)
{
    if (tree != NULL)
    {
        if (tree->l == NULL)
        {
            free_tree(tree->r);
        }
        if (tree->r == NULL)
        {
            free_tree(tree->l);
        }
        free(tree);
    }
}

void traverse(Node *tree, int *i, int *arr)
{
    if (tree == NULL)
        return;
    traverse(tree->l, i, arr);
    arr[*i] = tree->val;
    *i = *i + 1;
    traverse(tree->r, i, arr);
}

int main(void)
{
    FILE *fin = fopen("input.bin", "rb");
    FILE *fout = fopen("output.bin", "wb");

    //разметка
    int arr_size, traverse_counter = 0;
    fread(&arr_size, 4, 1, fin);
    int *arr = malloc(arr_size * sizeof(int));
    fread(arr, 4, arr_size, fin);
    srand(42);
    random_shuffle(arr, arr_size);
    Node *tree_root = NULL; //создаём дерево

    //заполняем дерево(вроде работает)
    for (int i = 0; i < arr_size; i++)
    {
        tree_root = add_to_tree(arr[i], tree_root);
    }

    //инфиксный обход дерева
    traverse(tree_root, &traverse_counter, arr);

    //вывод
    fwrite(arr, 4, arr_size, fout);

    //гарбач коллектор(-_-)
    free_tree(tree_root);
    free(arr);
    fclose(fin);
    fclose(fout);
}