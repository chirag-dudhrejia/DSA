#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node* left;
    int data;
    struct node* right;
};

struct node* create();
void inorder(struct node* root);

int main()
{
    struct node* root = NULL;

    root = create();

    printf("\nInorder traversal : ");
    inorder(root);
    printf("\n\n");
    return 0;
}

void inorder(struct node* root)
{
    if (root == NULL) return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
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

    printf("\nEnter right node of %d", data);
    new_node->right = create();
    return new_node;
}