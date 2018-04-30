#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	int fd[2];
	char buffer[100];
	pid_t p;
	pipe(fd);
	p = fork();

	if(p == -1)
	{
		perror("pipe");
		exit(1);
	}
	if(p == 0)  //child
 	{
 		printf("Child process...\n");
 		write(fd[1],"Hello there!",12);
	}
	else        //parent 
	{
		printf("Parent process...\n");
		read(fd[0],buffer,100);
		printf("Buffer: %s\n", buffer);
	}
}