#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *left;
    int data;
    struct node *right;
};

struct node* create();
void preorder(struct node* root);

int main()
{
    struct node *root;

    root = create();

    printf("\nPreorder traversal : ");
    preorder(root);
    printf("\n\n");
    return 0;
}

void preorder(struct node* root)
{
    if (root == NULL) return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

struct node* create()
{
    int data;
    struct node* new_node = NULL;
    new_node = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter data (-1 for no node) : ");
    scanf("%d", &data);

    if (data == -1) return 0;
    
    new_node->data = data;
    printf("\nEnter left child of %d", data);
    new_node->left = create();

    printf("\nEnter right child of %d", data);
    new_node->right = create();
    return new_node;
}