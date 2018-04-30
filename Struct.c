#include<stdio.h>
#include<dirent.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
  DIR *dp;
  struct dirent *dptr;
  mkdir("Adarsh",0777);
  dp = opendir("Adarsh");
  while ((dptr = readdir(dp)) != NULL)
  {
    printf("%s\n",dptr -> d_name );
    printf("%d\n",dptr -> d_type );
    printf("%llu\n",dptr -> d_ino );
  }
  closedir(dp);
}
// struct dirent
// {
//   int_t d_ino;
//   off_t d_ff;
//   unsigned char reclen;
//   int d_type;
//   char d_name[256];
// }
