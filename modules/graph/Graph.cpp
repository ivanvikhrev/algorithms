#include <vector>
#include <stack>
#include <iostream>
#include "Graph.h"

Graph::Graph(int n, std::vector<std::vector<int>> a) : N(n), adj(a) { };

void Graph::DFS() {
	std::vector<bool> visited(N, false);
	std::stack<int> s;
	int i = 0;
	s.push(i);
	while (!s.empty()) {
		i = s.top();
		s.pop();

		if (!visited[i])
		{
			std::cout << i << " - > ";
			visited[i] = true;
		}

		for (auto v : adj[i]) {
			if (!visited[v]) {
				s.push(v);
			}
		}
		if (s.size() == 0) std::cout << "end";
	}
}

void Graph::BFS() {
	std::vector<bool> visited(N, false);
	std::stack<int> s;
	int i = 0;
	s.push(i);
	while (!s.empty()) {
		i = s.top();
		s.pop();

		if (!visited[i])
		{
			std::cout << i << " - > ";
			visited[i] = true;
		}

		for (auto v : adj[i]) {
			if (!visited[v]) {
				s.push(v);
			}
		}
		if (s.size() == 0) std::cout << "end";
	}
}