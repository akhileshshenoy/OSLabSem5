#include<stdio.h>
#include<stdlib.h>

void FIFO(int frameArr[], int pageArr[], int numOfFrames, int numOfPages)
{
	for (int i = 0; i < numOfFrames; ++i)
	{
	 	frameArr[i] = -1;
	}
	int firstIn = 0,pageHit = 0, pageFault = 0, hit = 0;
	for (int i = 0; i < numOfPages; ++i)
	{
		for (int j = 0; j < numOfFrames; ++j)
		{
			hit = 0;
		 	if(pageArr[i]==frameArr[j])
		 	{
		 		pageHit++;
		 		hit = 1;
		 		break;
		 	}
		}
		if (hit == 0)
		{
			pageFault++;
			frameArr[firstIn] = pageArr[i];
			firstIn = (firstIn + 1) % numOfFrames;
		}
	}
	printf("In FIFO\nPage hits = %d\nPage faults = %d\n",pageHit,pageFault);
}

void OPTIMAL(int frameArr[], int pageArr[], int numOfFrames, int numOfPages)
{
	for (int i = 0; i < numOfFrames; ++i)
	{
	 	frameArr[i] = -1;
	}
	int maxDist = 0,nextAppear = 0,frameToReplace,pageHit = 0, pageFault = 0, hit = 0;
	for (int i = 0; i < numOfPages; ++i)
	{
		for (int j = 0; j < numOfFrames; ++j)
		{
			hit = 0;
		 	if(pageArr[i]==frameArr[j])
		 	{
		 		//printf("\nhit %d",pageArr[i]);
		 		pageHit++;
		 		hit = 1;
		 		break;
		 	}
		}
		if (hit == 0)
		{
			pageFault++;
			//printf("\n%d ",numOfPages-i);
			maxDist = 0;
			for (int j = 0; j < numOfFrames; ++j)
			{
				nextAppear = 1;
				while(nextAppear<numOfPages-i)
				{
					if(frameArr[j] != pageArr[i+nextAppear])
						nextAppear++;
					else 
						break;
				}
				//printf("%d %d\t",frameArr[j],nextAppear);
				if(nextAppear>maxDist)
				{
					maxDist = nextAppear;
					frameToReplace = j;
					if(maxDist == numOfPages-i)
						break;
				}
			}

			frameArr[frameToReplace] = pageArr[i];
			//printf("current frame:");
			// for (int k = 0; k < numOfFrames; ++k)
			// {
			// 	printf("%d ",frameArr[k]);
			// }

		}
	}
	printf("In OPTIMAL\nPage hits = %d\nPage faults = %d\n",pageHit,pageFault);
}

void LRU(int frameArr[], int pageArr[], int numOfFrames, int numOfPages)
{
	for (int i = 0; i < numOfFrames; ++i)
	{
	 	frameArr[i] = -1;
	}
	int LRUIndex,minLRU,pageHit = 0, pageFault = 0, hit = 0;
	int* LRUArr = malloc(sizeof(int)*numOfFrames);
	for (int i = 0; i < numOfFrames; ++i)
	{
	 	LRUArr[i] = -1;
	}

	for (int i = 0; i < numOfPages; ++i)
	{
		for (int j = 0; j < numOfFrames; ++j)
		{
			hit = 0;
		 	if(pageArr[i]==frameArr[j])
		 	{
		 		pageHit++;
		 		LRUArr[j] = i;
		 		hit = 1;
		 		break;
		 	}
		}
		if (hit == 0)
		{
			pageFault++;
			LRUIndex=-1;
			for (int j = 0; j < numOfFrames; ++j)
			{
				if(LRUArr[j]<0)
				{
					LRUIndex = j;
					break;
				}
				if(LRUIndex == -1)
				{
				 	LRUIndex = j;
				 	minLRU = LRUArr[j];
				}
				if(LRUArr[j]<minLRU)
				{
					LRUIndex = j;
					minLRU = LRUArr[j];
				}
			}
			LRUArr[LRUIndex] = i;
			frameArr[LRUIndex] = pageArr[i];
		}

	}
	printf("In LRU\nPage hits = %d\nPage faults = %d\n",pageHit,pageFault);
}

void secChance(int frameArr[], int pageArr[], int numOfFrames, int numOfPages)
{
	for (int i = 0; i < numOfFrames; ++i)
	{
	 	frameArr[i] = -1;
	}
	int replceIndex,firstIn = 0,pageHit = 0, pageFault = 0, hit = 0;
	int* secondChanceArr = malloc(sizeof(int)*numOfFrames);
	for (int i = 0; i < numOfFrames; ++i)
	{
	 	secondChanceArr[i] = 0;
	}

	for (int i = 0; i < numOfPages; ++i)
	{
		printf("\n%d %d ",pageArr[i],firstIn);
		for (int j = 0; j < numOfFrames; ++j)
		{
			hit = 0;
		 	if(pageArr[i]==frameArr[j])
		 	{
		 		pageHit++;
		 		secondChanceArr[j] = 1;
		 		hit = 1;
		 		break;
		 	}
		}
		if (hit == 0)
		{
			pageFault++;
			for (int j = 0; j < numOfFrames; ++j)
			{
				if(secondChanceArr[(firstIn+j)%numOfFrames]==1)
					secondChanceArr[(firstIn+j)%numOfFrames]=0;
				if(secondChanceArr[(firstIn+j)%numOfFrames]==0)
				{
					replceIndex = (firstIn+j)%numOfFrames;
					break;
				}
			}
			//secondChanceArr[replceIndex] = 1;
			frameArr[replceIndex] = pageArr[i];
			firstIn = (replceIndex + 1) % numOfFrames;
		}
					printf("current frame:");
			for (int k = 0; k < numOfFrames; ++k)
			{
			 	printf("%d ",frameArr[k]);
			}
								printf("\tcurrent secframe:");
			for (int k = 0; k < numOfFrames; ++k)
			{
			 	printf("%d ",secondChanceArr[k]);
			}
	}
	printf("In Second Chance\nPage hits = %d\nPage faults = %d\n",pageHit,pageFault);
}


int main()
{
	int numOfFrames,numOfPages;
	
	printf("Enter the number of frames: ");
	scanf("%d",&numOfFrames);
	
	printf("Enter the number of pages in order: ");
	scanf("%d",&numOfPages);
	
	int* frameArr = malloc(sizeof(int)*numOfFrames);
	int* pageArr = malloc(sizeof(int)*numOfPages);
	
	printf("Enter the page vector : ");
	for (int i = 0; i < numOfPages; ++i)
	{
	 	scanf("%d",&pageArr[i]);
	}

	// FIFO(frameArr,pageArr,numOfFrames,numOfPages);
	// OPTIMAL(frameArr,pageArr,numOfFrames,numOfPages);
	// LRU(frameArr,pageArr,numOfFrames,numOfPages);
	secChance(frameArr,pageArr,numOfFrames,numOfPages);
	return 0;
}