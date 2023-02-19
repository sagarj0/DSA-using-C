#include <stdio.h>
#include<stdlib.h>


struct Node {
    
int data;
struct Node *next;
struct Node *prev;
    
}*head=NULL;

void create(){
    struct Node *t,*last;
    int n;
    head=(struct Node *)malloc(sizeof(struct Node));
    printf("Enter the no. of nodes:");
    scanf("%d",&n);
    printf("Enter first data:\n");
    scanf("%d",&head->first);
    head->next=head->prev=head;
    last=head;
    int i;
    printf("Enter remaining nodes");
    for(i=1;i<n;i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        scanf("%d",t->data);
    }   
    last->next=t;
    t->prev=last;
    t->next=head;
    head->prev=t;
    last=t;
    
    }
}
void display(struct Node *p){
    
    
    do{
        printf("%d ",p->data);
        p=p->next;
        
    }
    while(p!=head);
}
int count(struct Node *p){
    int len=0;
    do{
        len++;
        p=p->next;
        
    }while(p!=head);
    return len;
}


void insert(struct Node *p, int index,int x){
    int i;
    struct Node *t;
    if(index<0||index>count(p)){
        return;
    }
    if(index==0){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=x;
        t->next=p;
        t->prev=p->prev;
        p->prev->next=t;
        p->prev=t;
        head=t;
    }else{
        for(i=0;i<index-1;i++){
            p=p->next;
        }
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=x;
        t->next=p->next;
        t->prev=p;
        p->next->prev=t;
        p->next=t;
    }
}

int delete(struct Node *p, int index){
    
    int i,x;
    if(index<1||index>count(p)){
        return -1;
    }
    if(index==1){
        
     head=head->next;
     head->prev=p->prev;
     x=p->data;
     p->prev->next=head;
     free(p);
        
    }
    else{
        for(i=0;i<index-1;i++){
            p=p->next;
        }
        p->prev->next=p->next;
        p->next->prev=p->prev;
        x=p->data;
        free(p);
        
    }
    return x;
}
int main(){
    int a[]={1,2,3,4,5};
    create();
    display(head);
    printf("\n length of the LL is \n %d \n",count(head));
    insert(head,2,100);
    display(head);
    printf("\n after deleting\n ");
    delete(head,3);
    display(head);
    return 0;
    
}
