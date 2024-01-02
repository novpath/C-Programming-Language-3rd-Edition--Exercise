#include<stdio.h>

int main(void)
{
	int i, m;
	
	printf("Enter a number:");
	scanf("%d", &m);
	
	for(i = 2; i <= m / 2; i ++)
		if(m % i == 0) printf("No!\n");
		else printf("%d is a prime number!\n", m);

	return 0;
}
