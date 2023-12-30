#include<stdio.h>
#include<math.h>
int main()
{
    double x = 0;
    double result = 0;
    scanf("%lf", &x);

    if(x < 0)
        result = (x + 1) * (x + 1) + 2 * x + 1 / x;
    else
        result = sqrt(x);

    printf("f(%.1f) = %.3f\n", x, result);

    return 0;
}

