//Program: zombie.c
#include<stdio.h>
#include <sys/types.h>
#include<unistd.h>
#include <pthread.h>
int main()
{
   pid_t t;
   t=fork();
   if(t==0)
   {
       printf("Child having id %d\n",getpid());
    }
    else
    {
        printf("Parent having id %d\n",getpid());
        sleep(15); // Parent sleeps. Run the ps command during this time
    }
}
//  How it works: Compile the program and run it using ./a.out &. 
// The '&' signs makes it run in the background. 
// After you see both the printf statement output the parent will go into sleep for 15 seconds. 
// During this time type the command 'ps'. 
// The output will contain a process with defunct written in the end. 
// This is the child process process(can be verified from PID) which has become zombie. */