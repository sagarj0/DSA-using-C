#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *first = 0;

void create(int a[], int n)
{
    struct node *last, *t;
    int *p;
    p = a;
    first = (struct node *)malloc(sizeof(struct node));
    first->data = *p;
    first->next = 0;
    last = first;
    p++;
    while (p != &a[n])
    {
        t = (struct node *)malloc(sizeof(struct node));
        // struct node *t, s;
        // t = &s;
        t->data = *p;
        t->next = 0;
        last->next = t;
        last = t;
        p++;
    }
};

void display(struct node *head)
{
    while (head != 0)
    {
        printf("%d\t", head->data);
        head = head->next;
    }
};

void Rdisplay(struct node *head)
{
    if (head != 0)
    {
        printf("%d\t", head->data);
        Rdisplay(head->next);
    }
};

int count(struct node *head)
{

    int c = 0;
    while (head != 0)
    {
        c++;
        head = head->next;
    }
    return c;
};

int Rcount(struct node *head)
{
    if (head = 0)
    {
        return 0;
    }
    else
    {
        return Rcount(head->next) + 1;
    }
};

int sum(struct node *head)
{
    int c = 0;
    while (head != 0)
    {
        c += head->data;
        head = head->next;
    }
    return c;
};

int Rsum(struct node *head)
{
    if (head = 0)
    {
        return 0;
    }
    else
    {
        return Rsum(head->next) + head->data;
    }
};

void search(struct node *head, int ele)
{
    int c = 0;
    do
    {
        if (head->data == ele)
        {
            printf("search successful");
            break;
        }
        head = head->next;
        c++;
    } while (c != count(first));

    if (c == count(first))
    {
        printf("search unsuccessful");
    }
};

void insert(struct node *head, int ele, int position)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    if (position < 0 || position > count(first))
    {
        printf("Invalid position");
    }
    else
        while (position != 0)
        {
            p = head;
            head = head->next;
            position--;
        }
    struct node *new;
    new->data = ele;
    p->next = new;
    new->next = head;
};

int delete(struct node *head, int pos)
{
    struct node *temp = malloc (sizeof(struct node));
    int data;
    while(pos != 0)
    {
        temp = head;
        head = head -> next;
        pos--;
    }
    data = temp -> data;
    //free(temp);
    return data;
};

int main()
{
    int A[100], n, *p;
    printf("Enter the number of nodes you want to create:");
    scanf("%d", &n);
    p = A;
    printf("\nEnter the elements : ");
    while (p != &A[n])
    {
        scanf("%d", p);
        p++;
    }
    create(A, n);
    printf("Displaying data of nodes: \n");
    display(first);
    // Rdisplay(first);
    //printf("\nCount of  nodes : %d", count(first));
    // printf("\nCount of nodes from recurssion: %d", Rcount(first));
    //printf("\nSum of nodes : %d", sum(first));
    // printf("\nSum from recursion : %d", Rsum(first));
    // printf("\nsearching of given element...\n");
    // search(first, 5);
    //printf("\ninserting...\n");
    //insert(first, 3, 0);
    //display(first);
    //printf("\n deleted element is %d", delete(first, 1));
    //display(first);
    return 0;
}
