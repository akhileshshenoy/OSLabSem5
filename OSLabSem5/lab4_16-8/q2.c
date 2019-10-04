#include"header.h"
int main()
{
	pid_t pid;
	int status;
	pid=fork();
	if(pid==-1)
		printf("ERROR\n");
	else if(pid==0)
		execlp("./q1",NULL);
	else
	{
		wait(&status);
		printf("Parent q2\n");
	}
}
