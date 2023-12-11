#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head;

void create_list(int);
void display_list();

int main()
{
    int n;

    printf("ENter Number of nodes to be created : ");
    scanf("%d", &n);

    create_list(n);
    display_list();

}

void create_list(int n)
{
    struct node *current = NULL, *temp = NULL;
    int data, i;

    head = (struct node *)malloc(sizeof(struct node));

    if (head == NULL)
    {
        printf("Memory not allocated\n");
        
    }

    printf("Enter data for node 1 : ");
    scanf("%d", &data);

    head->data = data;
    head->next = NULL;

    temp = head;

    for (i = 2; i <= n; i++)
    {
        current = malloc(sizeof(struct node));

        if (current == NULL)
        {
            printf("Memory not allocated\n");
            
        }

        printf("Enter data for node %d : ", i);
        scanf("%d", &data);

        current->data = data;
        current->next = NULL;

        temp->next = current;
        temp = temp->next; 
    }
}

void display_list()
{
    struct node *temp = NULL;
    int i;

    if(head == NULL)
    {
        printf("List is Empty\n");
        
    }

    temp = head;

    printf("\nList : ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}