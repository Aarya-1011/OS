#include<stdio.h>
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
}	
