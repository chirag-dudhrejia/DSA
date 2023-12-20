#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct Stack
{
    float *arr;
    size_t size;
    int top;
} Stack;

void initialization(Stack *s, size_t si);
void push(Stack *s, float value);
float top(Stack s);
float pop(Stack *s);
int is_empty(Stack s);
void convert(Stack *infix, char expression[], char postfix[]);
int precedence(char ch);
float operation(Stack *s, char postfix[]);

int main()
{
    char expression[20];
    char str_postfix[20];

    printf("Enter expression.\n");
    scanf(" %[^\n]", &expression);

    Stack infix;

    initialization(&infix, 10);
    convert(&infix, expression, str_postfix);

    printf("%s", str_postfix);

    Stack postfix;
    initialization(&postfix, 20);
    float result = operation(&postfix, str_postfix);

    printf("\n%.1f\n", result);
    return 0;
}

void initialization(Stack *s, size_t si)
{
    s->arr = (float *)malloc(sizeof(float) * si);
    s->top = -1;
    s->size = si;
}
int is_empty(Stack s)
{
    return s.top == -1 ? 1 : 0;
}
int is_full(Stack s)
{
    return s.top == s.size ? 1 : 0;
}
void push(Stack *s, float value)
{
    s->arr[++s->top] = value;
}
float pop(Stack *s)
{
    float temp = s->arr[s->top--];
    return temp;
}
float top(Stack s)
{
    return s.arr[s.top];
}

int precedence(char ch)
{
    if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else if (ch == '^')
    {
        return 3;
    }
    return -1;
}

void convert(Stack *infix, char expression[], char postfix[])
{
    int i = 0;
    int pos = -1;

    int len = strlen(expression);
    expression[len+1] = '\0';
    // printf("%d", len);

    while (expression[i] != '\0')
    {
        if (expression[i] >= '0' && expression[i] <= '9')
        {
            postfix[++pos] = expression[i];
        }
        else if (is_empty(*infix) || top(*infix) == '(' || expression[i] == '(')
        {
            push(&*infix, expression[i]);
        }
        else if (expression[i] == ')')
        {
            char ch = '0';
            while (top(*infix) != '(')
            {
                postfix[++pos] = pop(&*infix);
            }
            pop(&*infix);
        }
        else
        {
            while (!is_empty(*infix) && precedence(expression[i]) <= precedence(top(*infix)))
            {
                postfix[++pos] = pop(&*infix);
            }
            push(&*infix, expression[i]);
        }
        i++;
    }
    while (!is_empty(*infix))
    {
        postfix[++pos] = pop(&*infix);
    }
    postfix[++pos] = '\0';
}

float operation(Stack *s, char postfix[])
{
    float a, b, result;
    int i = 0;
    postfix[strlen(postfix)+1] = ')';
    while (postfix[i] != ')')
    {
        if (postfix[i]>='0' && postfix[i]<='9')
        {
            int num = postfix[i] - '0';
            push(&*s, num);
        }
        else if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/')
        {
            b = pop(&*s);
            a = pop(&*s);
            switch (postfix[i])
            { 
            case '+':result = a+b; break;
            case '-':result = a-b; break;
            case '*':result = a*b; break;
            case '/':result = a/b; break;
            }
            push(&*s, result);
        } 
        i++;
    }
    return pop(&*s);
}