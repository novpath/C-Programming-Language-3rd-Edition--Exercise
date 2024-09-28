#include<stdio.h>
#include<math.h>

int main()
{
    int n;
    int blank, count;

    scanf("%d", &n);
    for(int i = 1; i <= n; i ++)
    {
        blank = 2 * fabs(n / 2 + 1 - i);
        count = 0;
       for(int j = 1; j <= n; j ++)
       {
           if(blank > 0)
           {
               printf(" ");
               blank --;
           }
           else if(blank == 0)
           {
               printf("* ");
               count ++;
           }
           if(count == (n - 2 * fabs(n / 2 + 1 - i)))
           {
               printf("\n");
               break;
           }
       }
    }

    return 0;
}
