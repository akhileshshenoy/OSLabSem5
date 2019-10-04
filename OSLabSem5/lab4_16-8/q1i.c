#include<sys/types.h> // for pid and fork
#include<unistd.h> //for pid
#include<stdio.h>

int main()
{
	pid_t pid;
	pid=fork(); //create a child process
	if(pid<0)
	{
		printf("Couldn't create a child process.\n");
		exit(-1);
	}
	else if(pid==0)
	{
		printf("Waiting for child to terminate or stop\n");
		wait(NULL); //&status-(int) if we want to know how child died and return type of wait is pid of dead child
		printf("Child terminated");
	}
	else
	{
		for(int i = 0; i < 10; i++)
			printf("%d\n",i);
	}
}