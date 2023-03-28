#include<stdio.h>
#include<stdlib.h>
#include<string.h>

static int minnode(int n, int[] keyval, bool[] mstset)
{
	int mini = Int32.MaxValue;
	int mini_index = 0;

	for(int i = 0; i < n; i++)
	{
		if (mstset[i] == false && keyval[i] < mini)
    {
			mini = keyval[i];
			mini_index = i;
		}
	}
	return mini_index;
}

static void findcost(int n, int[,] city)
{
	int[] parent = new int[n];
	int[] keyval = new int[n];
	bool[] mstset = new bool[n];
	for(int i = 0; i < n; i++)
	{
		keyval[i] = Int32.MaxValue;
		mstset[i] = false;
	}
	parent[0] = -1;
	keyval[0] = 0;

	for(int i = 0; i < n - 1; i++)
	{
	    int u = minnode(n, keyval, mstset);
		mstset[u] = true;
		for(int v = 0; v < n; v++)
		{
			if (city[u, v] > 0 && mstset[v] == false &&
				city[u, v] < keyval[v])
		 	{
				keyval[v] = city[u, v];
				parent[v] = u;
			}
	 	}
	}
	int cost = 0;
	for(int i = 1; i < n; i++)
		cost += city[parent[i], i];
	Console.WriteLine(cost);
}

public static void Main(string[] args)
{
 	int n1 = 5;
	int[,] city1 = { { 0, 14, 2, 10, 0 },
					{ 14, 0, 6, 3, 5 },
					{ 2, 6, 0, 1, 0 },
					{ 10, 3, 1, 0, 8 },
 					{ 0, 5, 0, 8, 0 } };

 findcost(n1, city1);

}


