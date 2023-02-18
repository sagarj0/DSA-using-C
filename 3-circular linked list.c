#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *first = NULL;

void create()
{
    int n;
    struct node *head, *temp = malloc(sizeof(struct node));
    printf("Enter no of nodes: ");
    scanf("%d", &n);
    printf("Enter data of 1st:");
    scanf("%d", &temp->data);
    // first->data = temp->data;
    //  last = temp;
    //  last -> next =  first;
    first = temp;
    first->next = first;
    head = first;
    for (int i = 2; i <= n; i++)
    {
        struct node *new = malloc(sizeof(struct node));
        printf("\nEnter data of %d node: ", i);
        scanf("%d", &new->data);
        head->next = new;
        head = new;
        head->next = first;
    }
}

void display()
{
    struct node *head;
    printf("\nDisplaying data: ");
    head = first;
    do
    {
        printf("%d\t", head->data);
        head = head->next;
    } while (head != first);
}
int count()
{
    struct node *t;
    int count = 0;
    t = first;
    do
    {
        count++;
        t = t->next;
    } while (t != first);
    return count;
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
        head->next = temp;
    }
}

void delete()
{
    struct node *temp, *head;
    int pos;
    printf("\nEnter position to be deleted:");
    scanf("%d", &pos);
    if (pos < 1 || pos > count())
    {
        printf("Invalid position.");
    }

    else if (pos == 1)
    {
        temp = first;
        first = first->next;
        free(temp);
    }
    else
    {
        head = first;
        int i;
        for (i = 1; i < pos - 1; i++)
        {
            head = head->next;
        }
        // head->next=temp;
        temp = head->next;
        head->next = temp->next;
        free(temp);
    }
}

int main()
{
    create();
    display();
    // printf("\ncount of node is %d\n", count());
    // insert();
    // display();
    delete ();
    display();

    return 0;
}
