// Copyright 2020 Vikhrev Ivan
#include <string>
#ifndef ARRAYS_ALGORITHMS_H_
#define ARRAYS_ALGORITHMS_H_

bool allUnique(std::string s);
bool allUniqueBruteForce(std::string s);
void inverse(char* str);
bool isPerm(std::string s1, std::string s2);
bool isPerm2(std::string& s1, std::string& s2);
void URLify(char* s, int n);
bool isPalindromePerm(std::string s);
bool oneAway(std::string s1, std::string s2);
std::string strCompression(const std::string& s);
std::vector<int> rotate(std::vector<int> mat, int n);
int numberOfIslands(std::vector<int> v, int N, int M);

#endif  // ARRAYS_ALGORITHMS_H_