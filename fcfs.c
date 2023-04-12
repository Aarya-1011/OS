#include<stdio.h>
int main()
{
	int i, n; 
	float tsum=0, wsum=0;
	printf("Enter number of processes : ");
	scanf("%d", &n);
	int a[n][5];
	
	printf("________Enter arrival time and burst timeof each process________ ");
	for(i=0; i<n; i++)
	{
		printf("\nArrival time of process %d : ",i);
		scanf("%d", &a[i][1]);
		printf("\nBurst time of process %d : ",i);
		scanf("%d", &a[i][2]);
	}
	a[0][3]=a[0][2];
	for(i=1; i<n; i++)
	{
		a[i][3]=a[i-1][3]+a[i][2];
	}
	for(i=0; i<n; i++)
	{
		a[i][4]=a[i][3]-a[i][1];
		a[i][5]=a[i][4]-a[i][2];
	}
	printf("Process\t   arrival time\t   burst time\t   T.AT\t   W.T\n");
	for(i=0; i<n; i++)
	{
		printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t\n",i, a[i][1],a[i][2],a[i][4],a[i][5]);
		tsum=tsum+a[i][4];
		wsum=wsum+a[i][5];
	}
	wsum = wsum / n;
	printf("\nAverage turn around = %0.2f", tsum);
	printf("\nAverage waiting time = %0.2f", wsum);
}
	
