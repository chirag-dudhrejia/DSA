#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node* left;
    int data;
    struct node* right;
};

struct node* create();
void postorder(struct node* root);

int main()
{
    struct node* root = NULL;

    root = create();

    printf("\nPostorder traversal : ");
    postorder(root);
    printf("\n\n");
    return 0;
}

void postorder(struct node* root)
{
    if (root == NULL) return ;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
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
    printf("\nEnter left node of %d", data);
    new_node->left = create();

    printf("\nEnter right node of %d", data);
    new_node->right = create();
    return new_node;
}