// Rachneet Kaur
// IE 498 HW 7
// Question 3
// Rod Cutting Problem 
#include<iostream>
#include<fstream>
using namespace std;
int *RodCut(int *p, int n)
{
	int q;   // Temporary variable
	int *cut = new int[n+1], *r = new int[n + 1]; // cut[i] stores the optimal first cut and r[i] stores the optimal revenue for piece of length i
	r[0] = 0;   
	for (int j = 1; j <= n; j++)
	{
		q = INT_MIN;                      // q = -infinity
		for (int i = 1; i <= j; i++)
			if (q < (p[i] + r[j - i]))  // Optimal revenue r[j]= Max(p[i]+r[j-i]) for i =1 to j
			{
				q = p[i] + r[j - i];     // p - price vector
				cut[j] = i;             // The point at which we get max revenue decides the first cut position
			}
		r[j] = q;                      // r - revenue vector
	}
	cout << " \nOptimal Revenue = " << r[n] << "\n";
	return cut;                      // Optimal first cut vector 
}
int main()
{
	ifstream file("input.txt");
	int n;
	file >> n;
	int Optimal_Revenue =0;    // Optimal Revenue using prices in p and length of rod n
	int *p = new int[n+1],*cut;
	for (int i = 1; i <= n; i++)      // Reading price vector from the file
	{
		file >> p[i];
	}
	cut = RodCut(p, n);   // Optimal first cuts
	cout << "Pieces to sell: ";
	for (int i = n; i > 0; i = i - cut[i])
		cout << cut[i] << " ";                // Pieces to sell
	cout << "\n";
	return 0;
}