#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
int main()
{
	int n, off;
	char buffer[10];
	n = open("F1.txt",O_CREAT|O_RDWR,0777);
	read(n,buffer,5); //read first 5 charactors
	write(1,buffer,5);
	off = lseek(n,10,SEEK_SET);//pointer will be at 10th from beginning
	//off = lseek(n,10,SEEK_CUR);//pointer will be 10 position ahead from current postion
	//off = lseek(n,-3,SEEK_END);//pointer will be in last 3rd poistion from END
	printf("\nCurrent position is %d \n", off);
	//printf("\n");
	read(n,buffer,5);
	write(1,buffer,5); 
	printf("\n");
}