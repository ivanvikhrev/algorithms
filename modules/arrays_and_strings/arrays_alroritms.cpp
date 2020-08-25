// Copyright 2020 Vikhrev Ivan

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <utility>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include "../../modules/arrays_and_strings/arrays_algorithms.h"

using std::vector;
using std::string;
using std::stack;
using std::unordered_map;
using std::unordered_set;
using std::pair;
using std::make_pair;

// should have checked for size of string > size of ASCII table
bool allUnique(string s) {
    if (s.size() > 256) return false;

    unordered_set<char> charSet;

    for (auto ch : s) {
        if (charSet.find(ch) == charSet.end()) {
            charSet.insert(ch);
        } else {
            return false;
        }
    }
    return true;
}

bool allUniqueBruteForce(string s) {
    for (auto i = s.begin(); i < s.end(); ++i) {
        for (auto j = i + 1; j < s.end(); ++j) {
            if (*j == *i) {
                return false;
            }
        }
    }

    return true;
}

// haven't checked error cases
string inverse(const char* str) {
    string tmp(str);

    for (size_t i = 0; i < tmp.size() / 2; ++i) {
        char ch = tmp[i];
        tmp[i] = tmp[tmp.size()-1 -i];
        tmp[tmp.size() - 1 - i] = ch;
    }
    return tmp;
}

// simple solution O(n^2),  using '\0' symbol to mark checked character,
bool isPermBruteForce(std::string s1, std::string s2) {
    if (s1.size() != s2.size()) return false;

    for (size_t i = 0; i < s1.size(); ++i) {
        for (size_t j = 0; j < s2.size(); ++j) {
            if (s1[i] == s2[j]) {
                s2[j] = '\0';
                break;
            }
            if (j == s2.size() - 1) return false;
        }
    }

    return true;
}

bool isPerm(const std::string& s1, const std::string& s2) {
    if (s1.size() != s2.size()) return false;

    unordered_map<char, int> umap1;
    unordered_map<char, int> umap2;

    for (size_t i = 0; i < s1.size(); ++i) {
        if (umap1.find(s1[i]) == umap1.end())
            umap1.insert({ s1[i], 1 });
        else
            ++umap1[s1[i]];

        if (umap2.find(s2[i]) == umap2.end())
            umap2.insert({ s2[i], 1 });
        else
            ++umap2[s2[i]];
    }

    return umap1 == umap2;
}

string URLify(const char* s, int n) {
    string tmp(s);
    char subs[] = "%20";
    int offset = 2;
    int newN = n;
    for (int i = n-1; i >= 0; --i) {
        if (tmp[i] == ' ') {
            for (int j = newN - 1; j > i; --j) {
                tmp[j + offset] = tmp[j];
            }
            for (int k = 0; k <= offset; ++k) {
                tmp[i+k] = subs[k];
            }
            newN = newN + offset;
        }
    }
    return tmp;
}

bool oneAway(std::string s1, std::string s2) {
    if (abs(static_cast<int>(s1.size() - s2.size())) <= 1) {
        size_t i = 0, j = 0, mismatch = 0;
        while (i < s1.size() && j < s2.size()) {
            if (s1[i] == s2[j]) {
                ++i;
                ++j;
            } else {
                ++mismatch;
                if (s1.size() == s2.size()) {
                    ++i;
                    ++j;
                } else {
                    s1.size() > s2.size() ? ++i : ++j;
                }
            }
        }
        if (mismatch <= 1) return true;
    }

    return false;
}

// forget about last alone symbol
std::string strCompression(const std::string& s) {
    string res;
    int count = 1;
    for (size_t i = 0; i < s.size() - 1; ++i) {
        if (s[i] == toupper(s[i + 1]) || s[i] == tolower(s[i + 1])) {
            ++count;
            continue;
        } else {
            res = res + s[i] + std::to_string(count);
            count = 1;
        }
    }
    res = res + s[s.size()-1] + std::to_string(count);
    return res.size() < s.size() ? res : s;
}

// wrong index for rotated matrix, forgot about -1  : (n-j-1)*n+i
vector<int> rotate(vector<int> mat, int n) {
    if (n*n != mat.size()) return { -1 };
    vector<int> res(mat.size());
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            res[(n-j-1)*n+i] = mat[i*n + j];
    return res;
}

vector<int> rotateInPlace(vector<int> mat, int n) {
    if (n*n != mat.size()) return mat;

    for (int i = 0; i < n / 2; ++i)
        for (int j = i; j < n - i - 1; ++j) {
            int tmp = mat[(n - j - 1)*n + i];
            mat[(n - j - 1)*n + i] = mat[i*n + j];  // copy top to the left
            mat[i*n + j] = mat[j*n + n - i - 1];  // copy right to the top
            mat[j*n + n - i - 1] = mat[(n - i - 1)*n + n - j - 1];  // copy bottom to the right
            mat[(n - i - 1)*n + n - j - 1] = tmp;  // copy left to the bottom
        }
    return mat;
}

void DFS(vector<int>& v, int N, int M, pair<int, int> p) {
    stack<pair<int, int>> s;
    s.push(p);

    while (!s.empty()) {
        int i = s.top().first;
        int j = s.top().second;
        s.pop();
        if (v[i*N + j] == 1) {
            v[i*N + j] = 2;
            for (int k = -1; k < 2; ++k) {
                for (int p = -1; p < 2; ++p) {
                    if (i + k < 0 || i + k >= N || j + p < 0 || j + p >= M)
                        continue;
                    int newI = i + k;
                    int newJ = j + p;
                    if (v[newI*N + newJ] == 1)
                        s.push(make_pair(newI, newJ));
                }
            }
        }
    }
}

int numberOfIslands(vector<int> v, int N, int M) {
    stack<pair<int, int>> s;
    int count = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (v[i*N + j] == 1) {
                DFS(v, N, M, make_pair(i, j));
                ++count;
            }
        }
    }

    return count;
}

bool isPalindrome(const std::string& s) {
    for (size_t i = 0; i < s.size() / 2; ++i) {
        if (s[i] != s[s.size() - i - 1])
            return false;
    }
    return true;
}

void perm(const std::string& s) {
    std::vector<bool> chosen(s.size());
}
