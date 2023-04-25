#include<stdio.h>
#include<time.h>
main()
{
    int n;
    int k;
    int m;
    int b,c;

    printf("enter the number of elements\n");
    scanf("%d",&n);
 int a[n-1];
    FILE* fp= fopen("input1.txt","a");
    for(int i=0;i<n;i++)
    {
      k=rand()%(50-0);
      a[i]=k;
      printf("%d\n",a[i]);
      fprintf(fp,"%d ",k);
    }
    clock_t start=clock();
 for(int j=0;j<n;j++)
 {
     for(int l=j+1;l<n;l++)
     {
        if(a[j]>a[l])
        {
            c=a[l];
            a[l]=a[j];
            a[j]=c;

        }
     }
 }

clock_t end=clock();
 double time_taken = ((double)(end - start));


 for(int i1=0;i1<n;i1++)
 {
     printf("%d ",a[i1]);
 }
 printf("\n %f",time_taken );
}

