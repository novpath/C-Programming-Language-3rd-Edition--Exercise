#include<stdio.h>

int main()
{
    int speed, limit;
    scanf("%d %d", &speed, &limit);
	double q;
	
    q = 1.0 * (speed - limit) / limit;

    if(q < 0.1)
        printf("OK\n");
    else if(q >= 0.1 && q < 0.5)
        printf("Exceed %.f%%. Ticket 200", 100 * q);
    else
        printf("Exceed %.f%%. License Revoked", 100 * q);

    return 0;
}
