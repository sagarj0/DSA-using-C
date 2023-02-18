// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

struct node
{

    int data;
    struct node *next;
} *top = NULL;
void push(int x)
{

    struct node *p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL)
    {
        printf("stack overflow");
    }
    else
    {

        p->data = x;
        p->next = top;
        top = p;
    }
}
void display(struct node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
int pop(struct node *p)
{
    int x;

    if (top == NULL)
    {
        printf("stack underflow");
    }
    else
    {

        top = top->next;
        x = p->data;
        free(p);
    }

    return x;
}

int peek(struct node *p, int pos)
{

    int i;
    for (i = 0; p != NULL && i < pos - 1; i++)
    {
        p = p->next;
    }
    if (p != NULL)
    {
        return p->data;
    }
    else
    {
        return -1;
    }
}

void isEmpty()
{
    if (top == NULL)
    {
        printf("stack empty");
    }
}
void isFull()
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL)
    {
        printf("stack is full");
    }
}
int main()
{

    push(5);
    push(10);
    push(9);

    display(top);
    // printf("poped data =%d \n", pop(top));
    display(top);
    printf("\n peeked data=%d", peek(top, 10));
    // pop(top);
    // pop(top);
    // isEmpty();
    return 0;
}









