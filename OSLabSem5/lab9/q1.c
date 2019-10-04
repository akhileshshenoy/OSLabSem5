#include<stdio.h>
#include<stdlib.h>

int checkFlags(int flag[],int numOfProc)
{
	for(int i = 0; i < numOfProc ; ++i)
	{
		if(flag[i]==0)
			return 1;
	}
	return 0;
}

int checkIfFeasible(int need[],int work[],int numOfRes)
{
	for(int i = 0; i < numOfRes ; ++i)
	{
		if(need[i]>work[i])
			return 0;
	}
	return 1;
}

int main()
{
	int alloc[10][10],max[10][10],need[10][10],available[10],flag[10],work[10];
	int numOfProc,numOfRes,safeOrder[10];
	printf("Enter the number of processes and resources :");
	scanf("%d %d",&numOfProc,&numOfRes);
	printf("Enter allocation matrix:\n");
	for(int i=0;i<numOfProc;i++)
		for (int j = 0; j < numOfRes; ++j)
		{
			scanf("%d",&alloc[i][j]);
		}
	printf("Enter max matrix:\n");
	for(int i=0;i<numOfProc;i++)
		for (int j = 0; j < numOfRes; ++j)
		{
			scanf("%d",&max[i][j]);
		}
	printf("Enter available vector: ");
	for (int j = 0; j < numOfRes; ++j)
		{
			scanf("%d",&available[j]);
		}
	printf("Need matrix is : \n");
	for(int i=0;i<numOfProc;i++)
	{
		for (int j = 0; j < numOfRes; ++j)
		{
			need[i][j] = max[i][j] - alloc[i][j];
			printf("%d ",need[i][j]);
		}
		printf("\n");
	}

	for (int j = 0; j < numOfProc; ++j)
		{
			flag[j] = 0;
		}
	for (int j = 0; j < numOfRes; ++j)
		{
			work[j] = available[j];
		}	
	int procNum = 0,prevProcNum = -1,safeOrderIndex = 0;
	while(checkFlags(flag,numOfProc))
	{
		printf("%d %d \n",procNum,prevProcNum); 
		if(prevProcNum == procNum)
		{
			printf("No safe state possible.");
			exit(0);
		}
		if(checkIfFeasible(need[procNum],work,numOfRes))
		{
			for (int j = 0; j < numOfRes; ++j)
			{
				work[j] += alloc[procNum][j];
			}
			flag[procNum] = 1;
			prevProcNum = procNum;
			safeOrder[safeOrderIndex++] = procNum;	
		}
		if(prevProcNum == -1)prevProcNum = 0;
		procNum = (procNum + 1) % numOfProc;
	}
	printf("Safe state is possible.\n");
	printf("Order is :");
	for (int i = 0; i < numOfProc; ++i)
	{
		printf("%d	",safeOrder[i]);
	}

}