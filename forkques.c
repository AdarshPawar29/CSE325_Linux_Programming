//wap to create a child process. the parent's print 20-29 and child prints 0-9. also both the process prints a common message
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
//The <sys/stat.h> header shall define the structure of the data returned by the functions fstat(), lstat(), and stat().
#include<sys/wait.h>
int main()
{
	pid_t p;
	int i,j;
	p=fork();
	switch(p)
	{
		case -1: printf("Error");
			break;
		case 0: //Child is executing
			for(i=0;i<10;i++)
			{
				printf("%d\n",i);
				sleep(1);
			}
			break;
		default: //wait();
			for(j=20;j<30;j++)
			{
				printf("%d\n",j);
				sleep(1);
			}
	}
	printf("Common Message\n");
}
