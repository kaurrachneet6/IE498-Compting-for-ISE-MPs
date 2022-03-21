// Rachneet Kaur
// IE 498 HW 4 Ques 4
// Merge sorted arrays and sort
// We will take 2 sorted arrays, both in increasing order and merge into an array sorted again in increasing order
#include<iostream>
using namespace std;
int *MergeArrays(int *a, int *b, int sizea, int sizeb);  // Function Prototype
int main()
{
	int n1, n2;                      // n1 and n2 are lengths of arrays a and b resp.
	cout << "\nEnter size of array 1: ";
	cin >> n1;
	int *a = new int[n1];           //  a, b - 2 sorted arrays in increasing order
	cout << "\nEnter array 1: ";
	for (int i = 0; i < n1; i++) cin >> *(a + i);
	cout << "\nEnter size of array 2: ";
	cin >> n2;
	int *b = new int[n2], *c;      // c- merged array
	cout << "\nEnter array 2: ";
	for (int i = 0; i < n2; i++) cin >> *(b + i);
	cout << "\nMerged Sorted array is: ";
	c = MergeArrays(a, b, n1, n2);   // Returning the pointer to merged array
	delete[]a;                      // Deleting the heap memory
	delete[]b; 
	for (int i = 0; i < n1 + n2; i++) cout << *(c + i) << " ";        // Printing the merged sorted array
	cout << "\n";
	delete[] c;                      
	return 0;
}
int *MergeArrays(int *a, int *b, int sizea, int sizeb)
{
	int *c = new int[sizea+sizeb], i = 0, j = 0, k = 0;
	while (i < sizea&&j < sizeb)                  // Run until Min(sizea, sizeb)
	{
		if (*(a + i) < *(b + j))                  // Sorting while merging in increasing order
			*(c + k++) = *(a + i++);
		else
			*(c + k++) = *(b + j++);
	}
	while(i<sizea)
		*(c + k++) = *(a + i++);                 // Copy the remaining elements of the longer array
	while(j<sizeb)
		*(c + k++) = *(b + j++);
	return c;                                    // Returning the pointer to merged sorted array
}