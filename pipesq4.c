#include <stdio.h>
#include <unistd.h>
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
close(pfd[0]);
}
else
{
printf("Parent\n");
close(pfd[0]);
read(pfd[1], "Memory\n", 10);
close(pfd[1]);
}
}
