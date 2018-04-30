//program to opendir, readdir and closedir
#include<stdio.h>
#include<dirent.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
int main()
{
	DIR *dp;
	struct dirent *dptr;
	mkdir("Arun",0777);
	dp = opendir("Arun");
	while((dptr = readdir(dp)) != NULL)
	{
		printf("%s/\n",dptr->d_name);
		printf("%d\n",dptr->d_type);
		printf("%llu\n",dptr->d_ino);
	}
	closedir(dp);
}
