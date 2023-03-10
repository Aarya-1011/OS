#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
	int n;
	printf("Enter number limit : ");
	scanf("%d",&n);
	int odds=0;
	int evens=0;
	pid_t id =fork();
	if(id>0)
	{
		for(int i=1;i<n;i=i+2)
			{odds+=i;}
		printf("sum of odd numbers till %d is %d\n",n,odds);
		printf("PID of parent process is %d\n",getpid());
	}
	else if(id==0)
	{
		for(int i=0;i<n;i=i+2)
			{evens+=i;}
		printf("sum of odd numbers till %d is %d\n",n,evens);
		printf("PID of child process is %d\n",getpid());
	}
	else
	{
		printf("failed");
	}
	return 0;
}
