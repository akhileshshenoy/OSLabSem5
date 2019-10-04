#include<sys/types.h> // for pid and fork
#include<unistd.h> //for pid
#include<stdio.h>
#include<stdlib.h>

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
		wait(NULL); //&status-(int) if we want to know how child died and return type of wait is pid of dead child
		printf("Child terminated!");
	}
	else
	{
		execlp("/Desktop/OS/test","test",NULL);
	}
}