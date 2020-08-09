// Copyright 2020 Vikhrev Ivan

#include <vector>
#include <iostream>
#include "gtest/gtest.h"
#include "../../modules/graph/Graph.h"

using std::vector;

TEST(graph, can_create) {
    vector<vector<int>> adj = { {1, 3}, {0, 2, 3}, {1, 4, 5}, {0, 1, 4}, {2, 3}, {2} };
    Graph g(adj.size(), adj);
    g.BFS();
}
int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
