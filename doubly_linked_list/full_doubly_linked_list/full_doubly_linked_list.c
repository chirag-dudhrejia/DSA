#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

void traverse_list(struct node *head);
struct node *create_list(struct node *head);
struct node *add_to_empty(struct node *head, int data);
void insert_at_end(struct node *head, int data);
struct node *insert_at_begin(struct node *head, int data);
struct node *insert_at_position(struct node *head, int data, int position);
struct node *deletion_at_begin(struct node *head);
struct node *deletion_at_end(struct node *head);
struct node *deletion_at_position(struct node *head, int position);

int main()
{
    struct node *head = NULL;
    int data, position;
    char option = '9';

    while (option != '0')
    {
        printf("\nChoose Task to perform.\n1. Create List.\n2. Insertion.\n3. Deletion.\n4. Traverse List/Show List\n0. Exit.\n");
        scanf(" %c", &option);

        if (option == '1')
        {
            head = create_list(head);
        }
        else if (option == '2')
        {
            while (option != '7' && option != '0')
            {

                printf("\nChoose insertion task.\n1. Insertion at Begining.\n2. Insertion at given position.\n3. Insertion at end.\n7. Back to main menu.\n0. Exit.\n");
                scanf(" %c", &option);

                if (option == '1')
                {
                    printf("Enter data to insert at beginning : ");
                    scanf("%d", &data);
                    head = insert_at_begin(head, data);
                }
                else if (option == '2')
                {
                    printf("Enter position at which you want to insert data : ");
                    scanf("%d", &position);
                    printf("Enter data to insert at position %d : ", position);
                    scanf("%d", &data);
                    head = insert_at_position(head, data, position);
                }
                else if (option == '3')
                {
                    printf("Enter data to insert at end : ");
                    scanf("%d", &data);
                    insert_at_end(head, data);
                }
            }
        }
        else if (option == '3')
        {
            while (option != '7' && option != '0')
            {

                printf("\nChoose deletion task.\n1. Deletion at Begining.\n2. Deletion at given position.\n3. Deletion at end.\n7. Back to main menu.\n0. Exit.\n");
                scanf(" %c", &option);

                if (option == '1')
                {
                    head = deletion_at_begin(head);
                }
                else if (option == '2')
                {
                    printf("Enter position you want to delete data : ");
                    scanf("%d", &position);
                    head = deletion_at_position(head, position);
                }
                else if (option == '3')
                {
                    deletion_at_end(head);
                }
            }
        }
        else if (option == '4')
        {
            printf("\nList.\n");
            traverse_list(head);
        }   
    }

    return 0;
}

void traverse_list(struct node *head)
{
    struct node *temp = NULL;
    temp = head;

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct node *create_list(struct node *head)
{
    int n, data;
    printf("Enter number of nodes to create : ");
    scanf("%d", &n);

    printf("Enter data for node 1 : ");
    scanf("%d", &data);

    head = add_to_empty(head, data);

    for (int i = 1; i < n; i++)
    {
        printf("Enter data for node %d : ", i + 1);
        scanf("%d", &data);
        insert_at_end(head, data);
    }
    return head;
}

struct node *add_to_empty(struct node *head, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;

    head = temp;
    return head;
}

void insert_at_end(struct node *head, int data)
{
    struct node *current = NULL, *temp = NULL;

    current = (struct node *)malloc(sizeof(struct node));
    if (current == NULL)
    {
        printf("Memory not allocated.\n");
        return;
    }
    current->prev = NULL;
    current->data = data;
    current->next = NULL;
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = current;
    current->prev = temp;
}

struct node *insert_at_begin(struct node *head, int data)
{
    struct node *current = NULL;
    if (head == NULL)
    {
        printf("List is empty.\n");
        return head;
    }
    current = (struct node *)malloc(sizeof(struct node));
    if (current == NULL)
    {
        printf("Memory not allocated.\n");
        return head;
    }
    current->prev = NULL;
    current->data = data;
    current->next = head;
    head->prev = current;
    head = current;
    return head;
}

struct node *insert_at_position(struct node *head, int data, int position)
{
    if (position == 1)
    {
        head = insert_at_begin(head, data);
    }
    else
    {
        struct node *current = add_to_empty(head, data);
        struct node *temp = head;
        struct node *temp2 = NULL;

        while (position > 2)
        {
            temp = temp->next;
            position--;
        }
        temp2 = temp->next;
        temp2->prev = current;
        current->prev = temp;
        current->next = temp2;
        temp->next = current;
    }
    return head;
}

struct node *deletion_at_begin(struct node *head)
{
    if (head == NULL)
    {
        printf("Underflow.\n");
        return head;
    }

    head = head->next;
    free(head->prev);
    head->prev = NULL;
    return head;
}

struct node *deletion_at_end(struct node *head)
{
    if (head == NULL)
    {
        printf("Underflow.\n");
        return head;
    }
    else if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return head;
    }

    struct node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

struct node *deletion_at_position(struct node *head, int position)
{
    struct node *temp = head, *temp2 = NULL;
    if (position == 1)
    {
        head = deletion_at_begin(head);
    }
    else
    {
        while (position > 1)
        {
            temp = temp->next;
        }
        temp2 = temp->prev;
        temp2->next = temp->next;
        temp->next->prev = temp2;
        free(temp);
        temp = NULL;
    }
    return head;
}