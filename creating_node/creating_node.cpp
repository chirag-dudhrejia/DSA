#include <iostream>

using namespace std;

struct node{
    int data;
    struct node *link;

};

int main()
{
    struct node *head = NULL;

    head = (struct node *)malloc(sizeof(struct node));

    head->data = 25;
    head->link = NULL;

    printf("%d", head->data);
}