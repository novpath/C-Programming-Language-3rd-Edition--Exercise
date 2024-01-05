#include<stdio.h>

int main()
{
    int m, n;
    int sum, flag, fac_count, count;
    
    scanf("%d %d", &m, &n);
    count = 0;
    for(int i = m; i <= n; i ++)
    {
        sum = 0;
        flag = 0;
        fac_count = 0;
        for(int j = 1; j <= i / 2; j ++)
        {
            if(i % j == 0)
            {
                sum += j;
                fac_count ++;
            }

        }
        if(sum == i)
        {
            flag = 1;
            count ++;
        }
        if(flag == 1)
        {
            printf("%d =", i);
            for(int k = 1; k <= i / 2; k ++)
            {
                if(i % k == 0)
                {
                    printf(" %d", k);
                    fac_count --;
                    if(fac_count >= 1)
                	{
                		printf(" +", k);
					}
					else
					{
						printf("\n");
						break;
					}
                }
            }
        }
    }
    
    if(count == 0)
    {
    	printf("None\n");
	}

    return 0;
}
