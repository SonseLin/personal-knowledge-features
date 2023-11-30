/*
  it doesnt work properly
  uploaded in study purposes
  guess or trees doesnt very good
  or is more likely that my skill doesnt
  high ATM. Hope the second is the truth
*/


#include <stdio.h>
#include <stdlib.h>

typedef struct Tree_fib
{
    int n;
    int value;
    struct Tree_fib *left;
    struct Tree_fib *right;
} Tree_fib;

int fib(int n, Tree_fib *root);
Tree_fib *init_root(int n, int fib_value);
void add_fib_value(Tree_fib *root, Tree_fib *new);
void search_for_n_in_tree(Tree_fib *root, int n, int *value, int *is_found);
void print_tree(Tree_fib *tree);

int main()
{
    Tree_fib *root = init_root(0, 0);
    for (int i = 0; i < 50; i++)
    {
        int value = -1;
        int is_found = 0;
        search_for_n_in_tree(root, i, &value, &is_found);
    }
    print_tree(root);
    return 0;
}

int fib(int n, Tree_fib *root)
{
    int is_found = 0;
    int value = -1;
    search_for_n_in_tree(root, n, &value, &is_found);
    if (is_found)
    {
        return value;
    }
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return fib(n - 1, root) + fib(n - 2, root);
    }
}

Tree_fib *init_root(int n, int fib_value)
{
    Tree_fib *new = malloc(sizeof(Tree_fib));
    new->n = n;
    new->value = fib_value;
    new->left = NULL;
    new->right = NULL;
    return new;
}

void add_fib_value(Tree_fib *root, Tree_fib *new)
{
    if (root->n > new->n)
    {
        if (root->left != NULL)
        {
            add_fib_value(root->left, new);
        }
        else
        {
            root->left = new;
        }
    }
    else if (root->n < new->n)
    {
        if (root->right != NULL)
        {
            add_fib_value(root->right, new);
        }
        else
        {
            root->right = new;
        }
    }
}

void search_for_n_in_tree(Tree_fib *root, int n, int *value, int *is_found)
{
    if (root == NULL)
    {
        return;
    }

    if (root->n == n)
    {
        *value = root->value;
        *is_found = 1;
        return;
    }

    if (root->n > n)
    {
        search_for_n_in_tree(root->left, n, value, is_found);
    }
    else
    {
        search_for_n_in_tree(root->right, n, value, is_found);
    }

    if (!*is_found && root->n != n)
    {
        Tree_fib *new = init_root(n, fib(n, NULL));
        add_fib_value(root, new);
        *is_found = 1;
    }
}

void print_tree(Tree_fib *tree)
{
    if (tree == NULL)
    {
        return;
    }

    print_tree(tree->left);
    print_tree(tree->right);
    printf("%d\n", tree->value);
}
