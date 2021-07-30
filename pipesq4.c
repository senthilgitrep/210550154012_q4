//*** To communicate a file from Process P1 to P2 using Pipes and print length of strings starting with letter m ***//

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

#define SIZE 64

int main(int argc, char const *argv[])
{
	unsigned char buff[SIZE];
	unsigned char buff1[SIZE];
	int pfd[2];
	int pfdr[2];
	pid_t id;
	pipe(pfd);
	pipe(pfdr);
	id = fork();
	
if (0 == id)
{
printf("Child\n");
close(pfd[1]);
read(pfd[0], buff, SIZE);
printf("Child: Got the string: %s\n", buff);
printf("Length of string %d", sizeof(char), strlen(buff));
close(pfd[0]);
}

else
{
printf("Parent\n");
close(pfd[0]);
printf(buff, "Man made machine");
read(pfd[1], "Man made machine\n", 17);
close(pfd[1]);
}
}
