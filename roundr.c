#include<stdio.h>
int q[50], f=-1, r = -1;
void insert(int n)
{
	if(f == -1)
	f = 0;
	r = r+1;
	q[r] = n;
}
int delete()
{
	int n;
	n = q[f];
	f = f+1;
	return n;
}
int main()
{
	int p, tq, n, i, t = 0;
	float twt = 0, ttat = 0;
	printf("no:of Process : ");
	scanf("%d", &n);
	int a[n][5], bt[10], exist[10]={0};
	printf("arrival time and burst time \n");
	for(i=0;i<n;i++)
	{
		printf("\nProcess No : "); 
		scanf("%d", &a[i][0]);
		printf("\nArrival time  : ");
		scanf("%d", &a[i][1]);
		printf("\nBurst time   : ");
		scanf("%d", &a[i][2]);
		bt[i]=a[i][2];
	}
	printf("time quantum");
	scanf("%d", &tq);
	insert(0);
	exist[0]=1;
	while(f<=r)
	{
		p=delete();
		if(a[p][2]>=tq)
		{
			a[p][2]=a[p][2]-tq;
			t=t+tq;
		}
		else
		{
			t=t+a[p][2];
			a[p][2]=0;
		}
		for(i=0;i<n;i++)
		{
			if(exist[i]==0 && a[i][1]<=t)
			{
				insert(i);
				exist[i]=1;
			}
		}
		if(a[p][2]==0)
		{
			a[p][4]=t-a[p][1];
			a[p][3]=a[p][4]-bt[p];
			ttat=ttat+a[p][4];
			twt=twt+a[p][3];
		}
		else
			insert(p);
	}
	printf("Process\t   priority\t   burst time\t   T.AT\t   W.T\n");
	for(i=0; i<n; i++)
	{
		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\n", a[i][0],a[i][1],bt[i],a[i][4],a[i][3]);
	}
	ttat=ttat/n;
	twt=twt/n;
	printf("Avg turn around : %f", ttat);
	printf("Avg waiting time : %f", twt);
}
