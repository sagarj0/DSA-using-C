#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *s;
};

void create(struct stack *stk)
{
    stk->top = -1;
    printf("Enter size:");
    scanf("%d", &stk->size);
    stk->s = (int *)malloc(stk->size * sizeof(int));

}

void push(struct stack *stk)
{
    int temp;
    printf("Enter element of stack");

    stk->top++;
    scanf("%d", &temp);
    stk->s[stk->top] = temp;
}

void display(struct stack *stk)
{
    int temp = stk->top;

    printf("\nDisplaying data\n");
    while (stk->top != -1)
    {
        printf("%d\t", stk->s[stk->top]);
        stk->top--;
    }
    stk->top = temp;
}

int pop(struct stack *stk)
{
    return stk->s[stk->top];
}

int peak(struct stack *stk, int pos)
{
    return( stk -> s[stk->top - pos + 1]);
}

int main()
{
    struct stack st;
    create(&st);
    int c,tsize, ttemp;
    tsize=st.size;
    ttemp=st.top;
    while (tsize != 0)
    {

        printf("Do you want to push again:(1/0):");
        scanf("%d", &c);
        if (c == 1)
        {
            push(&st);
            tsize--;
            continue;
        }
        else if (c == 0)
        {
            break;
        }
    }
    display(&st);

    while (st.top != -1)
    {
        printf("\nDo you want to pop again:(1/0):\n");
        scanf("%d", &c);
        if (c == 1)
        {
            printf("%d\t", pop(&st));
            st.top--;
            continue;
        }

        else if (c == 0)
            break;
    }
    display(&st);

    if(st.top==-1)
    {
        printf("\nstack empty");
    }
    else if(st.top==st.size-1)
    {
        printf("\nstack full");
    }
    printf("\npeaking 1st position value:...");
    printf("\n%d",peak(&st,1));
    return 0;
}