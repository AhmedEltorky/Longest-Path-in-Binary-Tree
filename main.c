#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int data;
    struct _node *left_child;
    struct _node *right_child;
} Node;

int max(int l, int r)
{
    return (l > r) ? l : r;
}

int find_height(Node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    int left_height = find_height(root->left_child);
    int right_height = find_height(root->right_child);
    return max(left_height, right_height) + 1;
}

Node add_node(int n_data)
{
    Node temp;
    temp.data = n_data;
    temp.left_child = NULL;
    temp.right_child = NULL;
    return temp;
}

int main()
{
    Node n1 = {1, NULL, NULL};
    Node n2 = {2, NULL, NULL};
    Node n3 = {3, NULL, NULL};
    Node n4 = {4, NULL, NULL};
    Node n5 = {5, NULL, NULL};
    Node n6 = {6, NULL, NULL};
    Node n7 = {7, NULL, NULL};
    Node n8 = {8, NULL, NULL};
    Node n9 = {9, NULL, NULL};
    Node n10 = {10, NULL, NULL};

    Node *root = &n1;

    n1.left_child = &n2;
    n1.right_child = &n3;

    n2.left_child = &n4;
    n2.right_child = &n5;

    n3.left_child = &n6;
    n3.right_child = &n7;

    n5.left_child = &n8;
    n5.right_child = &n9;

    n9.right_child = &n10;

    printf("\nthe longest path in this tree = %d\n", find_height(root));

    return 0;
}

/* The Binary Tree 
           1 
         /    \
        /      \ 
       2        3 
     /   \     /  \ 
    4     5   6    7 
         / \
        8   9
             \
              10
*/