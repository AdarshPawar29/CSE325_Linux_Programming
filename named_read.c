#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
	int res, n;
	char buffer [100];
	res = open("fifo1",O_RDONLY);
	n = read(res,buffer,100);
	printf("Total bytes read: %d\n",n);
	printf("%swas passed to me \n", buffer );
	printf("Process %d finished\n",getpid());
}