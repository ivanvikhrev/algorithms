// Copyright 2020 Vikhrev Ivan

#include <vector>
#include <utility>
#ifndef MODULES_GRAPH_GRAPH_H_
#define MODULES_GRAPH_GRAPH_H_

class Graph {
 private:
    int N;
    std::vector<std::vector<std::pair<int, int>>> adj;
    std::vector<int> distances;
 public:
     Graph(int N,  std::vector<std::vector<std::pair<int, int>>>  a);
     void DFS(int start);
     void BFS(int start);
     std::vector<int> dijkstra(int start);
};

#endif  // MODULES_GRAPH_GRAPH_H_
