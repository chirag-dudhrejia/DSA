#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

void traverse_list(struct node *head);
struct node *add_to_empty(struct node *head, int data);
struct node *insert_at_begin(struct node *head, int data);
struct node *insert_at_end(struct node *head, int data);
struct node *insert_at_position(struct node *head, int data, int pos);
struct node *delete_begining(struct node* head);
struct node* delete_end(struct node* head);
struct node* delete_given_position(struct node* head, int pos);

int main()
{
    struct node *head = NULL;
    int data, pos;
    int option = 9;

    while (option != 0)
    {
        printf("Choose task to perform.\n1. Insertion\n2. Deletion\n4. Traverse List\n0. Exit\n");
        scanf("%d", &option);

        if (option == 1)
        {
            while (option != 7 && option != 0)
            {
                printf("Choose Insertion task to perform.\n1. insertion at begining\n2. insertion at given position\n3. Insertion at end\n7. back to main menu\n0. Exit\n");
                scanf("%d", &option);

                if (option == 1)
                {
                    printf("Enter data to insert : ");
                    scanf("%d", &data);
                    head = insert_at_begin(head, data);
                    printf("\n");
                }
                else if (option == 2)
                {
                    printf("Enter data to insert : ");
                    scanf("%d", &data);
                    printf("Enter Position to enter data : ");
                    scanf("%d", &pos);
                    head = insert_at_position(head, data, pos);
                    printf("\n");
                }
                else if (option == 3)
                {
                    printf("Enter data to insert : ");
                    scanf("%d", &data);
                    head = insert_at_end(head, data);
                    printf("\n");
                }
            }
        }
        else if (option == 2)
        {
            while (option != 7 && option != 0)
            {
                printf("Choose Deletion task to perform.\n1. Deletion at begining\n2. Deletion at given position\n3. Deletion at end\n7. back to main menu\n0. Exit\n");
                scanf("%d", &option);

                if (option == 1)
                {
                    head = delete_begining(head);
                    printf("\n");
                }
                else if (option == 2)
                {
                    printf("Enter Position to delete data : ");
                    scanf("%d", &pos);
                    head = delete_given_position(head, pos);
                    printf("\n");
                }
                else if (option == 3)
                {
                    head = delete_end(head);
                    printf("\n");
                }
            }
        }
        else if (option == 4)
        {
            printf("List : ");
            traverse_list(head);
            printf("\n");
        }
    }

    printf("List : ");
    traverse_list(head);
    return 0;
}

void traverse_list(struct node *head)
{
    struct node *temp = head;

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
struct node *add_to_empty(struct node *head, int data)
{
    struct node *current = (struct node *)malloc(sizeof(struct node));
    if (current == NULL)
    {
        printf("Memory not allocated.\n");
        return head;
    }
    current->prev = NULL;
    current->data = data;
    current->next = NULL;
    head = current;
    return head;
}
struct node *insert_at_begin(struct node *head, int data)
{
    if (head == NULL)
    {
        head = add_to_empty(head, data);
        return head;
    }

    struct node *current = NULL;
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
struct node *insert_at_end(struct node *head, int data)
{
    struct node *current = NULL, *temp = head;
    current = (struct node *)malloc(sizeof(struct node));
    if (current == NULL)
    {
        printf("Memory not allocated.\n");
        return head;
    }
    if (head == NULL)
    {
        head = add_to_empty(head, data);
        return head;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        current->prev = head;
        current->data = data;
        current->next = NULL;
        temp->next = current;
        return head;
    }
}
struct node *insert_at_position(struct node *head, int data, int pos)
{
    struct node *current = NULL, *temp = head;
    current = (struct node *)malloc(sizeof(struct node));
    if (current == NULL)
    {
        printf("Memory not allocated.\n");
        return head;
    }
    if (pos == 1)
    {
        head = insert_at_begin(head, data);
    }
    else
    {
        while (pos>2)
        {
            temp = temp->next;
            pos--;
        }
        current->data = data;
        current->prev = temp;
        current->next = temp->next;
        current->next->prev = current;
        temp->next = current;
    }
    return head;
}

struct node *delete_begining(struct node* head)
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
    else
    {
        head = head->next;
        free(head->prev);
        head->prev = NULL;
        return head;
    }
}

struct node* delete_end(struct node* head)
{
    struct node* temp = NULL;
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
    else
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
        return head;
    } 
}

struct node* delete_given_position(struct node* head, int pos)
{
    struct node* temp = head, *temp2 = NULL;
    if (head == NULL)
    {
        printf("Underflow.\n");
        return head;
    }
    else if (pos == 1)
    {
        head = delete_begining(head);
        return head;
    }
    else
    {
        while (pos>1)
        {
            temp = temp->next;
            pos--;
        }
        temp2 = temp->prev;
        temp2->next = temp->next;
        temp2 = temp2->next;
        temp2->prev = temp->prev;
        free(temp);
        temp = NULL;
        return head;
    } 
}