// Copyright 2020 Vikhrev Ivan

#include <vector>
#include <iostream>
#include <tuple>
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
    std::cout << l << std::endl;
    ASSERT_EQ(l.front(), 1);
    ASSERT_EQ(l.back(), 10);
}

TEST(List, can_copy_list) {
    List l{1, 2, 3, 4};
    ASSERT_NO_THROW(List l2(l));
}

TEST(List, copied_list_eq_original) {
    List l{1, 2, 3, 4};
    List l2(l);
    std::cout << l2 << std::endl;
    ASSERT_EQ(l, l2);
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

TEST(List, empty_list_is_empty) {
    List l;
    ASSERT_EQ(l.empty(), true);
}

TEST(List, not_empty_list_isnt_empty) {
    List l(1);
    ASSERT_EQ(l.empty(), false);
}


TEST(List, eq_lists_are_eq) {
    List l1{1, 2, 3, 4, 5};
    List l2{1, 2, 3, 4, 5};
    ASSERT_EQ(l1, l2);
}


TEST(List, not_eq_lists_arent_eq) {
    List l1(1);
    List l2(2);
    ASSERT_NE(l1, l2);
}

class ListParameterizedTestFixture : public ::testing::TestWithParam<std::tuple<List, List>> {};

TEST_P(ListParameterizedTestFixture, can_remove_duplicates_with_unordered_set) {
    List l = std::get<0>(GetParam());
    List expected = std::get<1>(GetParam());
    l.remove_duplicates1();
    ASSERT_EQ(l, expected);
}

TEST_P(ListParameterizedTestFixture, can_remove_duplicates_without_temporary_buffer) {
    List l = std::get<0>(GetParam());
    List expected = std::get<1>(GetParam());

    l.remove_duplicates2();
    std::cout << l << std::endl;
    ASSERT_EQ(l, expected);
}

INSTANTIATE_TEST_SUITE_P(
    RemoveDuplicatesTest,
    ListParameterizedTestFixture,
    ::testing::Values(
        std::make_tuple<List, List>({ 1 }, { 1 }),
        std::make_tuple<List, List>({ 1, 1, 0, 0 }, { 1, 0 }),
        std::make_tuple<List, List>({ 1, 1, 1, 1 }, { 1 }),
        std::make_tuple<List, List>({ 1, 1, 1, 0 }, { 1, 0 }),
        std::make_tuple<List, List>({ 1, 2, 3, 4, 5, 6, 7, 8, 9}, { 1, 2, 3, 4, 5, 6, 7, 8, 9}),
        std::make_tuple<List, List>
                ({ 1, 1, 1, 2, 3, 3, 4, 5, 6, 6, 7, 8, 9, 9, 9}, { 1, 2, 3, 4, 5, 6, 7, 8, 9})));

class ListParameterizedWith3ParamsTestFixture :
        public ::testing::TestWithParam<std::tuple<std::tuple<List, int>, List>> {};

TEST_P(ListParameterizedWith3ParamsTestFixture, can_rearrange) {
    List l = std::get<0>(std::get<0>(GetParam()));
    int x = std::get<1>(std::get<0>(GetParam()));
    List expected = std::get<1>(GetParam());
    l.rearrange(x);
    std::cout << l << std::endl;
    ASSERT_EQ(l, expected);
}

INSTANTIATE_TEST_SUITE_P(
    RearrangeTest,
    ListParameterizedWith3ParamsTestFixture,
    ::testing::Values(
        std::make_tuple<std::tuple<List, int>, List>
            (std::make_tuple<List, int>({1}, 1), {1}),
        std::make_tuple<std::tuple<List, int>, List>
            (std::make_tuple<List, int>({5, 1}, 3), {1, 5}),
        std::make_tuple<std::tuple<List, int>, List>
            (std::make_tuple<List, int>({5, 1, 1, 1}, 3), {1, 1, 1, 5}),
        std::make_tuple<std::tuple<List, int>, List>
            (std::make_tuple<List, int>({5, 4, 2, 1, 2, 3, 4, 5}, 2), {1, 5, 4, 2, 2, 3, 4, 5}),
        std::make_tuple<std::tuple<List, int>, List>
            (std::make_tuple<List, int>({1, 2, 3, 4, 5, 6, 7}, 3), {1, 2, 3, 4, 5, 6, 7}),
        std::make_tuple<std::tuple<List, int>, List>
            (std::make_tuple<List, int>({ 4, 4, 4, 1, 1, 8, 8, 0, 0, 0 }, 2), {1, 1, 0, 0, 0, 4, 4, 4, 8, 8})));


TEST(List, kth_from_the_end) {
    List l1{ 1, 2, 3, 4, 5, 6, 7};
    ASSERT_EQ(l1.find_k_from_end(6), 1);
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
