// Rachneet Kaur
//IE498 HW2 Ques 2
// Displaying Triangular No.s from n = 10 to n = 25
#include<iostream>
using namespace std;
int main()
{
	for (int n = 10; n <= 25; n++)                            // We need sum of first n positive integers for n=10 to 25
		cout << "T(" << n << ") =" << n*(n + 1)/2 << "\n";  // Sum of first n positive integers is T(n) = n(n+1)/2
	return 0;
}