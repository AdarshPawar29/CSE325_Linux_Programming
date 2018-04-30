//Send_Message
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
    int fd[2], n;
    char buffer[100];
    pid_t p;
    pipe(fd);
    p=fork();
    if(p>0)
    {
        close(fd[0]);
        printf("passing value to child\n");
        write(fd[1], "hello\n", 6);
        wait(0);
    }
    else
    {
        close(fd[1]);
        n = read(fd[0], buffer, 100);
        write(1, buffer, n);
    }
}