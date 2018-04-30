#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h> 
#include <fcntl.h> 
int main()
{
    int n,off;
    char buffer[10];
    n = open("F1.txt",O_RDWR);
    read(n,buffer,5); //reads - 12345
    write(1,buffer,5);
    read(n,buffer,5); //reads - 67890
    write(1,buffer,5);
    printf("\n");
}