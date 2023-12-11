#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void create_list(int size);
void traverse_list();
void insert_begin();
void deletion_begin();
void insert_end();
void deletion_end();
void insert_after();
void insert_at();
void deletion_at();
void rev_list();
void delete_list();

struct node
{
    int data;
    struct node *next;
} *head;

int main()
{
    char option;
    int n;
    printf("Enter number of nodes to be created : ");
    scanf("%d", &n);

    create_list(n);
    traverse_list();

    while (option != '0')
    {

        printf("\nChoose task to perform.\n1. Inrsetion\n2. Deletion\n3. Reverse List\n4. Traverse List\n0. Exit.\n");
        scanf(" %c", &option);

        switch (option)
        {
        case '0':
            break;
        case '4':
            printf("\nTraversing List :\n");
            traverse_list();
            continue;
            break;
        case '1':
            printf("\nchoose insertion task to perform.\n1. Insertion at beginning\n2. Insertion at end\n3. Insertion after a given position\n4. Insertion at given position\n0. Exit.\n");
            scanf(" %c", &option);

            switch (option)
            {
            case '0':
                break;
            case '1':
                insert_begin();
                printf("\nInsertion at Beginning successfull.\n");
                printf("Press Enter.");
                getch();
                break;
            case '2':
                insert_end();
                printf("\nInsertion at End successfull.\n");
                printf("Press Enter.");
                getch();
                break;
            case '3':
                insert_after();
                printf("Press Enter.");
                getch();
                break;
            case '4':
                insert_at();
                printf("Press Enter.");
                getch();
                break;
            default:
                printf("\nInvalid Input.\n");
                printf("Press Enter.");
                getch();
                break;
            }
            break;
        case '2':
            printf("\nchoose Deletion task to perform.\n1. Deletion at beginning\n2. Deletion at end\n3. Deletion after a given position\n4. Delete at from given position\n5. Delete Whole List\n0. Exit.\n");
            scanf(" %c", &option);

            switch (option)
            {
            case '0':
                break;
            case '1':
                deletion_begin();
                printf("\nDeletion at Beginning successfull.\n");
                printf("Press Enter.");
                getch();
                break;
            case '2':
                deletion_end();
                printf("\nDeletion at End successfull.\n");
                printf("Press Enter.");
                getch();
                break;
            case '3':
                printf("\nDeletion after given position.\n");
                printf("\nCurrently Not available.\n");
                printf("Press Enter.");
                getch();
                break;
            case '4':
                printf("\nDeletion at given position.\n");
                deletion_at();
                printf("Press Enter.");
                getch();
                break;
            case '5':
                delete_list();
                printf("\nDeleted Whole List Successfull.\n");
                printf("Press Enter.");
                getch();
                break;
            default:
                printf("\nInvalid Input.\n");
                printf("Press Enter.");
                getch();
                break;
            }
            break;
        case '3':
            rev_list();
            printf("\nReversed Successfully.\n");
            printf("Press Enter.");
            getch();
            break;
        default:
            printf("\nInvalid Input.\n");
            printf("Press Enter.");
            getch();
            break;
        }
        system("cls");
    }
    return 0;
}

void create_list(int size)
{
    struct node *current, *temp;
    int data;

    head = (struct node *)malloc(sizeof(struct node));

    if (head == NULL)
    {
        printf("Memory Not Allocated.");
        return;
    }

    printf("Enter Data for node : 1\n");
    scanf("%d", &data);

    head->data = data;
    head->next = NULL;

    temp = head;
    for (int i = 2; i <= size; i++)
    {
        current = (struct node *)malloc(sizeof(struct node));

        if (current == NULL)
        {
            printf("Memory not allocated.");
            return;
        }

        printf("Enter Data for node : %d\n", i);
        scanf("%d", &data);

        current->data = data;
        current->next = NULL;

        temp->next = current;
        temp = temp->next;
    }
}

void traverse_list()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("list is Empty.\n");
        return;
    }

    temp = head;
    printf("List : ");
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insert_begin()
{
    struct node *temp;
    int data;

    temp = (struct node *)malloc(sizeof(struct node));

    if (temp == NULL)
    {
        printf("Memory not allocated.\n");
        return;
    }

    printf("Enter data : ");
    scanf("%d", &data);

    temp->data = data;
    temp->next = head;
    head = temp;
}

void deletion_begin()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;
    head = head->next;
    free(temp);
    temp = NULL;
    printf("Node Deleted from beginning.\n");
}

void insert_end()
{
    struct node *current, *temp;
    int data;

    current = (struct node *)malloc(sizeof(struct node));

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    if (current == NULL)
    {
        printf("Memory not allocated\n");
        return;
    }

    printf("Enter Data : ");
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

void deletion_end()
{
    struct node *temp, *temp1;

    if (head == NULL)
    {
        printf("List Is empty.\n");
        return;
    }
    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
        printf("Only Node of the list deleted.\n");
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp1 = temp;
            temp = temp->next;
        }
        temp1->next = NULL;
        free(temp);
        temp = NULL;
    }
}

void insert_after()
{
    struct node *current, *temp;
    int data, i, pos;

    if (head == NULL)
    {
        printf("list is empty.");
        return;
    }

    current = (struct node *)malloc(sizeof(struct node));
    if (current == NULL)
    {
        printf("Memory not allocated.\n");
        return;
    }

    printf("Enter Data : ");
    scanf("%d", &data);

    printf("Enter Position after which node is to be inserted : ");
    scanf("%d", &pos);

    current->data = data;

    temp = head;
    for (i = 2; i <= pos; i++)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            printf("Can not insert at this point.");
            return;
        }
    }

    current->next = temp->next;
    temp->next = current;
    printf("\nInsertion after given position successfull.\n");
}

void insert_at()
{
    struct node *current = NULL, *temp = NULL;
    int pos, data;

    current = (struct node*)malloc(sizeof(struct node*));

    if (current == NULL)
    {
        printf("Memory not allocated.");
        return;
    }

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("Enter Data : ");
    scanf("%d", &data);

    printf("Enter position : ");
    scanf("%d", &pos);

    current->data = data;
    current->next = NULL;

    temp = head;
    for (int i = 2; i <= pos-1; i++)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            printf("\nCannot insert at this position,\n");
            printf("Position does not exist.\n");
            return;
        }
    }
    
    current->next = temp->next;
    temp->next = current;
    printf("\nInsertion at given position successfull.\n");
}

void deletion_at()
{
    int pos, i;
    struct node *temp = NULL, *prev = NULL;

    if (head == NULL)
    {
        printf("List is empty.");
        return;
    }

    printf("Enter Position to delete element : ");
    scanf("%d", &pos);
    temp = head;
    for ( i = 2; i <= pos; i++)
    {
        prev = temp;
        temp = temp->next;
        if (temp == NULL)
        {
            printf("Can not delete from this position,\n");
            printf("Position does not exist.\n");
            return;
        }
    }
    prev->next = temp->next;
    free(temp);
    temp = NULL;
    printf("\nDeletion at given position successfull.\n");
}

void rev_list()
{
    struct node *prev = NULL, *foregoing = NULL;

    if (head == NULL)
    {
        printf("List is Empty.\n");
        return;
    }

    while (head != NULL)
    {
        foregoing = head->next;
        head->next = prev;
        prev = head;
        head = foregoing;
    }
    head = prev;
}

void delete_list()
{
    struct node *temp = head;

    if (head == NULL)
    {
        printf("List is empty.");
        return;
    }

    while (head != NULL)
    {
        head = head->next;
        free(temp);
        temp = head;
    }
    printf("Whole list is deleted.");
}