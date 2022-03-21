// Rachneet Kaur
//IE498 HW2 Ques 1
// Asking for integer until it is divisible by 5 or 11
#include<iostream>
using namespace std;
int main()
{
	int n; 
	do                                    // Since it must run once and terminate only when n is divisible by 5 or by 11
	{
		cout << "Enter an integer: ";
		cin >> n;

	} 
	while ((n % 5 != 0) && (n % 11 != 0)); // We keep on entering an integer until it is either divisible by 5 or by 11
	return 0;
}