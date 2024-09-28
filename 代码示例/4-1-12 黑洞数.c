#include<stdio.h>

int main()
{
    int a, b, c, count, n;
    int max, mid, min, tmp;

    count = 0;
    scanf("%d", &n);
    c = n;
    if(c == 495)
    {
        printf("1: 954 - 459 = 495\n");
    }
    else
    {
        while(c != 495)
        {
            count ++;
            min = c % 10;
            mid = c % 100 / 10;
            max = c / 100;
            if(min > mid)
            {
                tmp = min;
                min = mid;
                mid = tmp;
            }
            if(min > max)
            {
                tmp = min;
                min = max;
                max = tmp;
            }
            if(mid > max)
            {
                tmp = mid;
                mid = max;
                max = tmp;
            }
            a = 100 * max + 10 * mid + min;
            b = max + 10 * mid + 100 * min;
            c = a - b;
            if(min == mid && mid == max)
            {
                printf("1:%d - %d = 0", a, b);
                break;
            }
            printf("%d: %d - %d = %d\n", count, a, b, c);
        }
    }
    

    return 0;
}
