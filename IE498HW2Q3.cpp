//Rachneet Kaur
//IE498 HW2 Ques 3
// Check if Leap Year or not
#include<iostream>
using namespace std;
int main()
{   
	int n, k=0;                                         // k=0 if non leap year, k=1 if leap year
	cout << " Enter the year to be tested: ";
	cin >> n;                                          // n - Year to be checked
	if (n % 4 == 0)                                   // If n is not divisible by 4, it's definitely not leap 
	{
		if (n % 100 != 0) k = 1;                      // If it's divisible by 4 and not by 100, it's leap
		else if (n % 400 == 0) k = 1;                // If it's divisible by 4 and 100, it's leap only when it's divible by 400
	}
	if (k == 1) cout << n << " is a leap year.\n";
	else cout << n << " is not a leap year.\n";
	return 0;
}