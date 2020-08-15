// Copyright 2020 Vikhrev Ivan

#include <vector>
#include <iostream>
#include <utility>
#include "gtest/gtest.h"
#include "../../modules/graph/Graph.h"

using std::vector;
using std::pair;
TEST(graph, can_create_graph) {
    vector<vector<pair<int, int>>> adj = { {{1, 1}, {3, 1}}, {{0, 1}, {2, 1}, {3, 1}},
                                           {{1, 1}, {4, 1}, {5, 1}}, {{0, 1}, {1, 1}, {4, 1}},
                                           {{2, 1}, {3, 1}}, {{2, 1}} };
    Graph g(adj.size(), adj);
    g.dijkstra(0);
    ASSERT_EQ(g.dijkstra(0), vector<int>{1});
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
