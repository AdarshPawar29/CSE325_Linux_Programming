#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

void main()
{
  char buffer[100];
  char childbuff[100];
  int fd[2], des, bytes, target;

  pipe(fd);

  if(fork()) {
    /* parent process closes the downstream */
    close(fd[0]);

    /* reads the file */
    des = open("test.txt", O_RDONLY);
    bytes = read(des, buffer, sizeof(buffer));

    /* puts data in pipe */
    write(fd[1], buffer, bytes);
  } else {
    /* Child process closes the upstream */
    close(fd[1]);

    /* reads from the pipe */
    read(fd[0], childbuff, sizeof(childbuff));
    close(fd[0]);

    /* output the received string */
    printf("\nReceived string is -- %s", childbuff);
    target = open("copy.txt", O_CREAT, 00777);
    write(target, childbuff, (strlen(childbuff)-1));
  }
}
