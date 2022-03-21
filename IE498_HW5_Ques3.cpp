// Rachneet Kaur
// IE 498 HW 5 Ques 3
// Interval Scheduling Algorithm

#include<iostream>
#include<fstream>
using namespace std;
bool * IntervalScheduling(int *s, int *f, int n);
void swap(int *a, int *b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}
int main()
{
	int no_int,*s,*f; // no_int - No. of intervals, s- Start times array, f - End times array
	bool *output;    // Output boolean array containg 1 if interval is selected else 0
	ifstream f1;     // File to read data
	f1.open("input-scheduling.txt");
	f1 >> no_int;    // No of intervals
	s = new int [no_int];
	f= new int [no_int];
	output = new bool[no_int];
	for (int i = 0; i < no_int; i++)     // Reading intervals from file
		f1 >> *(s + i) >> *(f + i);
	f1.close();
	output = IntervalScheduling(s, f, no_int);
	delete[]s;
	delete[]f;
	cout << "\nAccepted Intervals are:\n";
	for (int i = 0; i < no_int; i++)
		if (*(output + i)) cout << i + 1 << "\n";
	delete[]output;
	return 0;
}
bool * IntervalScheduling(int *s, int *f, int n)
{
	bool *output = new bool[n];
	int *index = new int[n];
	int i,temp;
	for (i = 0; i < n; i++) index[i] = i;     // Index for the particular interval
    // s and f are sorted according to the finishing time in increasing order
	for (i = 0; i < n - 1; i++)
		for (int j = 0; j < n - 1 - i; j++)

		{
			if (f[j] > f[j + 1])                    // Sorting according to finishing time in increasing order
			{
				swap(&index[j], &index[j + 1]);  // Swapping the index as well to keep track of interval no.s
				swap(&f[j], &f[j + 1]);
				swap(&s[j], &s[j + 1]);
			}
		}
	i = 0;
	while (i < n)
	{
		output[index[i]] = true;
		temp=f[i];
		i++;
		while ((s[i] < temp) && (i < n))   // Intervals not compatible with the selected one
		{
			output[index[i]] = false;
			i++;
		}
	}
	return output;

}