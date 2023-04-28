#include<stdio.h>
int main()
{
	int i, burst  =  0, n, timeq;
	float tsum=0, wsum=0;
	printf("Enter number of processes : ");
	scanf("%d", &n);
	int a[n], bt[n], at[n], Pnum[i], temp = n, wt[n], y[n], num = 0, ta[n], j = 0, flag = 0;
	printf("________Enter arrival time and burst time of each process________ ");
	for(i=0; i<n; i++)
	{
		printf("\nProcess No : "); 
		scanf("%d", &Pnum[i]);
		printf("\nArrival time  : ");
		scanf("%d", &at[i]);
		printf("\nBurst time   : ");
		scanf("%d", &bt[i]);
		y[i]=bt[i];
	}
	
	printf("Enter the time quantum ");
	scanf("%d", &timeq);
	for(i = 0, num = 0; temp != 0;)
	{
		if(y[i] <= timeq && y[i] > 0)
		{
			num+= y[i];
			y[i] = 0;
			flag = 1;
		}
		else if(y[i] > 0)
		{
			y[i] = timeq;
			num+= timeq;
		}
		if(flag == 1 && y[i] ==0)
		{
			num--;
			Pnum[j] = i+1;
			wt[j] = num - at[i] - bt[i];
			ta[j++] = num-at[i];
			flag = 0;
		}
		if(i ==n-1)
			i = 0;
		else if(at[i+1] <= num)
			i++;
		else 
			i = 0;
	}
	printf("Process\t   priority\t   burst time\t   T.AT\t   W.T\n");
	for(i=0; i<n; i++)
	{
		printf("%d\t%d\t\t%d\t\n",Pnum[i], wt[i], ta[i]  );
		tsum=tsum+a[i];
		wsum=wsum+a[i];
	}
	tsum = tsum/n;
	wsum = wsum / n;
	printf("\nAverage turn around = %0.2f", tsum);
	printf("\nAverage waiting time = %0.2f", wsum);
}
			 
