#include"header.h"
int main()
{
	pid_t pid;
	int status;
	pid=fork();
	if(pid==-1)
		printf("ERROR\n");
	else if(pid==0)
	{
		printf("%d",getppid());
		sleep(2);
		printf("Child running\n");
		printf("%d",getppid());
		exit(1);
	}
	else
	{
		sleep(1);
		printf("Parent running\n");
	}
}
