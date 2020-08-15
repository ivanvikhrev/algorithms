// Copyright 2020 Vikhrev Ivan

#include <vector>
#include <stack>
#include <queue>
#include <iostream>
#include <utility>
#include <limits>
#include "../../modules/graph/Graph.h"

Graph::Graph(int n, std::vector<std::vector<std::pair<int, int>>> a)
            : N(n), adj(a), distances(n, std::numeric_limits<int>::max()) { }

void Graph::DFS(int start) {
    std::vector<bool> visited(N, false);
    std::stack<int> s;
    int i = start;
    s.push(i);
    while (!s.empty()) {
        i = s.top();
        s.pop();
        if (!visited[i]) {
            std::cout << i << " - > ";
            visited[i] = true;
            for (auto v : adj[i]) {
                if (!visited[v.first]) {
                    s.push(v.first);
                }
            }
        }
        if (s.size() == 0) std::cout << "end";
    }
}

void Graph::BFS(int start) {
    std::vector<bool> visited(N, false);
    std::queue<int> q;
    int i =  start;
    q.push(i);
    while (!q.empty()) {
       i = q.front();
       q.pop();
       if (!visited[i]) {
           std::cout << i << " - > ";
           visited[i] = true;
           for (auto v : adj[i]) {
               if (!visited[v.first]) {
                   q.push(v.first);
               }
           }
       }
       if (q.size() == 0) std::cout << "end";
    }
}

std::vector<int> Graph::dijkstra(int start) {
    if (start >= N) return { -1 };
    std::priority_queue<std::pair<int, int>> q;
    std::vector<bool> processed(N);
    distances[start] = 0;
    q.push({0, start});
    int curr = start;
    while (!q.empty()) {
       curr = q.top().second;
       q.pop();
       if (processed[curr]) continue;
       processed[curr] = true;
       for (auto v : adj[curr]) {
           if (distances[curr] + v.second < distances[v.first]) {
               distances[v.first] = distances[curr] + v.second;
               q.push({ -distances[v.first], v.first });
           }
       }
    }
    return distances;
}
