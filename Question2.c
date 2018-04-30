//Write a program to create a child presses
//the parents print "integer no." and child prints "Integer number" user defind .
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
  int i, j,Pn,Pm,Cn,Cm;
  printf("Enter the start value of Child: \n");
    scanf("%d", &Cn);
  printf("Enter the end value of Child:\n");
    scanf("%d", &Cm);
  printf("Enter the start value of Parents:\n");
    scanf("%d", &Pn);
  printf("Enter the end value of Parents:\n");
    scanf("%d", &Pm);
  p = fork(); //a duplicate or child process creater
  switch (p)
  {
    case 1:
          printf("Error");
      break;
    case 0://child execution
        for(i=Cn;i<Cm;i++)
        {
          printf("%d\n",i);
        }
      break;
    default:// wait() //Parent is executing
      for(j=Pn;j<Pm;j++)
      {
        printf("%d\n",j);
        sleep(1);
      }
  }
  printf("\ncommon message.!.\n");
}
