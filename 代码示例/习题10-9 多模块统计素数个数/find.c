int prime(int a)
{
	int isprime = 1;
	if(a <= 1)
	{
		isprime = 0;
	}
	else
	{
		for(int i = 2; i <= a / 2; i ++)
		{
			if(a % i == 0)
			{
				isprime = 0;
				break;
			}
		}
	}

	return isprime;
}
