//Write a program to create a child presses
//the parents print 20-29 and child prints 0-9 .
// Also both the message prints the same common message.
#include<stdio.h>
#include<dirent.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
  pid_t p;
  int i, j;
  p = fork(); //a duplicate or child process creater
  switch (p)
  {
    case 1:
          printf("Error");
      break;
    case 0://child execution
        for(i=0;i<10;i++)
        {
          printf("%d\n",i);
        }
      break;
    default:// wait() //Parent is executing
      for(j=20;j<30;j++)
      {
        printf("%d\n",j);
        sleep(1);
      }
  }
  printf("\ncommon message.!.");
}
