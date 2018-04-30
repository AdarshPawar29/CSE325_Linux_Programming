#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
  int fd,n1,n2,m;
  char buff[100];
  n1 = read(0,buff,100);
  fd = open("Check",O_CREAT|O_RDWR,0777);
  write(fd,buff,n1);
//  write(1,buff,5);
  lseek(fd,2,SEEK_SET);
  m = read (fd,buff,5);
  write(1,"AfterSeek",9);
  write(1,buff,m);
  printf("\n");
}
