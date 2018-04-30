#include<stdio.h>
#include<stdlib.h>
int main()
{
    int f[50],p,i,j,k,a,st,len,n,c;
    for(i=0;i<50;i++)
    f[i]=1;
    printf("Enter how many blocks that are allocated:\t");
    scanf("%d",&p);
    printf("\n Enter the blocks nos that are already allocated");
    for(i=0;i<p;i++)
    {
        scanf("%d", &a);
        f[a]=0;
    }
    X:
    printf("Enter the starting index block and length:\t");
    scanf("%d%d",&st, &len);
    k=len;
    for(j=st;(k+st);j++)
    {
        if(f[j]==1)
        {
            f[j]=0;
            printf("\n%d->%d",j,f[j]);
        }
        else
        {
            printf("\n %d->block is already allocated",j);
            k++;
        }
    }
    printf("\n Do you want to enter another file?(yes-1/no-0)");
    scanf("%d",&c);
    if(c==1)
    goto X;
    else 
    exit(0);
}
