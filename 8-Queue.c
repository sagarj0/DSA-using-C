#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int data;
    struct queue *next;
} *front = 0, *rear = 0;

void enqueue(int x)
{

    struct queue *q = malloc(sizeof(struct queue));
    q->data = x;
    q->next = 0;
    if (front == 0)
    {

        front = q;
        rear = q;
    }
    else
    {
        rear->next = q;
        rear = q;
    }
}

void display(struct queue *temp)
{
    while (temp != 0)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}

int dequeue()
{
    if (front == 0)
    {
        printf("nothing to dequeue.");
    }
    else
    {
        struct queue *t = front;
        int x;
        front = front->next;
        x = t->data;
        free(t);
        return x;
    }
}

int main()
{
    // front = (struct queue *)malloc(sizeof(struct queue));
    enqueue(5);
    enqueue(7);
    enqueue(9);
    enqueue(8);
    display(front);

    printf("\n dequed element is : %d\n", dequeue());

    display(front);
    return 0;
}