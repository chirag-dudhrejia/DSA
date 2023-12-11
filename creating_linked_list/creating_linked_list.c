#include <stdio.h>
#include <stdlib.h>

void create_list(int);
void traverse_list();

struct node
{
    int data;
    struct node *next;
} *head;

int main()
{
    int n;

    printf("Enter Size of linked list : ");
    scanf("%d", &n);

    create_list(n);

    traverse_list();
}

void create_list(int n)
{
    struct node *current = NULL, *temp = NULL;
    int data, i;

    head = (struct node *)malloc(sizeof(struct node));

    if (head == NULL)
    {
        printf("Unable To Allocate Memory\n");
        exit(0);
    }

    printf("Enter Data of node 1 : ");
    scanf("%d", &data);

    head->data = data;
    head->next = NULL;

    temp = head;
    for (i = 2; i <= n; i++)
    {
        current = malloc(sizeof(struct node));

        if(current == NULL)
        {
            printf("Unable To Allocate Memory\n");
            exit(0);
        }

        printf("Enter Data of Node %d : ", i);
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
        printf("List is empty\n");
        return;
    }

    temp = head;

    printf("List : ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } 
    
}