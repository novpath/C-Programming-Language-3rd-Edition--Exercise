#include<stdio.h>

int main()
{
    int i, j, n; 
	scanf("%d", &n);
	for (i = n; i > 0; i --)
    {
    	for (j = n - i; j > 0; j --) 
    	{
        	printf (" ");
    	}     
    	for (j = 2 * i - n; j > 0; j --)
    	{
        	printf ("*");
    	}     
    	printf ("\n");
	}
    
    return 0;
}
