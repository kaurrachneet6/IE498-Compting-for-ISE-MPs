// Rachneet Kaur
// IE 498 HW 11
// Merge Sort
#include <iostream>
using namespace std;

//Merging the sorted subarrays
int *Merge(int *b, int *c, int s1, int s2) // 2 arrays to merge and their sizes
{
	int i = 0, j = 0, k = 0;
	int *mer = new int[s1 + s2];    // merged array

	while (i < s1 && j < s2)
	{
		if (b[i] <= c[j])
			mer[k++] = b[i++];
		else
			mer[k++] = c[j++];
	}

	while (i < s1)
		mer[k++] = b[i++];

	while (j < s2)
		mer[k++] = c[j++];
	return mer;           // Merged Subarray
}

void MergeSort(int *a, int length)
{
	int *res;
	if (length > 1)
	{
		res = new int[length];
		int *b = new int[length / 2];    // Creating 2 subarrays of length half the length of array
		int *c = new int[length - length / 2];
		for (int i = 0; i < length / 2; i++)
			b[i] = a[i];
		for (int i = 0; i < length - length / 2; i++)
			c[i] = a[length / 2 + i];
		MergeSort(b, length / 2);  // MergeSort on left half part
		MergeSort(c, length - length / 2);  // Merge sort on right half part
		res = Merge(b, c, length / 2, length - length / 2);  // Merging the 2 sorted parts together
		for (int i = 0; i < length; i++)   // Soring the sorted array in a
			a[i] = res[i];
	}
}
int main()
{
	int *a, n;
	cout << "Enter no. of integers: ";
	cin >> n;
	a = new int[n];
	cout << "Enter integers: ";
	for (int i = 0; i<n; i++)
		cin >> a[i];
	MergeSort(a, n);
	cout << "Sorted array of integers: ";
	for (int i = 0; i<n; i++)
		cout << a[i] << " ";
	cout << "\n";
}

