#include <stdio.h>

#define MAX 5
int stack_arr[MAX];
int top = -1;

void push(int);
void pop();
int isfull();
int isempty();
void show();

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    show();
    pop();
    pop();
    pop();
    pop();
    pop();
    show();

    return 0;
}

int isfull()
{
    if (top == MAX-1)
    {
        return 1;
    }
    return 0;
}

int isempty()
{
    if (top == -1)
    {
        return 1;
    }
    return 0;
}

void push(int data)
{
    if (isfull())
    {
        printf("Overflow\n");
        return;
    }

    top++;
    stack_arr[top] = data;
}

void pop()
{
    if (isempty())
    {
        printf("Underflow\n");
        return;
    }
    
    printf("Poped element from stack is : %d\n", stack_arr[top]);
    top--;
}

void show()
{
    int i;

    if (isempty())
    {
        printf("\nStack is empty\n\n");
        return;
    }
    
    printf("Elements of stack are.\n");
    for ( i = top; i >= 0; i--)
    {
        printf("%d\t", stack_arr[i]);
    }
    printf("\n\n");
}