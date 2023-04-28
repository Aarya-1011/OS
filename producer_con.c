#include<stdio.h>
int counter = 0, in = 0, out = 0, buffer_size  =10;
int buffer[5];
void producer()
{
	int produced = 0;
	while(counter == buffer_size)
		buffer[in] = ++produced;
	in = (in +1 ) % buffer_size;
	counter++;
}
void consumer()
{
	int consumed ;
	while(counter == 0)
		consumed = buffer[out];
	out = (out +1 )% buffer_size;
	counter--;
}
int main()
{
	int ch, x;
	while(ch != 3)
	{
		printf(" \n 1. Producer\n 2. Consumer\n 3. Exit\n");
		printf("\nEnter your choice : ");
		scanf("%d", &ch);
		switch (ch)
		{
			case 1:
			{
				if(counter == buffer_size)
					printf("\nBuffer is FULL\n");
				else
				{
					printf("\nProducer produces the item %d\n", ++x);
					producer();
				}
				break;
			}
			case 2:
			{
				if(counter == 0)
					printf("\nBuffer is EMPTY\n");
				else
				{
					printf("\nConsumer consumes the item %d\n", x--);
					consumer();
				}
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
