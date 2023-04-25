#include<stdio.h>
main()
{
    int k;
    int a[10];
FILE* fp=fopen("input1.txt","r");
int j=fscanf(fp,"%d",&k);
int i=0;
while(k!=' ')
{
    a[i]=k;

    printf("%d ",a[i]);
     i++;
    fscanf(fp,"%d",&k);
}
}
