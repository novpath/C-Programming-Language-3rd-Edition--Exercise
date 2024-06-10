#include<stdio.h>

void insert(double a[], int *n, double x, int i);

int main()
{
	int *n = NULL;
	int num, x, pos;
	scanf("%d", &num);
	n = &num;
	double a[num + 1];

	for(int i = 0; i < num; i ++)
	{
		scanf("%lf", &a[i]);
	}
	for(int i = 0; i < num; i ++)
	{
		printf("%.0f ", a[i]);
	}
	printf("\nPlease input insert factor x and the insert position i:");
	scanf("%d %d", &x, &pos);
	insert(a, n, x, pos);
	for(int i = 0; i < num; i ++)
	{
		printf("%.0lf ", a[i]);
	}
	
	return 0;
}

void insert(double a[], int *n, double x, int i)
{
	int j;
	if(i < *n)
		for(j = *n - 1; j >= i; j--)
			a[j + 1] = a[j];
	else
		i = *n;
	a[i] = x;
	(*n) ++;
}
