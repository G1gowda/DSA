#include<stdio.h>
struct Node{
int s;
struct Node *next;

};typedef struct Node *node;

node push(node top,int data, FILE *fst)
{
    node nw;
    nw=(node)malloc(sizeof(struct Node));
    if(nw==NULL)
    {
        printf("no memory\n");
        exit(0);
    }
    else if (top==NULL)
    {   printf("\n88\n");
         nw->next=NULL;
        nw->s=data;
        top=nw;

    }
    else
    {  printf("\n77\n");
         nw->s=data;
        nw->next=top;
        top=nw;
    }
    node temp=top;
    while(temp!=NULL)
    {
        fprintf(fst,"%d ",temp->s);
        temp=temp->next;
    }
     fclose(fst);
    return top;

}
node pop(node top, FILE *fpo,FILE *fst)
{
       int k=top->s;

        fprintf(fpo,"%d ",k);
        node temp1=top;
top=top->next;
free(temp1);
node temp=top;
 while(temp!=NULL)
    {
        fprintf(fst,"%d ",temp->s);
        temp=temp->next;
    }
    fclose(fst);
return top;
}
void display(node top)
{    printf("\ndisplay\n");
    node temp=top;

    printf("\ndisplay\n");
    while(temp!=NULL)
    { printf("\ndisplay\n");
        printf(" %d ",temp->s);
        temp=temp->next;
    }
}
main()
{
    node top;

    top=NULL;
    int n,n1,j,k,k1;
     printf("enter number of random numbers to be generated \n");
     scanf("%d",&n1);
     FILE *fi=fopen("input1.txt","w");
     for(int h=0;h<n1;h++)
    {
        k1=rand()%(100-10+1);
        fprintf(fi,"%d ",k1);
    }
    fclose(fi);
    fi=fopen("input1.txt","r");
    FILE *fope=fopen("operations.txt","w");
    FILE *fpu=fopen("push.txt","w");
     FILE *fpo=fopen("pop.txt","w");
    while(1)
    {
        printf("1 push\n2 pop\n3 display");
        scanf("%d",&n);
        if(n==1)
        {   j= fscanf(fi,"%d",&k);
             if(j!=-1)
             { FILE *fst=fopen("stack.txt","w");
               fputs("push()\n",fope);
                fprintf(fpu,"%d ",k);
            top=push(top,k,fst);
             }
             else
            { fputs("push() no elements\n",fope);

                   }
        }
        else if(n==2)
        {
              if(top==NULL)
        {
             fputs("pop() no elements\n",fope);
             break;

        }
        else{
               FILE *fst=fopen("stack.txt","w");
                fputs("pop()\n",fope);
            top=pop(top,fpo,fst);
        }
        }
        else if(n==3)
       {

        display(top);
        }
        else
        {
            fclose(fpu);
            fclose(fpo);
            exit(0);
        }
    }
}
