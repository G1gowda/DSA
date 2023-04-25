//program to revers the numbers in a file
#include<stdio.h>
main()
{
    FILE* fp;
    fp=fopen("input.txt","r"); //open the file input present in the system
    int n;
    fscanf(fp,"%d",&n);//to read the first element of the file i.e the number of elements
     int a[n];
    int j;
    FILE* fq=fopen("output.txt","a");//open the file output present in the system
    for(int i=0;i<n;i++)//loop to accept the numbers in the input file and store it in an array a
    {
        fscanf(fp,"%d",&j);
        a[i]=j;

    }
    for(int k=n-1;k>=0;k--)//loop to write all the elements of the array in reversed order
    {
        fprintf(fq,"%d ",a[k]);
    }
fclose(fp);//close both the files
fclose(fq);
}
