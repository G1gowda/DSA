#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;


};typedef struct Node *node;


node getnode();
node data();
node insert(node head, int k);
node getnode()
{
    node nw;
    nw=(node)malloc(sizeof(struct Node));
    if(nw==NULL)
    {
        printf("no memory allocated\n");
        exit(0);
    }
    else{
        nw->next=NULL;
        return nw;
    }
}

node insert(node head,int k)
{ //printf("1\n");
    node nw;
    nw=getnode();
    node temp;
    temp=head;
    if(head==NULL)
    {//printf("2\n");
        return nw;
    }
    else{
    while(temp->next!=NULL)
    {//printf("1\n");
        temp=temp->next;
    }

    temp->next=nw;
    nw->data=k;
    //printf("%d\n",nw->data);
    nw->next=NULL;
    return head;
    }

}
node display(node head)
{
    node temp;
    temp=head;
    if(temp==NULL)
    {
        printf("node is empty\n");
    }
    else if(temp->next==NULL)
    {
      printf("\n%d",temp->data);
    }
    else
 {
     while(temp!=NULL)
     {
        printf("\n%d",temp->data);
        temp=temp->next;

     }

    }
}
main()
{
node head;
    head=NULL;
FILE* fp=fopen("input.txt","r");
int i,k;
i=fscanf(fp,"%d",&k);
   while(i!=EOF)
   { printf("%d ",k);
       head=insert(head,k);
       i=fscanf(fp,"%d",&k);
   }

    display(head);
}
