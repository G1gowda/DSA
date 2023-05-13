#include<stdio.h>
#include<stdlib.h>
int stack[100];
int top=-1;
int push1(int k,FILE *fpu,FILE *fst)
{ top++;
   stack[top]=k;
   for(int i=0;i<=top;i++)
   {
   fprintf(fst,"%d ",stack[i]);
   }

    fprintf(fpu,"%d ",k);
printf("%d\n",k);
 fclose(fpu);
    return;
}
int pop(FILE *fpo,FILE *fst)
{    int k;
     k=stack[top];
     printf("%d",k);
    top--;
     for(int i=0;i<=top;i++)
   {
   fprintf(fst,"%d ",stack[i]);
   }
    fprintf(fpo,"%d ",k);
    return;
}

main()
{    int j,k,n;
    FILE *fi=fopen("input1.txt","r");

    //FILE *fst1=fopen("stack.txt","r");

    while(1)
    { printf("\nenter 1 for push\n2 for p0p\n3for exit\n");
        scanf("%d",&n);

        if(n==1)
        {   FILE *fope=fopen("operations.txt","a");
            fputs("push()\n",fope);
            fclose(fope);
            FILE *fpu=fopen("push.txt","a");
            FILE *fst=fopen("stack.txt","w");
            j= fscanf(fi,"%d",&k);
           // printf("%d %d",j,k);
            if(j!=-1)
            {
            push1(k,fpu,fst);
            fclose(fpu);
            fclose(fst);

            }

        }

        else if(n==2)
        {
             FILE *fope=fopen("operations.txt","a");
            fputs("pop()\n",fope);
            fclose(fope);
        FILE *fpo=fopen("pop.txt","a");
        FILE *fst=fopen("stack.txt","w");
         pop(fpo,fst);
         fclose(fpo);
         fclose(fst);
        }
        else
            exit(0);
    }
}
