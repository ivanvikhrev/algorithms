#include <vector>
#include <iostream>
#include "Graph.h"
using namespace std;
int main(int argc, char* argv[]) {
	
	vector<vector<int>> adj = { {1,3}, {0,2,3}, {1,4,5}, {0,1,4}, {2,3}, {2} };
	vector<vector<int>> adj2 = { {1}, {2}, {5}, {0,4}, {1,2}, {5} };
	Graph g(adj.size(), adj2);
	g.DFS();
	int *p = nullptr;
	int &r = *p;
	cout << p << endl;
	return 0;
}