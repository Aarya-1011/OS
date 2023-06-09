#include<stdio.h>
#define max 25
void main()
{
	int frag[max], b[max], f[max], i, j, nb, nf, temp;
	static int bf[max], ff[max];
	printf("\n\tMemory Managemennt Scheme - First fit");
	printf("\nEnter no:of blocks");
	scanf("%d", &nb);
	printf("\nEnter no:of files");
	scanf("%d", &nf);
	printf("\nEnter of blocks in KB : ");
	for(i=0; i<nb; i++)
	{
		scanf("%d", &b[i]);
	}
	printf("Enter size of files : ");
	for(i=0; i<nf; i++)
	{
		scanf("%d", &f[i]);
	}
	for(i=0; i<nf; i++)
	{
		for(j=0;j<nb; j++)
		{
			if(bf[j]!=1)
			{
				temp=b[j]-f[i];
				if(temp>=0)
				{
					ff[i]=j;
					break;
				}
			}
		}
		frag[i]=temp;
		bf[ff[i]]=1;
	}
	printf("\nFileNo\tFile size\tBlockNo\tBlock size\tFragment");
	for(i=0; i<nf; i++)
	printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i, f[i], ff[i], b[ff[i]],frag[i]);
}
