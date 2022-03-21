// Rachneet Kaur
// IE 498 HW 3 Ques 3
// Generate a coin toss
#include<iostream>
#include <ctime>
using namespace std;
void coinToss();
int main()
{
	int n;
	cout << "Enter no. of coin tosses: "; cin >> n;    // Taking the number of tosses
	srand(time(0));                                    // To generate a different random no. each time
	cout << "Results of " << n << " tosses are: ";
	for (int i = 1; i <= n; i++)
		coinToss();                                   // Running a coin toss n no. of times
	cout << "\n";
	return 0;
}
void coinToss()
{
	int x = 1+rand() % 2;                            // Random integer between 1 and 2
	if (x == 1)cout << "\nHeads";                    // If random no. is 1 then Heads else Tails
	if (x == 2) cout << "\nTails";
}