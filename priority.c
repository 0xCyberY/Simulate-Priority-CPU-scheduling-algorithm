#include<stdio.h>
int main()
{
int p[20],bt[20],pri[20], wt[20],tat[20], n,i, temp;
float wtavg=0, tatavg=0;
printf("Enter the number of processes --- ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
	p[i] = i;
	printf("Enter the Burst Time & Priority of Process %d --- ",i);
	scanf("%d %d",&bt[i], &pri[i]);
}
for(int i=0;i<n;i++)
for(int k=i+1;k<n;k++)
if(pri[i] > pri[k])
   {
	temp=p[i];
	p[i]=p[k];
	p[k]=temp;

	temp=bt[i];
	bt[i]=bt[k];
	bt[k]=temp;

	temp=pri[i];
	pri[i]=pri[k];
	pri[k]=temp;
   }
wt[0] = 0;
tat[0] = bt[0];
for(int i=1;i<n;i++)
   {
	wt[i] = wt[i-1] + bt[i-1];
	tat[i] = tat[i-1] + bt[i];
	wtavg = wtavg + wt[i];
	tatavg = tatavg + tat[i];
   }
printf("\nPROCESS\t\tPRIORITY\tBURST TIME\tWAITING TIME\tTURNAROUND TIME");
for(int i=0;i<n;i++)
	printf("\n%d \t\t %d \t\t %d \t\t %d \t\t %d ",p[i],pri[i],bt[i],wt[i],tat[i]);
	printf("\nAverage Waiting Time is --- %f",wtavg/n);
	printf("\nAverage Turnaround Time is --- %f\n",tatavg/n);
return 0;

}

