// Copyright 2020 Vikhrev Ivan

#include <iostream>
#include <string>
#include <tuple>
#include <cmath>
#include <algorithm>
#include <unordered_set>
#include <vector>
#include "gtest/gtest.h"
#include "../../modules/arrays_and_strings/arrays_algorithms.h"

using std::vector;
using std::string;
using std::pair;
using std::make_pair;

TEST(allUnique, true_for_empty_string) {
    string s = "";
    ASSERT_EQ(allUnique(s), true);
}

TEST(allUnique, true_for_one_char) {
    string s = "a";
    ASSERT_EQ(allUnique(s), true);
}

TEST(allUnique, true_for_all_unique_chars) {
    ASSERT_EQ(allUnique("abc"), true);
    ASSERT_EQ(allUnique("cbdtsg"), true);
}

TEST(allUnique, false_when_no_unique_chars) {
    ASSERT_EQ(allUnique("aabc"), false);
    ASSERT_EQ(allUnique("abca"), false);
}


TEST(allUniqueBruteForce, true_for_empty_string) {
    string s = "";
    ASSERT_EQ(allUniqueBruteForce(s), true);
}

TEST(allUniqueBruteForce, true_for_one_char) {
    string s = "a";
    ASSERT_EQ(allUniqueBruteForce(s), true);
}

TEST(allUniqueBruteForce, true_for_all_unique_chars) {
    ASSERT_EQ(allUniqueBruteForce("abc"), true);
    ASSERT_EQ(allUniqueBruteForce("cbdtsg"), true);
}

TEST(allUniqueBruteForce, false_when_no_unique_chars) {
    ASSERT_EQ(allUniqueBruteForce("aabc"), false);
    ASSERT_EQ(allUniqueBruteForce("abca"), false);
}

TEST(inverse, handle_empty_string ) {
    ASSERT_EQ(inverse(""), "");
}

TEST(inverse, handle_one_char_string) {
    ASSERT_EQ(inverse("a"), "a");
}

TEST(inverse, can_inverse_strings) {
    ASSERT_EQ(inverse("abc"), "cba");
    ASSERT_EQ(inverse("abcd"), "dcba");
    ASSERT_EQ(inverse("0123456789"), "9876543210");
}

TEST(isPermutationBruteForce, handle_empty_string) {
    ASSERT_EQ(isPermBruteForce("", ""), true);
}

TEST(isPermutationBruteForce, false_for_strings_with_diff_size) {
    ASSERT_EQ(isPermBruteForce("abs", "a"), false);
}

TEST(isPermutationBruteForce, true_for_one_char_string) {
    ASSERT_EQ(isPermBruteForce("a", "a"), true);
}

TEST(isPermutationBruteForce, true_for_true_input) {
    ASSERT_EQ(isPermBruteForce("abc", "abc"), true);
    ASSERT_EQ(isPermBruteForce("abc", "cba"), true);
    ASSERT_EQ(isPermBruteForce("abc", "bca"), true);
    ASSERT_EQ(isPermBruteForce("abc", "acb"), true);
    ASSERT_EQ(isPermBruteForce("1234", "4321"), true);
}

TEST(isPermutationBruteForce, fale_for_false_input) {
    ASSERT_EQ(isPermBruteForce("abc", "abd"), false);
    ASSERT_EQ(isPermBruteForce("1234", "1235"), false);
}


TEST(isPermutation, handle_empty_string) {
    ASSERT_EQ(isPerm("", ""), true);
}

TEST(isPermutation, false_for_strings_with_diff_size) {
    ASSERT_EQ(isPerm("abs", "a"), false);
}

TEST(isPermutation, true_for_one_char_string) {
    ASSERT_EQ(isPerm("a", "a"), true);
}

TEST(isPermutation, true_for_true_input) {
    ASSERT_EQ(isPerm("abc", "abc"), true);
    ASSERT_EQ(isPerm("abc", "cba"), true);
    ASSERT_EQ(isPerm("abc", "bca"), true);
    ASSERT_EQ(isPerm("abc", "acb"), true);
    ASSERT_EQ(isPerm("1234", "4321"), true);
}

TEST(isPermutation, fale_for_false_input) {
    ASSERT_EQ(isPerm("abc", "abd"), false);
    ASSERT_EQ(isPerm("1234", "1235"), false);
}

TEST(URLify, handdle_empty_string) {
    ASSERT_EQ(URLify("", 0), "");
}

TEST(URLify, handdle_string_with_spaces) {
    ASSERT_EQ(URLify(" ..", 1), "%20");
    ASSERT_EQ(URLify("  ....", 2), "%20%20");
    ASSERT_EQ(URLify(" a..", 2), "%20a");
    ASSERT_EQ(URLify("a a..", 3), "a%20a");
    ASSERT_EQ(URLify("a a ....", 4), "a%20a%20");
}

TEST(URLify, handdle_string_without_spaces) {
    ASSERT_EQ(URLify("abc", 3), "abc");
}

TEST(oneAway, handle_empty_strings ) {
    ASSERT_EQ(oneAway("", ""), true);
}

TEST(oneAway, handle_positive_cases) {
    ASSERT_EQ(oneAway("a", "a"), true);
    ASSERT_EQ(oneAway("adc", "abc"), true);
    ASSERT_EQ(oneAway("abc", "dbc"), true);
    ASSERT_EQ(oneAway("ab", "abc"), true);
    ASSERT_EQ(oneAway("abc", "abcd"), true);
    ASSERT_EQ(oneAway("abc", "dabc"), true);
}

TEST(oneAway, handle_negative_cases) {
    ASSERT_EQ(oneAway("ab", "ba"), false);
    ASSERT_EQ(oneAway("cat", "kit"), false);
}

TEST(stringCompression, can_compress_string) {
    ASSERT_EQ(strCompression("aaa"), "a3");
    ASSERT_EQ(strCompression("aaabbbccc"), "a3b3c3");
    ASSERT_EQ(strCompression("abbbccc"), "a1b3c3");
}

TEST(stringCompression, no_compression) {
    ASSERT_EQ(strCompression("a"), "a");
    ASSERT_EQ(strCompression("abcd"), "abcd");
    ASSERT_EQ(strCompression("abcdd"), "abcdd");
}

class MatrixParameterizedTestFixture : public ::testing::TestWithParam<std::tuple<vector<int>, vector<int>>> {};

TEST_P(MatrixParameterizedTestFixture, check_correctness_rotate_function) {
    vector<int> mat = std::get<0>(GetParam());
    vector<int> expected = std::get<1>(GetParam());
    ASSERT_EQ(rotate(mat, static_cast<int>(std::sqrt(mat.size()))), expected);
}

TEST_P(MatrixParameterizedTestFixture, check_correctness_in_place_rotate_function) {
    vector<int> mat = std::get<0>(GetParam());
    vector<int> expected = std::get<1>(GetParam());
    ASSERT_EQ(rotateInPlace(mat, static_cast<int>(std::sqrt(mat.size()))), expected);
}

INSTANTIATE_TEST_SUITE_P(
    RotateTest,
    MatrixParameterizedTestFixture,
    ::testing::Values(
        // 1 x 1
        std::make_tuple<vector<int>, vector<int>>({ 1 }, { 1 }),
        // 2 x 2
        std::make_tuple<vector<int>, vector<int>>({ 1, 1, 0, 0 }, { 1, 0, 1, 0 }),
        std::make_tuple<vector<int>, vector<int>>({ 1, 0, 0, 1 }, { 0, 1, 1, 0 }),
        std::make_tuple<vector<int>, vector<int>>({ 1, 1, 1, 0 }, { 1, 0, 1, 1 }),
        std::make_tuple<vector<int>, vector<int>>({ 1, 1, 1, 1 }, { 1, 1, 1, 1 }),
        // 3 x 3
        std::make_tuple<vector<int>, vector<int>>({ 1, 1, 1, 1, 0, 1, 1, 1, 1 }, { 1, 1, 1, 1, 0, 1, 1, 1, 1 }),
        std::make_tuple<vector<int>, vector<int>>({ 1, 2, 3, 4, 5, 6, 7, 8, 9 }, { 3, 6, 9, 2, 5, 8, 1, 4, 7 })));

class NumberOfIslandsParameterizedTestFixture : public ::testing::TestWithParam<std::tuple<vector<int>, int>> {};

TEST_P(NumberOfIslandsParameterizedTestFixture, check_correctness_number_of_islands) {
    vector<int> mat = std::get<0>(GetParam());
    int expected = std::get<1>(GetParam());
    ASSERT_EQ(numberOfIslands(mat, static_cast<int>(std::sqrt(mat.size())),
                                   static_cast<int>(std::sqrt(mat.size()))), expected);
}


INSTANTIATE_TEST_SUITE_P(
    RotateTest,
    NumberOfIslandsParameterizedTestFixture,
    ::testing::Values(
        // 1 x 1
        std::make_tuple<vector<int>>({ 1 }, 1),
        //// 2 x 2
        std::make_tuple<vector<int>>({ 1, 1, 0, 0 }, 1),
        std::make_tuple<vector<int>>({ 1, 0, 0, 1 }, 1),
        std::make_tuple<vector<int>>({ 1, 1, 1, 0 }, 1),
        std::make_tuple<vector<int>>({ 1, 1, 1, 1 }, 1),
        // 3 x 3
        std::make_tuple<vector<int>>({ 1, 0, 0, 0, 0, 1, 1, 0, 0 }, 3),
        std::make_tuple<vector<int>>({ 1, 0, 0, 0, 1, 0, 0, 0, 1 }, 1),
        std::make_tuple<vector<int>>({ 1, 0, 1, 0, 1, 0, 0, 0, 1 }, 1),
        std::make_tuple<vector<int>>({ 0, 0, 0, 0, 1, 0, 0, 0, 0 }, 1),
        std::make_tuple<vector<int>>({ 1, 1, 1, 0, 0, 1, 1, 0, 0 }, 2)));


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
