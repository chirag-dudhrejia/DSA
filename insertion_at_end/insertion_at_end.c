#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*head;

void create_list(int);
void traverse_list();
void insert_end();
void insert_beginning();

int main()
{
    int n;
    char option;
    printf("Enter Number of Nodes : ");
    scanf("%d", &n);

    create_list(n);

    traverse_list();

    printf("\nchoose Task From Below:\n1 : Insertion at beginning\n2 : Insertion at end\n3 : Insertion in middle\n");
    scanf(" %c", &option);

    switch (option)
    {
    case '1':
        insert_end();
        break;
    
    case '2':
        insert_beginning();
        break;
    
    default:
        break;
    }

    traverse_list();
}

void create_list(int n)
{
    struct node *current = NULL, *temp = NULL;
    int data, i;

    head = (struct node *)malloc(sizeof(struct node));

    if (head == NULL)
    {
        printf("Memory not allocated\n");
        exit(0);
    }

    printf("Enter Data of node 1 : ");
    scanf("%d", &data);

    head->data = data;
    head->next = NULL;

    temp = head;
    for ( i = 2; i <= n; i++)
    {
        current = malloc(sizeof(struct node));

        if (current == NULL)
        {
            printf("Memory not allocated\n");
            exit(0);
        }

        printf("Enter Data of node %d : ", i);
        scanf("%d", &data);

        current->data = data;
        current->next = NULL;

        temp->next = current;
        temp = temp->next; 
    }
    
}

void traverse_list()
{
    struct node *temp = NULL;

    if (head == NULL)
    {
        printf("Memory not allocated\n");
        exit(0);
    }
    
    
    temp = head;
    printf("List : ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    
}

void insert_end()
{
    struct node *temp = NULL, *current = NULL;
    int data, i;

    current = malloc(sizeof(struct node));

    if (current == NULL)
    {
        printf("Memory not allocated\n");
        exit(0);
    }

    printf("Enter Data to insert : ");
    scanf("%d", &data);

    current->data = data;
    current->next = NULL;

    temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = current;
    
}

void insert_beginning()
{
    struct node *temp = NULL, *current = NULL;
    int data, i;

    current = malloc(sizeof(struct node));

    if (current == NULL)
    {
        printf("Memory not allocated\n");
        exit(0);
    }

    printf("Enter Data to insert : ");
    scanf("%d", &data);

    current->data = data;
    current->next = head;
    head = current;
}