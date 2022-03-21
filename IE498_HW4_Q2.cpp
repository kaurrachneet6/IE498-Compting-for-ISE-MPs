// Rachneet Kaur
// IE 498 HW 4 Ques 2
// Reversing an Integer
#include<iostream>
using namespace std;
int reverse(int n);    // Reversing an integer function
int main()
{
	int n;
	cout << "Enter an integer: ";
	cin >> n;
	cout << "Reverse of " << n << " is " << reverse(n)<<"\n";
	return 0;
}
int reverse(int n)
{
	int rev = 0, r; // rev - Reversed Integer of n, r - Remainder
	while (n != 0)
	{
		r = n % 10;    // Taking digits in reverse order
		rev = rev * 10 + r;  // Creating the reversed integer
		n = n / 10;
	}
	return rev; 
	}