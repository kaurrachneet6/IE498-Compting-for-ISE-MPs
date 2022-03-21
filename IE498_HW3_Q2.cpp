// Rachneet Kaur
// IE 498 HW 3 Ques 2
// Square each element of array and reverse the array
#include<iostream>
using namespace std;
void squareNreverse(int a[], int s); // Function prototypes
void swap(int &a, int &b);           // To reverse the array, we will use the swap function
int main()
{
	int a[5];
	cout << "Enter 5 elements: \n";
	for (int i = 0; i < 5; i++) cin >> a[i];             // Input the array 
	squareNreverse(a, 5);                              // Calling the function
	cout << "\nThe array Squared and Reversed is: \n";
	for (int i = 0; i < 5; i++) cout << a[i] << " ";  // Output the array
	cout << "\n";
	return 0;
}
void squareNreverse(int a[], int s)
{
	for (int i = 0; i < s; i++) a[i] = a[i] * a[i];               // Squaring every element of array
	for (int i = 0; i < s/2; i++) swap(a[i], a[s - 1 - i]);	     // Reversing the array by swapping first half of list with remaining half
}
void swap(int &a,int &b)  // Function to swap 2 numbers
{
	int t;
	t = a;
	a =b;
	b = t;
}