#include"header.h"
int main()
{
	pid_t pid;
	int status;
	pid=fork();
	if(pid==-1)
		printf("ERROR\n");
	else if(pid==0)
		printf("Child\n");
	else
	{
		wait(&status);
		printf("Parent\n");
		printf("Child returned:%d\n",status);
	}
}