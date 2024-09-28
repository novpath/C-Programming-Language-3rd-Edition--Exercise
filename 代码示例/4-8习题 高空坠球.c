#include<stdio.h>
typedef long long ll;

int main()
{
    ll h, n;
    int count;
    double s, ns, t;

    scanf("%lld %lld", &h, &n);
    
    if(n == 0)
    {
    	s = 0;
    	ns = 0;
	}
	else
	{
		s = h;
		ns = h / 2.0;
		for(int i = 1; i < n; i ++)
    	{
	        s += 2 * ns;
	        ns /= 2;
    	}
	}

    printf("%.1f %.1f\n", s, ns);

    return 0;
}
