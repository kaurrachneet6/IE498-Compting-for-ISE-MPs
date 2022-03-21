#include<iostream>
#include<vector>
using namespace std;
vector <int> prime_factors;

bool isPrime(int n) {
	if (n == 1) {
		return false;
	}
	for (int i = 2; i<n; i++) {
		if (n%i == 0) {
			return false;
		}
	}
	return true;
}

int prime_divisor(int n)
{
	if (n == 1) return 0;
	else if (isPrime(n)) return n;
	else
	{
		for (int i = 2; i <= n; i++)
		{
			if (n%i == 0)
			{
				if (isPrime(i))
				{
					return( i+ prime_divisor(n / i));
				}
			}
		}
	}

}
int main()
{
	int count = 0;
	for(int n=2;n<=1000;n++)
		if (isPrime(prime_divisor(n))) {
			cout << n << " "; count++;
		}
	cout << "\n Total =" << count;
	return 0;
}