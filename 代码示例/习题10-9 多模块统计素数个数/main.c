#include<stdio.h>
#include "find.c"

int main()
{
	int a, n, cnt;
	
	cnt = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++)
	{
		scanf("%d", &a);
		if(prime(a) == 1)
			 cnt ++;
	}
	printf("%d\n", cnt);
	
	return 0;
}
