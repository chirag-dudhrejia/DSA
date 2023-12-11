#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node* prev;
    int data;
    struct node* next;
};

void traverse_list(struct node* head);
struct node* create_list(struct node* head);
struct node* add_to_empty(struct node* head, int data);
void insert_at_end(struct node* head, int data);
struct node* insert_at_begin(struct node* head, int data);
struct node* insert_at_position(struct node* head, int data, int position);

int main()
{
    struct node* head = NULL;
    int data, position;

    head = create_list(head);

    printf("Data to Insert at begin : ");
    scanf("%d", &data);
    head = insert_at_begin(head, data);

    printf("Enter position to enter data : ");
    scanf("%d", &position);
    printf("Data to Insert at position %d : ", position);
    scanf("%d", &data);
    head = insert_at_position(head, data, position);
    printf("List : ");
    traverse_list(head);
    return 0;
}

void traverse_list(struct node* head)
{
    struct node* temp = NULL;
    temp = head;

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct node* create_list(struct node* head)
{
    int n, data;
    printf("Enter number of nodes to create : ");
    scanf("%d", &n);

    printf("Enter data for node 1 : ");
    scanf("%d", &data);

    head = add_to_empty(head, data);

    for (int i = 1; i < n; i++)
    {
        printf("Enter data for node %d : ", i+1);
        scanf("%d", &data);
        insert_at_end(head, data);
    }
    return head;
}

struct node* add_to_empty(struct node* head, int data)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;

    head = temp;
    return head;
}

void insert_at_end(struct node* head, int data)
{
    struct node* current = NULL, *temp = NULL;

    current = (struct node*)malloc(sizeof(struct node));
    if (current == NULL)
    {
        printf("Memory not allocated.\n");
        return ;
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

struct node* insert_at_begin(struct node* head, int data)
{
    struct node* current = NULL;
    if (head==NULL)
    {
        printf("List is empty.\n");
        return head;
    }
    current = (struct node*)malloc(sizeof(struct node));
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

struct node* insert_at_position(struct node* head, int data, int position)
{
    if (position == 1)
    {
        head = insert_at_begin(head, data);
    }
    else
    {
        struct node* current = add_to_empty(head, data);
        struct node* temp = head;
        struct node* temp2 = NULL;

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