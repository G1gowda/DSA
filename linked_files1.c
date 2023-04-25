#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct NODE
{
    int data;
    struct node *next;
};
typedef struct NODE *node;
node head;
node data(node head,int i);
node display(node head,FILE *fq);

 node data(node head, int i)
 {   node nw;
 nw=(node)malloc(sizeof(struct NODE));
node temp;
 if(nw==NULL)
 {
     printf("\n memory not allocated");

 }
 else if(head==NULL)
 {  nw->next=NULL;
 //printf("\n D,%d",i);
 nw->data=i;
     head=nw;
     return head;

 }

 else
 {
temp=head;
     while(temp->next!=NULL)
     {
         temp=temp->next;
     }

     temp->next=nw;
     nw->next=NULL;
   //printf("\n D,%d",i);
     nw->data=i;
      return head;
 }
 }
node sort(node head)
{
    node temp1,temp2;
    temp1=head;
    temp2=head;
    int t;

   for(temp1=head;temp1!=NULL;temp1=temp1->next)
    { //printf("3");
    //temp2=temp1->next;
       for(temp2=temp1->next;temp2!=NULL;temp2=temp2->next)
        {//printf("4");
            if(temp1->data>temp2->data)
            {
                t=temp2->data;
                temp2->data=temp1->data;
                temp1->data=t;

            }

        }

    }
    return head;
}

node display( node head,FILE *fq)
 {
     node temp;

     // printf("\n%d",head->data);
     for(temp=head;temp!=NULL;temp=temp->next)
     {
         fprintf(fq,"%d ",temp->data);
          printf("%d ",temp->data);

     }
     return head;
 }

int main()
{
    head=NULL;
    FILE *fp=fopen("input1.txt","r");
    FILE *fq=fopen("output1.txt","w");
    int i,j;
    j=fscanf(fp,"%d",&i);
    //printf("%d  %d",j,i);
    while(j!=-1)
    {//printf("\n%d",i);
      head=data(head,i);
      j=fscanf(fp,"%d",&i);

    }
    clock_t start=clock();
      head=sort(head);
      clock_t end=clock();
    float time=(float)(end-start)/CLOCKS_PER_SEC;
    printf("\n%f ",time);
      head=display(head,fq);
    return 0;
}
