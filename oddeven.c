#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
	int n;
	printf("Enter number limit : ");
	scanf("%d",&n);
	int oddsum=0;
	int evensum=0;
	pid_t id =fork();
	if(id>0)
	{
		printf("___Parent Prcocess___");
		printf("PID :  %d\n",getpid());
		for(int i=1;i<n;i=i+2)
			{oddssum+=i;}
		printf("sum :- %d\n",n,oddsum);
		
	}
	else if(id==0)
	{
		Printf("___Child Process___");
		printf("PID : %d\n",getpid());
		for(int i=0;i<n;i=i+2)
			{evensum+=i;}
		printf("sum :- %d\n",n,evensum);
		
	}
	else
	{
		printf("ERROR !! ERROR !!");
	}
	return 0;
}
