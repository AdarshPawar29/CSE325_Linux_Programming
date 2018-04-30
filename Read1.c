#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
  int n;
  char buff [50];
  n = read(0,buff,50);
  write (0,buff,n);
}
