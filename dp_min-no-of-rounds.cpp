#include<bits/stdc++.h>
using namespace std;
class NAryTree
{
	int N; 
	list<int> *adj;
	void getMinIterUtil(int v, int minItr[]);
public:
	NAryTree(int N);
	void addChild(int v, int w);
	int getMinIter();
	static int compare(const void * a, const void * b);
};
NAryTree::NAryTree(int N)
{
	this->N = N;
	adj = new list<int>[N];
}
void NAryTree::addChild(int v, int w)
{
	adj[v].push_back(w); 
}
void NAryTree::getMinIterUtil(int u, int minItr[])
{
	minItr[u] = adj[u].size();
	int *minItrTemp = new int[minItr[u]];
	int k = 0, tmp = 0;
	list<int>::iterator i;
	for (i = adj[u].begin(); i!= adj[u].end(); ++i)
	{
		getMinIterUtil(*i, minItr);
		minItrTemp[k++] = minItr[*i];
	}
	qsort(minItrTemp, minItr[u], sizeof (int), compare);
	for (k = 0; k < adj[u].size(); k++)
	{
		tmp = minItrTemp[k] + k + 1;
		minItr[u] = max(minItr[u], tmp);
	}
	delete[] minItrTemp;
}

int NAryTree::getMinIter()
{
	int *minItr = new int[N];
	int res = -1;
	for (int i = 0; i < N; i++)
		minItr[i] = 0;
	getMinIterUtil(0, minItr);
	res = minItr[0];
	delete[] minItr;
	return res;
}
int NAryTree::compare(const void * a, const void * b)
{
		return ( *(int*)b - *(int*)a );
}
int main()
{
	// TestCase 1
	NAryTree tree1(13);
	tree1.addChild(0, 1);
	tree1.addChild(0, 2);

	tree1.addChild(1, 3);
	tree1.addChild(1, 4);
	tree1.addChild(1, 5);

	tree1.addChild(2, 6);

	tree1.addChild(6, 12);

	tree1.addChild(3, 7);
	tree1.addChild(3, 8);
	tree1.addChild(6, 9);
	tree1.addChild(6, 10);
    tree1.addChild(10, 11);

	cout << "TestCase 1 - Minimum Iteration: "
		<< tree1.getMinIter() << endl;

	// TestCase 2
	NAryTree tree2(3);
	tree2.addChild(0, 1);
	tree2.addChild(0, 2);
	cout << "TestCase 2 - Minimum Iteration: "
		<< tree2.getMinIter() << endl;

	// TestCase 3
	NAryTree tree3(1);
	cout << "TestCase 3 - Minimum Iteration: "
		<< tree3.getMinIter() << endl;

	// TestCase 4
	NAryTree tree4(6);
	tree4.addChild(0, 1);
	tree4.addChild(1, 2);
	tree4.addChild(2, 3);
	tree4.addChild(3, 4);
	tree4.addChild(4, 5);
	cout << "TestCase 4 - Minimum Iteration: "
		<< tree4.getMinIter() << endl;

	// TestCase 5
	NAryTree tree5(6);
	tree5.addChild(0, 1);
	tree5.addChild(0, 2);
	tree5.addChild(2, 3);
	tree5.addChild(2, 4);
	tree5.addChild(2, 5);
	cout << "TestCase 5 - Minimum Iteration: "
		<< tree5.getMinIter() << endl;

	// TestCase 6
	NAryTree tree6(6);
	tree6.addChild(0, 1);
	tree6.addChild(0, 2);
	tree6.addChild(2, 3);
	tree6.addChild(2, 4);
	tree6.addChild(3, 5);
	cout << "TestCase 6 - Minimum Iteration: "
		<< tree6.getMinIter() << endl;

	// TestCase 7
	NAryTree tree7(14);
	tree7.addChild(0, 1);
	tree7.addChild(0, 2);
	tree7.addChild(0, 3);
	tree7.addChild(1, 4);
	tree7.addChild(2, 5);
	tree7.addChild(2, 6);
	tree7.addChild(4, 7);
	tree7.addChild(5, 8);
	tree7.addChild(5, 9);
	tree7.addChild(7, 10);
	tree7.addChild(8, 11);
	tree7.addChild(8, 12);
	tree7.addChild(10, 13);
	cout << "TestCase 7 - Minimum Iteration: "
		<< tree7.getMinIter() << endl;

	// TestCase 8
	NAryTree tree8(14);
	tree8.addChild(0, 1);
	tree8.addChild(0, 2);
	tree8.addChild(0, 3);
	tree8.addChild(0, 4);
	tree8.addChild(0, 5);
	tree8.addChild(1, 6);
	tree8.addChild(2, 7);
	tree8.addChild(3, 8);
	tree8.addChild(4, 9);
	tree8.addChild(6, 10);
	tree8.addChild(7, 11);
	tree8.addChild(8, 12);
	tree8.addChild(9, 13);
	cout << "TestCase 8 - Minimum Iteration: "
		<< tree8.getMinIter() << endl;

	// TestCase 9
	NAryTree tree9(25);
	tree9.addChild(0, 1);
	tree9.addChild(0, 2);
	tree9.addChild(0, 3);
	tree9.addChild(0, 4);
	tree9.addChild(0, 5);
	tree9.addChild(0, 6);

	tree9.addChild(1, 7);
	tree9.addChild(2, 8);
	tree9.addChild(3, 9);
	tree9.addChild(4, 10);
	tree9.addChild(5, 11);
	tree9.addChild(6, 12);

	tree9.addChild(7, 13);
	tree9.addChild(8, 14);
	tree9.addChild(9, 15);
	tree9.addChild(10, 16);
	tree9.addChild(11, 17);
	tree9.addChild(12, 18);
	
	tree9.addChild(13, 19);
	tree9.addChild(14, 20);
	tree9.addChild(15, 21);
	tree9.addChild(16, 22);
	tree9.addChild(17, 23);
	tree9.addChild(19, 24);

	cout << "TestCase 9 - Minimum Iteration: "
		<< tree9.getMinIter() << endl;

	return 0;
}
