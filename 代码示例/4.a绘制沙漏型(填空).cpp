#include<stdio.h>

int main()
{
    int i, j, m, n; 
    scanf("%d", &n);
	m = n / 2;
	for(i = (n / 2 + 1); i >= 1; i --)
    {
    	for(j = 1; j <= (n - 2 * i + 1)/2; j ++)
        {
            printf(" ");
        }
        for(j = 1; j <= 2 * i - 1; j ++)
        {
            printf("*");
        }
            printf("\n");
    }
    
	for(i = 2; i <= (n / 2) + 1; i ++)
    {
    	for(j = 1; j <= (n - 2 * i + 1)/2; j ++)
        {
            printf(" ");
        }
        for(j = 1; j <= 2 * i - 1; j ++)
        {
            printf ("*");
        }
        printf("\n");
    }

    return 0;
}
