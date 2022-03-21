// Rachneet Kaur
// IE 498 HW 5 Ques 2
// If sum of Prime factors of no. is Prime
#include<iostream>
#include<cmath>
using namespace std;
bool isPrime(int n);
int sum_prime_divisors(int n);
int main()
{
	cout << "No.s whose sum of prime divisors is a prime no. are: \n";
	for (int i = 2; i <= 1000; i++)
		if (isPrime(sum_prime_divisors(i)))
			cout << i << " ";
	cout << "\n";
	return 0;
}
bool isPrime(int n)
{
	for (int j = 2; j <= sqrt(n); j++)
		if (n%j == 0) return false;
	return true;
}
int sum_prime_divisors(int n)
{
    if (isPrime(n)) return n;
	for(int i=2;i<=sqrt(n);i++)
	if ((n%i == 0)&&isPrime(i))
		return i + sum_prime_divisors(n / i);
}