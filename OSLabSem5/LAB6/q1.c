#include<stdio.h>
struct pro
{
    int id,at,bt,wt,tt;
};
typedef struct pro pro;

void swap(pro *a,pro *b)
{
	pro temp=*a;
	*a=*b;
	*b=temp;
}

void sort(int arr[])
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}

void asort(pro p[])
{
	for(int i=0;i<3;i++)
		for(int j=0;j<3-i;j++)
			if(p[j].at>p[j+1].at)
				swap(&p[j],&p[j+1]);
}

void bsort(pro p[])
{
	for(int i=0;i<3;i++)
		for(int j=0;j<3-i;j++)
			if(p[j].bt>p[j+1].bt)
				swap(&p[j],&p[j+1]);
}

void fcfs(pro p[])
{
	int tbt=0;
	asort(p);
	for(int i=0;i<4;i++)
	{
		p[i].wt=tbt-p[i].at;
		tbt+=p[i].bt;
		p[i].tt=p[i].wt+p[i].bt;
	}
}

void srtf(pro p[])
{
	//flag2 for max arrived time,flag3 for preempt
	//live is current process,cur is time till now,fin is finishing time,rem is remaining time
	int flag2,flag3=0;
	int live=0,cur=0;
	int rem[4],fin[4];
	for(int i=0;i<4;i++)
		rem[i]=p[i].bt;
	while(1)
	{
		flag2=p[3].at;
		flag3=0;
		for(int i=live+1;i<4 && flag2>0;i++)//checking for preemptive
		{
			if(rem[live]-p[i].at>p[i].bt) //preemptive
			{
				rem[live]-=p[i].at-p[live].at;
				cur=p[i].at;
				live=i;
				flag2-=p[i].at; //0 when all 4 arrived
				flag3=1;
				break;
			}
		}
		if(flag3 && flag2) //all arrived
			continue;
		break;
		//now all arrived so sort by remaining
	}
	sort(rem); //we done bois
	bsort(p);
	for(int i=0;i<4;i++)
	{
		cur+=rem[i];
		fin[i]=cur;
		p[i].wt=fin[i]-p[i].bt-p[i].at;
		p[i].tt=p[i].wt+p[i].bt;
	}
	//Waiting time=Finishing time-Burst-Arrival
}

void rr(pro p[],int quan)
{
	int rem[4],fin[4],flag=1,live=0,cur=0;
	for(int i=0;i<4;i++)
		rem[i]=p[i].bt;
	while(1)
	{
		flag=0;
		for(int i=0;i<4;i++)
			flag+=rem[i];
		if(flag==0)
			return;
		if(rem[live]>quan)
		{
			cur+=rem[live];
			rem[live]=0;
		}
		
		live=(live+1)%4;
	}

}

void disp(pro p[])
{
	printf("ID  AT  BT  WT  TT\n");
	int avgw=0,avgt=0;
	for(int i=0;i<4;i++)
	{
		printf("P%d  %d  %d  %d  %d\n",p[i].id,p[i].at,p[i].bt,p[i].wt,p[i].tt);
		avgw+=p[i].wt;
		avgt+=p[i].tt;
	}
	printf("AVG WT: %d\n",avgw/4);
	printf("AVG TT: %d\n",avgt/4);
}

int main()
{
	int t;
    pro p[4];
    printf("Enter arrival time and burst time:\n");
    for(int i=0;i<4;i++)
    {
    	scanf("%d %d",&p[i].at,&p[i].bt);
        p[i].id=i+1;
    }
    fcfs(p);
    printf("\nFCFS:\n");
    disp(p);
    srtf(p);
    printf("\nSRTF:\n");
    asort(p);
    disp(p);
    printf("\nEnter time quantum: ");
    scanf("%d",&t);
    rr(p,t);
    printf("RR:\n");
    asort(p);
    disp(p);
}
