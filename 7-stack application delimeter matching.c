
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
struct node
{

    char data;
    struct node *next;
} *top = NULL;

void push(char x)
{

    struct node *p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL)
    {
        printf("stack overflow");
    }

    p->data = x;
    p->next = top;
    top = p;
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
char pop(struct node *p)
{
    char x;

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

bool isbalance(char *c)
{
    int i;
    for (i = 0; c[i] != '\0'; i++)
    {
        if (c[i] == '(' || c[i] == '{' || c[i] == '[')
        {
            push(c[i]);
        }
        else if (c[i] == ')' || c[i] == '}' || c[i] == ']')
        {
            if (top == 0)
            {
                return 0;
            }
            else
            {
                if (((int)top->data == 40 && (int)c[i] == 41) || ((int)top->data == 91 && (int)c[i] == 93) || ((int)top->data == 123 && (int)c[i] == 125))
                {
                    pop(top);
                }
                else
                {
                    return 0;
                }
            }
        }
    }
    if (top == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char *exp = "{[(a+b)]*(a-b)}";

    // display(top);
    //  printf("poped data =%d \n", pop(top));
    // display(top);
    // printf("\n peeked data=%d", peek(top, 10));
    //  pop(top);
    //  pop(top);
    //  isEmpty();
    printf("is balnce : %s", isbalance(exp) ? "false" : "true");

    return 0;
}