//Rachneet Kaur
//IE498 HW2 Ques 4
// Sum and product of digits of entered integer
#include<iostream>
using namespace std;
int main()
{
	int n, r, sum = 0, prod = 1;
	cout << "Enter a number: ";
	cin >> n;
	while (n != 0)     // Until we have extracted all the digits of the number
	{
		r = n % 10;   // Computing the digits by taking remainder with 10
		n = n / 10;   // Dividing the number by 10, one's a digit is taken
		sum += r;    // Sum of digits
		prod *= r;   // Product of digits
	}
	cout << " Sum is " << sum << " and product is " << prod<<"\n";
	return 0;
}