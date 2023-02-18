#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
} *first = NULL;

void create()
{
    int n;
    struct node *head;
    first = malloc(sizeof(struct node));
    printf("Enter no of nodes:");
    scanf("%d", &n);
    printf("Enter data of 1st node:");
    scanf("%d", &(first->data));
    first->prev = NULL;
    first->next = NULL;
    head = first;
    for (int i = 2; i <= n; i++)
    {
        struct node *new = malloc(sizeof(struct node));
        printf("Enter data of %d node", i);
        scanf("%d", &new->data);
        new->prev = head;
        new->next = NULL;
        head->next = new;
        head = new;
    }
}

void display()
{
    struct node *temp = first;
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    /*while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->prev;
    }*/
}

int count()
{
    struct node *temp = first;
    int c = 0;
    while (temp != NULL)
    {
        c++;
        temp = temp->next;
    }
    return c;
}

void insert()
{
    int pos;
    struct node *head = first, *temp = malloc(sizeof(struct node));
    printf("\nEnter the data to be inserted: ");
    scanf("%d", &temp->data);
    printf("Enter position: ");
    scanf("%d", &pos);
    if (pos < 1 || pos > count() + 1)
    {
        printf("Invalid position.");
    }

    else if (pos == 1)
    {
        temp->next = first;
        temp->prev = NULL;
        first->prev = temp;
        first = temp;
    }
    else
    {
        int i;
        for (i = 1; i < pos - 1; i++)
        {
            head = head->next;
        }
        // head->next=temp;
        temp->next = head->next;
        temp->prev = head;
        // temp->prev->next=temp;
        if (head->next != NULL)
        {
            temp->next->prev = temp;
        }
        head->next = temp;
    }
}

void delete()
{
    int pos;
    struct node *head = first, *temp;
    printf("\nEnter position to be deleted: ");
    scanf("%d", &pos);
    if (pos < 1 || pos > count())
    {
        printf("Invalid position.");
    }

    else if (pos == 1)
    {
        temp = first;
        first = first->next;
        first->prev = NULL;
        free(temp);
    }
    else
    {
        int i;
        for (i = 1; i < pos - 1; i++)
        {
            head = head->next;
        }
        // head->next=temp;
        temp = head->next;
        // temp->prev =head;
        // temp->prev->next=temp;
        head->next = temp->next;
        if (temp->next != NULL)
        {
            temp->next->prev = head;
        }
        free(temp);
        // head->next = temp;
    }
}

int main()
{
    create();
    display();
    // printf("Count is %d", count());
    insert();
    //delete ();
    display();
}