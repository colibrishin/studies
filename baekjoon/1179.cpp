#include <iostream>

long long josep(long long n, int k)
{
	if(n == 1)
	{
		return 0;
	}
	if(k == 1)
	{
		return n - 1;
	}
	else if(n > 1 && n < k)
	{
		return (josep(n - 1, k) + k) % n;
	}

	long long remainder = n / k;
	long long result = josep(n - remainder, k) - n % k;

	if(result < 0)
	{
		return result + n;
	}

	return result + result / (k - 1);
}


int main()
{
	long long n;
	std::cin >> n;

	int k;
	std::cin >> k;

	std::cout << josep(n, k) + 1;
}
