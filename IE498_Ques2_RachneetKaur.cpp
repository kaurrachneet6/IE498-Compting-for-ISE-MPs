// Rachneet Kaur
// IE 498 HW 6 Ques 2
// Print elements with max frequency given frequency >=2
#include <iostream>
#include <list>
using namespace std;
int main()
{
	list<int> a; // List of all elements
	list<int> unique_ele;  // Taking only unique elements
	list<int> freq;    // Frequency of unique elements
	int s, n, start_size;
	cout << "\n Enter the no. of elements in the set : ";
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> s;
		a.push_back(s);
	}
	while (a.size() != 0)
	{
		start_size = a.size();
		unique_ele.push_back(a.front()); // Pushing unique element in new list
		a.remove(a.front());                // Removing all instances of this element from list
		freq.push_back(start_size - a.size()); // Now difference in size of list gives no. of times the element was repeated
	}
	int temp = freq.front();
	for (list<int>::iterator i = freq.begin(); i!= freq.end(); ++i)
		if (temp < *i) temp = *i;  // Computing Max frequency
	if (temp >= 2)              // Checking if Max frequency >=2
	{
		cout << "\nElements with Max frequency >=2 are: ";
		for (list<int>::iterator i = unique_ele.begin(); i != unique_ele.end(); ++i)
		{
			if (temp == freq.front() )       // Checking if freq. of this element is max frequency
		      cout << *i << " ";             // If yes, then printing the element
			freq.pop_front();
		}
		cout << "\n";
	}
	
	else cout << "\nNo element with frequency >=2\n ";    // If none has freq>=2, we print No element
	return 0;
}