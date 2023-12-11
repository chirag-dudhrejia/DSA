#include <stdio.h>

void push(int stack_arr[], int size, int *top, int data);
void pop(int stack_arr[], int *top);
void show(int stack_arr[], int top);
int isfull(int size, int *top);
int isempty(int *top);

int main()
{
    int size;
    printf("Enter size of stack as '5' : ");
    scanf("%d", &size);
    int stack_arr[100];
    int top = -1;

    push(stack_arr, size, &top, 10);
    push(stack_arr, size, &top, 20);
    push(stack_arr, size, &top, 30);
    push(stack_arr, size, &top, 40);
    push(stack_arr, size, &top, 50);
    show(stack_arr, top);
    pop(stack_arr, &top);
    pop(stack_arr, &top);
    pop(stack_arr, &top);
    pop(stack_arr, &top);
    pop(stack_arr, &top);
    show(stack_arr, top);

    return 0;
}

int isfull(int size, int *top)
{
    if (*top == size-1)
    {
        return 1;
    }
    return 0;
}

int isempty(int *top)
{
    if (*top == -1)
    {
        return 1;
    }
    return 0;
}

void push(int stack_arr[], int size, int *top, int data)
{
    if (isfull(size, top))
    {
        printf("Overflow\n");
        return;;
    }

    ++*top;
    stack_arr[*top] = data;
}

void pop(int stack_arr[], int *top)
{
    if (isempty(top))
    {
        printf("Underflow\n");
    }
    
    printf("Element poped from stack is : %d\n",stack_arr[*top]);
    --*top;
}

void show(int stack_arr[], int top)
{
    int i;
    if (isempty(&top))
    {
        printf("\nStack is empty\n\n");
        return;
    }
    
    printf("\nElements of stack are.\n");
    for (i = top; i >= 0; i--)
    {
        printf("%d\t", stack_arr[i]);
    }
    printf("\n\n");
}