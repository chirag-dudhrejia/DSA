#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *left;
    int data;
    struct node *right;
};

struct node *create_node(int data);
struct node *insert(struct node *root, int data);
void inorder(struct node *root);
struct node* search(struct node* root, int key);

int main()
{
    int data, option = -1;
    struct node *root;

    while (option != 0)
    {
        printf("\nChoose Task to perform.\n1. Create First node\n2. Insert\n3. Search\n4. Inorder Traversal\n4. Delete\n0. Exit.\n");
        scanf("%d", &option);

        if (option == 1)
        {
            printf("\nEnter data : ");
            scanf("%d", &data);
            root = create_node(data);
        }
        else if (option == 2)
        {
            printf("\nEnter data : ");
            scanf("%d", &data);
            root = insert(root, data); 
        }
        else if (option == 3)
        {
            printf("\nWhat do you want to search? : ");
            scanf("%d", &data);
            if (search(root, data)) printf("\n%d found", data);
            else printf("\n%d not found", data);
        }
        else if (option == 4)
        {
            printf("\nInorder Traversal : ");
            inorder(root);
        }
        else if (option == 5)
        {
            printf("\nCurrently not available.");
        }
        

        // printf("\nInorder Traversal : ");
        // inorder(root);
        // printf("\n");
    }
    return 0;
}

void inorder(struct node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

struct node *create_node(int data)
{
    struct node *new_node = NULL;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct node *insert(struct node *root, int data)
{
    if (root == NULL)
        return create_node(data);
    else if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

struct node* search(struct node* root, int key)
{
    if (root == NULL || root->data == key)
    {
        return root;
    }
    else if (root->data>key)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    } 
}