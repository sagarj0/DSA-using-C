#include<stdio.h>
#include<conio.h>

void TOH(int n, char O, char I, char D )
{
    if(n>0)
    {
        TOH(n-1,O,D,I);
        printf("move disk %d from %c to %c \n",n,O,D);
        TOH(n-1,I,O,D);
    }
}

int main()
{
    int n;
    printf("Enter number of disks:");
    scanf("%d",&n);
    TOH(n,'O','I','D');
    return 0;
}