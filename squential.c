#include<stdio.h>
#include<stdlib.h>
int main()
{
	int f[50],i,st,j,len,c,k;
	for(i=0;i<50;i++)
	{
		f[i]=1;
	}
	X:
	printf("\n Enter the starting block & length of file: ");
	scanf("%d%d",&st,&len);
	for (j = st; j < (st+len); j++)
	{
		if (f[j]==1)
		{	
			f[j]=0;
			printf("\n%d->%d", j,f[j]);
		}
		else
    	{
        	printf("Block already allocated");
        	break;
    	}
    }
    if(j==(st+len))
    {
	  	printf("\n the file is allocated to the disk\t");
	   	printf("\nif you want to enter more files?(y-1/n-0)\t");
	  	scanf("%d",&c);
   	}
   	if(c==1)
   	{
  		goto X;
   	}
   	else
      	exit(0);	
}