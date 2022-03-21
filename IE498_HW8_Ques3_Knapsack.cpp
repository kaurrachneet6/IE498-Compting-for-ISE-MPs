//Rachneet Kaur
// IE 498 HW 8 Ques 3
// Knapsack Problem

#include<iostream>
#include<fstream>
using namespace std;
int Knapsack(int *v, int *w, int j, int cap, int **Sol)
{
	int **K = new int *[j + 1]; //  K[j][cap] = Optimal value of Knapsack with j items and weight capacity cap
	for (int i = 0; i < j + 1; i++)
		K[i] = new int[cap + 1];

	for (int i = 0; i <= j; i++)
	{
		for (int m = 0; m <= cap; m++)
		{
			if (i == 0 || m == 0)
				K[i][m] = 0;
			else if (w[i] <= m)
			{
				if (v[i] + K[i - 1][m - w[i]] > K[i - 1][m])  // To decide if ith item must be added to the Knapsack or not
				{
					K[i][m] = v[i] + K[i - 1][m - w[i]];     // If yes, we update the value of Knapsack and Sol becomes 1
					Sol[i][m] = 1;                           // Sol[i][m] = 1 if ith item is picked with knapsack capacity m
				}
				else
					K[i][m] = K[i - 1][m];                   // Else Sol is 0 and Knapsack value remains the same
			}
			else
				K[i][m] = K[i - 1][m];                      // Case when weight of item i > Knapsack capacity m
		}
	}
	return K[j][cap];                                      // Optimal value of Knapsack with j items and capacity cap
	delete K;
}
int main()
{
	int n, W;                                           // n - Total no. of items, W - Total Weight of Knapsack
	ifstream f1("input.txt");
	f1 >> n >> W;   // No. of items and Total Weight
	int *v = new int[n + 1];      // Values array
	int *w = new int[W + 1];      // Weights array
	int **Sol = new int *[n + 1];   // 0 and 1's array with Sol[i][m]=1 if item i is selected with Knapsack capacity m
	for (int i = 0; i < n + 1; i++)
		Sol[i] = new int[W + 1];
	for (int i = 1; i <= n; i++)
		f1 >> w[i] >> v[i];              // Reading weights and values from input.txt
	for (int i = 0; i < n + 1; i++)
		for (int j = 0; j < W + 1; j++)
			Sol[i][j] = 0;              // Initially, taking all Sol values as 0

	cout << "Optimal Value = " << Knapsack(v, w, n, W, Sol) << endl;
	cout << "Items to pick: ";
	while ((n != 0) && (W != 0))
	{
		if (Sol[n][W] == 1)
		{
			cout << n << " ";
			W = W - w[n];
			n--;
		}
		else
			n--;
	}
	cout << endl;
	return 0;
}
