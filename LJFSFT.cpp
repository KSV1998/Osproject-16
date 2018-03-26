#include<stdio.h>
#include<algorithm>
struct pro_sch
{
	int at,bt,id,wtime,tt,ct;
	bool flag;
}s[10];
	int ab;
void sort(pro_sch *queue[10],int n)
{
	for(int i=0;i<n-1;i++)
		for(int j=0;j<n-i-1;j++)
			if(queue[j]->bt>queue[j+1]->bt)
			{
				pro_sch *temp=queue[j];
				queue[j]=queue[j+1];
				queue[j+1]=temp;
			}
}
int main()
{
	int n,clock;
	printf("Enter Number of process: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("Enter the arrival time for Process%d :",i+1);
		scanf("%d",&s[i].at);
		s[i].id=i+1;
		s[i].bt=s[i].at*2;
		s[i].flag=false;
		s[i].wtime=0;
	}
	printf("--------------------LONGEST JOB FIRST--------------\nSequence of flagcution : \n");
	pro_sch s1[n],*queue[n];
	int size=0;

	int totalcomplete=0;
	int totalturnaround=0;
	int totalwaiting=0;
	for(int i=0;i<n;i++)
	{
		totalwaiting += s[i].wtime;
		totalcomplete=s[i].bt+s[i].wtime+s[i].at+totalcomplete;
		totalturnaround=(s[i].bt+s[i].wtime)+totalturnaround;
	}
	printf("\nDetails of processes are: \n");
	printf("ID\tAT\t\tBT\t\tCT\t\tTT\t\tWT\n");
	for(int i=0;i<n;i++)
	{
		printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",s[i].id,s[i].at,s[i].bt,s[i].bt+s[i].wtime+s[i].at,s[i].bt+s[i].wtime,s[i].wtime);
	}
	printf("Average Turn Around Time: %.2f\n",(float)(totalturnaround)/n);
	printf("Average Waiting Time    : %.2f\n",(float)(totalwaiting)/n);
	printf("\n\n--------------------Shortest JOB FIRST--------------\n\n");
	s[0].ct=s[0].bt+s[0].at;
	s[0].tt=s[0].ct-s[0].at;
	s[0].wtime=s[0].tt-s[0].bt;
	
	for(int i=1;i<n;i++)
	{
		ab=s[i-1].ct;
		sort(s+i,s+n,comp2);
		if(s[i-1].ct<s[i].at)
		{
			s[i].ct=s[i-1].ct+s[i].bt+(s[i].at-s[i-1].ct);
		}
		else
		{

			s[i].ct=s[i-1].ct+s[i].bt;

		}
		s[i].tt=s[i].ct-s[i].at;
		s[i].wtime=s[i].tt-s[i].bt;
	}
	float tat,wtt;
	for(int i=0;i<n;i++)
	{
		tat=tat+s[i].tt;
		wtt=wtt+s[i].wtime;
	}
	
		printf("Average Turn Around Time : %.2f\nAverage Waiting Time     : %.2f",tat/n,wtt/n);
}

