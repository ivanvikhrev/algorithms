// Copyright 2020 Vikhrev Ivan

#include <vector>
#include <stack>
#include <queue>
#include <iostream>
#include "../../modules/graph/Graph.h"

Graph::Graph(int n, std::vector<std::vector<int>> a) : N(n), adj(a) { }

void Graph::DFS() {
    std::vector<bool> visited(N, false);
    std::stack<int> s;
    int i = 0;
    s.push(i);
    while (!s.empty()) {
        i = s.top();
        s.pop();
        if (!visited[i]) {
            std::cout << i << " - > ";
            visited[i] = true;
            for (auto v : adj[i]) {
                if (!visited[v]) {
                    s.push(v);
                }
            }
        }
        if (s.size() == 0) std::cout << "end";
    }
}

void Graph::BFS() {
    std::vector<bool> visited(N, false);
    std::queue<int> q;
    int i = 0;
    q.push(i);
    while (!q.empty()) {
        i = q.front();
        q.pop();

        if (!visited[i]) {
            std::cout << i << " - > ";
            visited[i] = true;
            for (auto v : adj[i]) {
                if (!visited[v]) {
                    q.push(v);
                }
            }
        }
        if (q.size() == 0) std::cout << "end";
    }
}
