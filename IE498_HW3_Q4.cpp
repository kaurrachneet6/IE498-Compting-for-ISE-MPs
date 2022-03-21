// Rachneet Kaur
// IE 498 HW 3 Ques 4
// Displaying a no. in English
#include<iostream>
using namespace std;
void no2english(int n);      // Function prototype
int main()
{
	int n;                   // n= Integer to be spelled in English
	cout << "Enter an integer: ";
	cin >> n;
	no2english(n);          // Function call
	cout << "\n";
	return 0;
}
void no2english(int n)     // Recurssive function to print english word for each digit of n
{
	char eng[10][10] = { "Zero ", "One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine " };
	if (n/10 != 0) no2english(n/10);      // We need to print from first to last digit so we reccurse first and then print
	cout<<eng[n%10];                     // Printing the remainder after recussing 
}