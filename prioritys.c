#include<stdio.h>
void swap(int *b, int *c)
{
	int temp;
	temp=*c;
	*c=*b;*b=temp;
}
int main()
{
	int i, n, j; 
	float tsum=0, wsum=0;
	printf("Enter number of processes : ");
	scanf("%d", &n);
	int a[n][6];
	
	printf("________Enter priority and burst time of each process________ ");
	for(i=0; i<n; i++)
	{
		printf("\nPriority of process %d : ",i);
		scanf("%d", &a[i][6]);
		printf("\nBurst time of process %d : ",i);
		scanf("%d", &a[i][2]);
	}
	for(i=0; i<n-1; i++)
	{
		for(j=0; j<n-i-1; j++)
		{
			if(a[j][1]<a[j+1][1])
			{
				swap(&a[j][0], &a[j+1][0]);
				swap(&a[j][6], &a[j+1][6]);
				swap(&a[j][2], &a[j+1][2]);
			}
		}
	}
	a[0][3]=a[0][2];
	for(i=1; i<n; i++)
	{
		a[i][3]=a[i-1][3]+a[i][2];
	}
	for(i=0; i<n; i++)
	{
		a[i][4]=a[i][3];
		a[i][5]=a[i][4]-a[i][2];
	}
	printf("Process\t   priority\t   burst time\t   T.AT\t   W.T\n");
	for(i=0; i<n; i++)
	{
		printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t\n",i, a[i][1],a[i][2],a[i][4],a[i][5]);
		tsum=tsum+a[i][4];
		wsum=wsum+a[i][5];
	}
	tsum = tsum / n;
	wsum = wsum / n;
	printf("\nAverage turn around = %0.2f", tsum);
	printf("\nAverage waiting time = %0.2f", wsum);
}
	
