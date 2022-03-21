//Rachneet Kaur
// IE 498 HW 6 Ques 3
// Checking if the given graph is bipartite or not
// Not Bipartite if there is no edge between nodes of the same level in BFS Tree for all connected components

#include <iostream>
#include <fstream>
#include <queue> 
using namespace std;

int * BFS(int **G, int n, int s, int *dist)    // Breadth first search
{
	int i, l = 0;   // l -level of BFS Tree
	bool *explored = new bool[n];
	for (i = 0;i < n;i++)
		explored[i] = false;
	dist[s] = l;
	explored[s] = true;

	queue<int> q;
	q.push(s);

	while (!q.empty())
	{
		int u = q.front();
		if (dist[u] == l) l++;
		q.pop();
		for (i = 0;i < n;i++)
		{
			if ((G[u][i] == 1) && (explored[i] == false))
			{
				explored[i] = true;
				dist[i] = l;
				q.push(i);
			}
		}
	}
	return dist;
}

bool isBipartite(int **G, int n)   // To check if Graph G is bipartite or not
{
	int *dist = new int[n];
	for (int i = 0;i < n;i++)
		dist[i] = -1;
	int s = 0;    // Starting BFS with 0th node
	int c = 1;
	while (c != 0)    // c=0 when all connected components of the graph are travered and made a BFS Tree of them
	{
		dist = BFS(G, n, s,dist);  // Getting the new levels after running BFS
		for (int i = 0;i < n;i++)
		{
			for (int j = 0;j < n;j++)
				if (dist[i] == dist[j] && G[i][j] == 1 && dist[i] != -1) // If 2 nodes on the same level have an edge between them
					return false;  // Then Not Bipartite
		}
		c = 0;
		for (int i = 0;i < n;i++)
			if (dist[i] == -1)  // If some nodes are left to be assigned to BFS Tree, meaning they are in new connected component
			{
				c++; s = i;  // c - count that some nodes are not yet discovered, and we need to run BFS again on unsearched node s
			}
	}
	return true;       // If none of the connected components' BFS tree has edge between 2 nodes at same level, hence bipartite
}

int main()
{
	ifstream in_file("input-graph.txt");
	int n, i, j, s;
	in_file >> n;// No. of  nodes
	int **G = new int*[n];  // Graph
	for (i = 0;i < n;i++)
		G[i] = new int[n];
	for (i = 0;i < n;i++)
		for (j = 0;j < n;j++)
			in_file >> G[i][j]; // Reading Graph from file
	
	if (isBipartite(G, n)) cout << "Graph is Bipartite\n";
	else cout << "Graph is not bipartite\n";

}