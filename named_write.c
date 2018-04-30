#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
	int res, n;
	res = open("fifo1",O_WRONLY);
	write(res,"writen",7);
	printf("Process %d finished\n",getpid());
}