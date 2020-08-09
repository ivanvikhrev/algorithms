// Copyright 2020 Vikhrev Ivan

#include <vector>
#ifndef MODULES_GRAPH_GRAPH_H_
#define MODULES_GRAPH_GRAPH_H_

class Graph {
 private:
    int N;
    std::vector<std::vector<int>> adj;
 public:
     Graph(int N, std::vector<std::vector<int>> a);
     void DFS();
     void BFS();
};

#endif  // MODULES_GRAPH_GRAPH_H_
