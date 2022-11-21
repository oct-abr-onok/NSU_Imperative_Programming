#define _CRT_SECURE_NO_WARNINGS
#define max(a, b) ((a > b) ? (a) : (b))
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Node_s
{
    int key;             //значение
    int hgt;             //высота дерева с вершиной в этой точке
    struct Node_s *s[2]; //сыновья 0 - левый, 1 - правый
} Node;

void free_tree(Node *tree)
{
    if (tree != NULL)
    {
        if (tree->s[0] == NULL)
        {
            free_tree(tree->s[1]);
        }
        if (tree->s[1] == NULL)
        {
            free_tree(tree->s[0]);
        }
        free(tree);
    }
}

void swap(int *a, int *b)
{
    int mem;
    mem = *a;
    *a = *b;
    *b = mem;
}

void update_hgt(Node *v)
{
    int lrhgt[2] = {-1, -1}; //рассмотр случаев с отсутствующими сыновьями
    for (int i = 0; i < 2; i++)
    {
        if (v->s[i] != NULL)
        {
            lrhgt[i] = v->s[i]->hgt;
        }
    }

    v->hgt = 1 + max(lrhgt[0], lrhgt[1]); //не забудьте про случай пустых поддеревьев!
}

Node *small_rotate(int direction, Node *tree) //direction == 0 ? right : left
{
    Node *mem;
    mem = tree->s[direction];
    tree->s[direction] = mem->s[!direction];
    mem->s[!direction] = tree;
    update_hgt(tree); //обновить высоту?
    update_hgt(mem);
    return mem;
}

Node *big_rotate(int direction, Node *tree) //direction == 0 ? right : left
{
    tree->s[direction] = small_rotate(!direction, tree->s[direction]);
    return small_rotate(direction, tree);
}

Node *rebalance(Node *tree)
{
    int lrhgt[2] = {-1, -1}; //рассмотр случаев с отсутствующими сыновьями
    for (int i = 0; i < 2; i++)
    {
        if (tree->s[i] != NULL)
        {
            lrhgt[i] = tree->s[i]->hgt;
        }
    }

    if (abs(lrhgt[0] - lrhgt[1]) == 2) //баланс нарушен
    {
        int direction = ((lrhgt[1] - lrhgt[0] == 2) ? 0 : 1);

        if (tree->s[!direction]->s[!direction] != NULL && tree->s[!direction]->s[!direction]->hgt == lrhgt[direction] + 1) //случай а)(ленивые вычисления пригодились)
        {
            return small_rotate(!direction, tree);
        }
        else //случай б)
        {
            return big_rotate(!direction, tree);
        }
    }
    return tree;
}

Node *add(FILE *file, int x, Node *tree)
{
    if (tree == NULL)
    {
        tree = malloc(sizeof(Node));
        tree->key = x;
        tree->s[0] = NULL;
        tree->s[1] = NULL;
        fprintf(file, "added\n");
        update_hgt(tree);
        return rebalance(tree);
    }

    if (tree->key == x)
    {
        fprintf(file, "dupe\n");
        return tree;
    }
    if (x < tree->key)
    {
        tree->s[0] = add(file, x, tree->s[0]);
        update_hgt(tree);
        return rebalance(tree);
    }
    if (x > tree->key)
    {
        tree->s[1] = add(file, x, tree->s[1]);
        update_hgt(tree);
        return rebalance(tree);
    }
}

Node *lower(FILE *file, int x, Node *tree)
{
    if (tree == NULL)
    {
        return NULL;
    }
    if (x <= tree->key)
    {
        Node *lower_res = lower(file, x, tree->s[0]);
        if (lower_res == NULL)
        {
            return tree;
        }
        else
        {
            return lower_res;
        }
    }
    else
    {
        return lower(file, x, tree->s[1]);
    }
}

//1) Выполняем Remove как в обычном дереве поиска
//2) Поднимаемся от удалённой вершины вверх до корня, запускаем для каждой вершины перебалансировку, если нужно.
Node *remve(FILE *file, int x, Node *tree)
{
    if (tree == NULL)
    {
        fprintf(file, "miss\n");
        return tree;
    }

    if (tree->key == x)
    {
        Node *mem[2] = {tree->s[0], tree->s[1]};
        if (mem[0] == NULL || mem[1] == NULL)
        {
            if (mem[0] != NULL)
            {
                free(tree);
                fprintf(file, "removed\n");
                return mem[0];
            }
            else
            {
                free(tree);
                fprintf(file, "removed\n");
                return mem[1];
            }
        }
        else //hard case....................................(возможно надо фиксить)
        {
            Node *lower_res;
            lower_res = lower(file, tree->key, tree->s[1]); //ближайший правый сосед ФУНКЦИЯ БЫЛА НИЖЕ
            swap(&tree->key, &lower_res->key);
            tree->s[1] = remve(file, x, tree->s[1]);
            if (tree->s[1] != NULL)
            {
                update_hgt(tree->s[1]);
                rebalance(tree->s[1]);
            }
            update_hgt(tree);
            return rebalance(tree);
        }
    }
    if (x < tree->key)
    {
        tree->s[0] = remve(file, x, tree->s[0]);
        update_hgt(tree);
        return rebalance(tree);
    }
    if (x > tree->key)
    {
        tree->s[1] = remve(file, x, tree->s[1]);
        update_hgt(tree);
        return rebalance(tree);
    }
}

int main(void)
{
    FILE *fin = fopen("input.txt", "rb");
    FILE *fout = fopen("output.txt", "wb");

    //разметка
    char **commands = malloc(sizeof(char *) * 3);
    commands[0] = "add";
    commands[1] = "remove";
    commands[2] = "lower";
    char curr_command[7];
    int commands_cnt;
    int x;
    Node *lower_res;
    Node *tree_root = NULL;

    //выполнение комманд
    fscanf(fin, "%d", &commands_cnt);
    for (int i = 0; i < commands_cnt; i++)
    {
        fscanf(fin, " ");
        fscanf(fin, "%s", curr_command);
        fscanf(fin, "%d", &x);
        for (int j = 0; j < 3; j++)
        {
            // if (i == 7)
            // {
            //     i = 7;
            //     double tst = -1;
            //     tst = 7;
            // }
            if (strcmp(curr_command, commands[j]) == 0)
            {
                switch (j)
                {
                case 0:
                    tree_root = add(fout, x, tree_root);
                    break;
                case 1:
                    tree_root = remve(fout, x, tree_root); //to be tested
                    break;
                case 2:
                    lower_res = lower(fout, x, tree_root);
                    if (lower_res == NULL)
                    {
                        fprintf(fout, "###\n");
                    }
                    else
                    {
                        fprintf(fout, "%d\n", lower_res->key);
                    }

                    break;
                default:
                    break;
                }
                fflush(fout);
            }
        }
    }

    //гарбач коллектор(-_-)
    free_tree(tree_root);
    free(commands);
    fclose(fin);
    fclose(fout);
}