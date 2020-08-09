// Copyright 2020 Vikhrev Ivan

#include <string>
#include <vector>
#ifndef MODULES_ARRAYS_AND_STRINGS_ARRAYS_ALGORITHMS_H_
#define MODULES_ARRAYS_AND_STRINGS_ARRAYS_ALGORITHMS_H_

bool allUnique(std::string s);
bool allUniqueBruteForce(std::string s);
std::string inverse(char* str);
bool isPermBruteForce(std::string s1, std::string s2);
bool isPerm(const std::string& s1, const std::string& s2);
std::string URLify(char* s, int n);
bool isPalindromePerm(std::string s);
bool oneAway(std::string s1, std::string s2);
std::string strCompression(const std::string& s);
std::vector<int> rotate(std::vector<int> mat, int n);
std::vector<int> rotateInPlace(std::vector<int> mat, int n);
int numberOfIslands(std::vector<int> v, int N, int M);

#endif  // MODULES_ARRAYS_AND_STRINGS_ARRAYS_ALGORITHMS_H_
