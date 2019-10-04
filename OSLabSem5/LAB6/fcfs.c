#include<stdio.h>
#include<stdlib.h>

void findWaitingTime(int n,double arrival[],double burst[],double waiting[])
{
	waiting[0]=0;
	for(int i = 1; i<n; i++)
	{
		waiting[i]=waiting[i-1]+burst[i-1]-arrival[i]+arrival[i-1];
		if(waiting[i]<0)
			waiting[i]=0;	
	}
	return;
}

void findTurnaroundTime(int n,double burst[], double waiting[], double turnaround[])
{
	for (int i = 0; i < n; ++i)
	{
		turnaround[i] = waiting[i] + burst [i];
	} 	
}

void findAvgTime(int n, double arrival[], double burst[])
{
	double waiting[n],turnaround[n];
	findWaitingTime(n,arrival,burst,waiting);
	findTurnaroundTime(n,burst,waiting,turnaround);
	double sum=0;
	for(int i=0;i<n;i++)
		sum+=waiting[i];
	double avgWaitingTime = sum/n;
	sum=0;
	for(int i=0;i<n;i++)
		sum+=turnaround[i];
	double avgTurnaroundTime = sum/n;
	printf("Average waiting time is %lf\n",avgWaitingTime);
	printf("Average turnaround time is %lf\n",avgTurnaroundTime);  
	return;
}

int main()
{
	int n;
	printf("Enter number of processes :");
	scanf("%d",&n);
	double burst[n],arrival[n];
	for(int i = 0; i < n; i++)
	{
		printf("Enter arrival time and burst time of process %d :",i+1);
		scanf("%lf %lf",&arrival[i],&burst[i]);
	}
	findAvgTime(n,arrival,burst);
}