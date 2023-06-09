/*#include<stdio.h>
void main()
{
	int n, m, available[10], need[10][10], allocation[10][10], max[10][10], i, j, k, p[10], work[10], finish[10], index  = 0, flag, y;
	printf("Enter no:of  resource type ");
	scanf("%d", &m);
	printf("Enter no:of process");
	scanf("%d", &n);
	printf("______Enter no:of instance of each process______");
	for(i=0; i<m; i++)
	{
		printf("\nEnter no:of instance of resource type %d : ", i+1);
		scanf("%d", &available[i]);
		work[i] = available[i];
	}
	printf("_____Enter no:of allocated instance of each process_____ ");
	for(i=0; i<n; i++)
	{
		printf("\nProcess %d ",i+1);
		for(j=0; j<m; j++)
		{
			printf("\nResource type %d ", j+1);
			scanf("%d", & allocation[i][j]);
		}		
	}
	printf("______Enter no:of max instance of each process_____");
	for(i=0; i<n; i++)
	{
		printf("\nProcess :-   %d ",i+1);
		for(j=0; j<m; j++)
		{
			printf("\nResource type %d ", j+1);
			scanf("%d", & max[i][j]);
		}	
	}
	for(i=0; i<n; i++)
	{
			finish[i] = 0;
	}
	for(i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
		{
			need[i][j] = max[i][j] - allocation[i][j];
		}
	}
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{	
			if(finish[j]==0)
			{
				flag = 0;
				for(k=0; k<m; k++)
				{
					if(need[j][k] > available[k])
					{
						flag = 1;
						break;
					}
				}
				if(flag == 0)
				{
					p[index ++] = j;
					for(y=0; y<m; y++)
					{
						available[y] += allocation[j][y];
					}
					finish[j] = 1;
				}
			}	
		}
	}
	printf("Safe sequence : ");
	for(i=0; i<n-1; i++)
	{
		printf("P%d -> ", p[i]);
	}
		printf("P%d", p[n-1]);
}*/	
#include<stdio.h>
#include<conio.h>
int max[100][100];
int alloc[100][100];
int need[100][100];
int avail[100];
int n,r;
void input();
void show();
void cal();
int main()
{
	int i,j;
	printf("********** Banker's Algorithm ************\n");
	input();
	show();
	cal();
	return 0;
}
void input()
{
	int i,j;
	printf("Enter the no of Processes\t");
	scanf("%d",&n);
	printf("Enter the no of resources instances\t");
	scanf("%d",&r);
	printf("Enter the Max Matrix\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<r;j++)
		{
			scanf("%d",&max[i][j]);
		}
	}
	printf("Enter the Allocation Matrix\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<r;j++)
		{
			scanf("%d",&alloc[i][j]);
		}
	}
	printf("Enter the available Resources\n");
	for(j=0;j<r;j++)
	{
		scanf("%d",&avail[j]);
	}
}
void show()
{
	int i,j;
	printf("Process\t Allocation\t Max\t Available\t");
	for(i=0;i<n;i++)
	{
		printf("\nP%d\t ",i+1);
		for(j=0;j<r;j++)
		{
			printf("%d ",alloc[i][j]);
		}
		printf("\t");
		for(j=0;j<r;j++)
		{
			printf("%d ",max[i][j]);
		}
		printf("\t");
		if(i==0)
		{
			for(j=0;j<r;j++)
				printf("%d ",avail[j]);
		}
	}
}
void cal()
{
	int finish[100],temp,need[100][100],flag=1,k,c1=0;
	int safe[100];
	int i,j;
	for(i=0;i<n;i++)
	{
		finish[i]=0;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<r;j++)
		{
			need[i][j]=max[i][j]-alloc[i][j];
		}
	}
	printf("\n");
	while(flag)
	{
		flag=0;
		for(i=0;i<n;i++)
		{
			int c=0;
			for(j=0;j<r;j++)
			{
				if((finish[i]==0)&&(need[i][j]<=avail[j]))
				{
					c++;
					if(c==r)
					{
						for(k=0;k<r;k++)
						{
							avail[k]+=alloc[i][j];
							finish[i]=1;
							flag=1;
						}
						printf("P%d->",i);
						if(finish[i]==1)
						{
							i=n;
						}
					}
				}
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if(finish[i]==1)
		{
			c1++;
		}
		else
		{
			printf("P%d->",i);
		}
	}
	if(c1==n)
	{
		printf("\n The system is in safe state");
	}
	else
	{
		printf("\n Process are in dead lock");
		printf("\n System is in unsafe state");
	}
}
