#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include <stdio.h>
#include <fcntl.h> // open function
#include <unistd.h> // close function
// #include <ctype.h>
// #include <errno.h>
// #include <string.h>
int main()
{
  int n,fd;
  char buff[100];
  n = read(0,buff,100);
  fd = open("newFile",O_CREAT|O_RDWR,0777);
  write(fd,buff,n);
  write(0,buff,n);
}
