#include<stdio.h>
#include<math.h>
typedef long long ll;

int isprime(ll x)
{
    int ret = 1;
    for(int i = 2; i <= sqrt(x); i ++)
    {
        if(x % i == 0)
        {
            ret = 0;
            break;
        }
    }

    return ret;
}


int main()
{
    ll n;
    
	scanf("%lld", &n);
    for(ll i = 2; i <= n / 2; i ++)
    {
           if(isprime(i) && isprime(n - i))
           {
               printf("%lld = %lld + %lld", n, i, n - i);
               break;
           }
    }

    return 0;
}
