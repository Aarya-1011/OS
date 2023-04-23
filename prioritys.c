#include<stdio.h>
void swap(*int b, int *c)
{
    int temp;
    temp = *c;
    *c = *b;
    *b = temp;
}
int main()
{
    int i, j, n;
    float tsum = 0, wsum = 0;
    printf("Enter number of processess : ");
    scanf("%d", &n);
    int a[n][6];
    
