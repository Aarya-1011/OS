#include<stdio.h>
#include<stdlib.h>
void fcfs(int[], int, int);
void main()
{
	int n, i, ihead;
	printf("--------FCFS Disk Schedullimg-------");
	printf("\nNo: of request : ");
	scanf("%d", &n);
	int req[n];
	printf("Enter  the sequence : ");
	for(i = 0; i<n; i++)
		scanf("%d", &req[i]);
	printf("Initial Head : ");
	scanf("%d", &ihead);
	fcfs(req, ihead, n);
}
void fcfs(int p[], int ihead, int n)
{
	int i, total = 0;
	for(i=0; i<n; i++)
	{
		total = total + abs(p[i] - ihead);
		ihead = p[i];
	}
	printf("Total head movement = %d", total);
}
