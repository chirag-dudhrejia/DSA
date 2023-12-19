#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct Stack
{
    int size;
    float *arr;
    int top;
}Stack;

void initialize(Stack *s, size_t size);
void push(Stack *s, float value);
float pop(Stack *s);
int is_full(Stack s);
int is_empty(Stack s);
float operation(Stack *s);

int main()
{
    Stack s;
    initialize(&s, 10);

    float result = operation(&s);
    printf("%.2f", result);
}

void initialize(Stack *s, size_t si)
{
    s->arr = (float *)malloc(sizeof(float)*si);
    s->top = -1;
    s->size = si;
}

int is_full(Stack s)
{
   return s.top==s.size?1:0;
}
int is_empty(Stack s)
{
   return s.top==-1?1:0;
}

void push(Stack *s, float value)
{
    if (is_full(*s))
    {
        return;
    }
    s->arr[++s->top] = value;
}

float pop(Stack *s)
{
    if (is_empty(*s))
    {
        return 0;
    }
    float temp = s->arr[s->top--];
    return temp;
}

float operation(Stack *s)
{
    float a, b, result;
    char exp = '0';
    while (exp != ')')
    {
        printf("Enter Expression : ");
        scanf(" %c", &exp);

        if (exp>='0' && exp<='9')
        {
            int num = exp - '0';
            push(&*s, num);
        }
        else if (exp == '+' || exp == '-' || exp == '*' || exp == '/')
        {
            b = pop(&*s);
            a = pop(&*s);
            switch (exp)
            { 
            case '+':result = a+b; break;
            case '-':result = a-b; break;
            case '*':result = a*b; break;
            case '/':result = a/b; break;
            }
            push(&*s, result);
        } 
    }
    return pop(&*s);
}