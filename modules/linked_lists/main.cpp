// Copyright 2020 Vikhrev Ivan

#include <vector>
#include <iostream>
#include "gtest/gtest.h"
#include "../../modules/linked_lists/linked_lists.h"

using std::vector;
// class ListTest : public ::testing:Test {
//   protected:
//     List l;
//     void SetUp() override {
//     }

//     void TearDown override {

//     }
// }

TEST(Node, can_create_node) {
    ASSERT_NO_THROW(Node n);
}

TEST(Node, can_create_node_with_params) {
    ASSERT_NO_THROW(Node n(nullptr, 1));
}

TEST(Node, node_init_is_correct) {
    Node n(nullptr, 1);
    ASSERT_EQ(n.next, nullptr);
    ASSERT_EQ(n.data, 1);
}

TEST(Node, eq_nodes_are_eq) {
    Node n1(nullptr, 1);
    Node n2(nullptr, 1);
    ASSERT_EQ(n1, n2);
}


TEST(Node, not_eq_nodes_arent_eq1) {
    Node n1(nullptr, 1);
    Node n2(nullptr, 2);
    ASSERT_NE(n1, n2);
}

TEST(Node, not_eq_nodes_arent_eq2) {
    Node n1(nullptr, 1);
    Node n2(&n1, 1);
    ASSERT_NE(n1, n2);
}

TEST(Node, not_eq_nodes_arent_eq3) {
    Node n1(nullptr, 1);
    Node n2(&n1, 2);
    ASSERT_NE(n1, n2);
}

TEST(List, can_create_list) {
    ASSERT_NO_THROW(List l);
}

TEST(List, can_create_list_with_param) {
    ASSERT_NO_THROW(List l(1, 1));
}

TEST(List, list_init_with_param_is_correct) {
    List l(10, 3);
    Node* curr = l.get_head();
    int i = 0;
    while (curr->next) {
        ++i;
        curr = curr->next;
    }
    ASSERT_EQ(i, 9);
    ASSERT_EQ(l.front(), l.back());
}

TEST(List, ist_init_with_init_list) {
    List l{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ASSERT_EQ(l.front(), 1);
    ASSERT_EQ(l.back(), 10);
}

TEST(List, push_back_to_empty_list) {
    List l;
    l.push_back(100);
    ASSERT_EQ(l.front(), l.back());
}

TEST(List, push_front_to_empty_list) {
    List l;
    l.push_front(100);
    ASSERT_EQ(l.front(), l.back());
}

TEST(List, push_back_to_list) {
    List l(10, 1);
    l.push_back(10);
    ASSERT_EQ(l.front(), 1);
    ASSERT_EQ(l.back(), 10);
}

TEST(List, push_front_to_list) {
    List l(10, 1);
    l.push_front(0);
    ASSERT_EQ(l.front(), 0);
    ASSERT_EQ(l.back(), 1);
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
