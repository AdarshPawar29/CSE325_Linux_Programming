#include<stdio.h>
#include<stdlib.h>
int f[50], i ,j, k, inde[50], n, c, count=0, p;
int main()
{
    for(i=0;i<50;i++)
    f[i]=1;
    X:
    printf("Enter index block:\t");
    scanf("%d", &p);
    if(f[p]==1)
    {
        f[p]=0;
        printf("Enter the files on index block\t");
        scanf("%d",&n);
    }
    else
    {
        printf("block alredy allocated\n");
        goto X;
    }
    for(i=0;i<n;j++)
    scanf("%d",&inde[i]);
    for(i=0;i<n;i++)
    if(f[inde[i]]==0)
    {
        printf("block already allocated;");
        goto X;    
    }
    for(i=0;i<n;i++)
    f[inde[j]]=0;
    printf("\n allocated");
    printf("\n file indexed");
    for(k=0;k<n;k++)
    printf("\n %d->%d:%d",p ,inde[k], f[inde[k]]);
    printf("Enter 1 to enter more files and 0 to exit\t");
    scanf("%d",&c);
    if(c==1)
    goto X;
    exit(0);
}