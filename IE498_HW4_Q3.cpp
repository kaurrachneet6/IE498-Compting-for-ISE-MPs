// Rachneet Kaur
// IE 498 HW 4 Ques 3
// Lottery
#include<iostream>
#include <ctime>
using namespace std;
int main()
{
	int user[5], lottery[5], count =0;  // user - array entered by user, lottery - array created by lottery method
	srand(time(0));               // Random no. generator seed setting by time
	cout << " Enter 5 integers: ";
	for (int i = 0; i < 5; i++)
	{
		cin >> user[i];
		lottery[i] = rand() % 10;      // Generating a random no. between 0 and 9
	}
	cout << "\nUser entered array is: ";
	for (int i = 0; i < 5; i++)
		cout << user[i] << " ";
	cout << "\nLoterry no.s are: ";
	for (int i = 0; i < 5; i++)
	{
		cout << lottery[i] << " ";
		if ((user[i] - lottery[i]) <= 1 && (user[i] - lottery[i]) >= -1) // Checking if absolute difference between 2 no.s <=1
			count++;                         // No. of enteries with absolute difference <=1
	}
		cout << "\n";
		cout << "\nNo. of matching no.s are: " << count << "\n";
		if (count == 5) cout << " Congrats! You won a big brize!\n";
	return 0;
}