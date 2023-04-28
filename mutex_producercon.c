#include<stdio.h>
int mutex = 1;
int full = 0, empty = 5, x = 0;
void producer()
{
	--mutex;
	++full;
	--empty;
	x++;
	printf("\nProducer produces the item %d", x);
	++mutex;
}
void consumer()
{
	--mutex;
	--full;
	++empty;
	printf("\nConsumer consumes the item %d", x--);
	++mutex;
}
int main()
{
	int ch;
	while(ch != 3)
	{
		printf(" \n 1. Producer\n 2. Consumer\n 3. Exit\n");
		printf("\nEnter your choice : ");
		scanf("%d", &ch);
		switch (ch)
		{
			case 1:
			{
				if((mutex == 1) && (full != 5))
					producer();
				else
					printf("\nBuffer is FULL\n");
				break;
			}
			case 2:
			{
				if((mutex == 1) && (empty != 5))
					consumer();
				else
					printf("\nBuffer is EMPTY\n");
				break;
			}
			case 3:
				break;
			default:
				printf("\nInvalid Choice!!!");
		}
	}
	return 0;
}
