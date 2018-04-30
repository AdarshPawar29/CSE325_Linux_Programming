/*Reading data from the message queue*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/msg/h>
int main()
{
    int msgid;
    char buff[100];
    msgid=msget((key_t)12, 066);
    printf("Data read from the message is: ");
    msgrcv(msgid, &buff, 100, 0);
    printf("%s", buff);
}