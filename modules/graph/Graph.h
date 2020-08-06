// Copyright 2020 Vikhrev Ivan
#include <vector>

#ifndef GRAPH_ALGORITHMS_H_
#define GRAPH_ALGORITHMS_H_

class Graph {
 private:
	int N;
	std::vector<std::vector<int>> adj;

 public:
	 Graph(int N, std::vector<std::vector<int>> a);
	 void DFS();
	 void BFS();

};


#endif  //GRAPH_ALGORITHMS_H_