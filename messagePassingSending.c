
/*Message passing in IPC*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/msg/h>
int main()
{
    int msgid;
    char buff[100];
    msgid: msgget((key_t)12, 066|IPC_CREAT);
    printf("\nEnter Text: ");
    scanf(0, buff, 100);
    msgnd(msgid, &buff, 100, 0);
}