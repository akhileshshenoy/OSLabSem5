#include"header.h"
int main()
{
	pid_t pid;
	int status;
	pid=fork();
	if(pid==-1)
	{
		printf("ERROR\n");
		exit(0);
	}
	else if(pid==0)
		printf("Child:\n");
	else
	{
		wait(&status);
		printf("Parent:\n");
	}
	printf("PID of Child: %d\n",pid);
	pid=getpid();
	printf("PID of Process: %d\n",pid);
	pid=getppid();
	printf("PID of Parent: %d\n",pid);
}