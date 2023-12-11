#include <stdio.h>
#include <stdlib.h>

struct node
{
	struct node* prev;
	int data;
	struct node* next;
};

struct node* create_list(struct node* head);
void traverse_list(struct node* head);
struct node* add_to_empty(struct node* head, int data);
struct node* insertion_at_begin(struct node* head, int data);
void insertion_at_end(struct node* head, int data);
struct node* insertion_at_given(struct node* head, int data, int position);

int main()
{
	int position, data;
	struct node* head = NULL;
	
	head = create_list(head);
	printf("\nList.\n");
	traverse_list(head);
	
	
	printf("Choose position to insert data : ");
	scanf("%d", &position);
	
	printf("Enter data : ");
	scanf("%d", &data);
	head = insertion_at_given(head, data, position);
	
	printf("\nList.\n");
	traverse_list(head);
	return 0;
}

void traverse_list(struct node* head)
{
	struct node* temp = head;
	
	while(temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}

struct node* create_list(struct node* head)
{
	int data, n;
	printf("Enter number of nodes in linked list : ");
	scanf("%d", &n);
	
	printf("Enter data for node 1 : ");
	scanf("%d", &data);
	if(head == NULL)
	{
		head = add_to_empty(head, data);
	}
	
	for(int i = 2; i<=n; i++)
	{
		printf("Enter data for node %d : ", i);
		scanf("%d", &data);
		
		insertion_at_end(head, data);
	}
	return head;
}

struct node* add_to_empty(struct node* head, int data)
{
	struct node* current = NULL;
	
	current = (struct node*)malloc(sizeof(struct node));
	current->prev = NULL;
	current->data = data;
	current->next = NULL;
	
	head = current;
	return head;
}

struct node* insertion_at_begin(struct node* head, int data)
{
	struct node* current = (struct node*)malloc(sizeof(struct node));
	
	current->prev = NULL;
	current->data = data;
	current->next = head;
	head->prev = current;
	head = current;
	return head;
}
void insertion_at_end(struct node* head, int data)
{
	struct node* current = (struct node*)malloc(sizeof(struct node));
	struct node* temp = NULL;
	
	temp = head;
	while(temp->next!=NULL)
	{
		temp = temp->next;
	}

	current->data = data;
	current->next = NULL;
	current->prev = temp;
	temp->next = current;
}

struct node* insertion_at_given(struct node* head, int data, int position)
{
	struct node* current = NULL, *temp = head;
	
	if(position == 1)
	{
		head = insertion_at_begin(head, data);
		return head;
	}
	current = (struct node*)malloc(sizeof(struct node));
	
	while(position > 2)
	{
		temp = temp->next;
		position--;
	}
	current->data = data;
	current->next = temp->next;
	temp->next = current;
	current->prev = temp;
	current->next->prev = temp->next;
	return head;
}