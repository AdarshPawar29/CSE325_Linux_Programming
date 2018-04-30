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
  p = fork();
  switch (p)
  {
    case 1:
          printf("Error");
      break;
    case 0://child execution
      printf("I am Child having id %d\n",getpid());
      printf("My Child id is %d\n",getppid());
      break;
    default: //Parent is executing
    printf("I am Parent having id %d\n",getpid());
    printf("My Parent id is %d\n",p);
  }
}
