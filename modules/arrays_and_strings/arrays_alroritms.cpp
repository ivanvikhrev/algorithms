#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include "arrays_algorithms.h"

using namespace std;

// should have checked for size of string > size of ASCII table
bool allUnique(string s) {
	if (s.size() > 256) return false;

	unordered_set<char> charSet;

	for (auto ch : s) {
		if (charSet.find(ch) == charSet.end()) {
			charSet.insert(ch);
		}
		else
			return false;
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
void inverse(char* str) {
	int n = 0;

	if (str) { //
		while (*(str + n) != '\0') {
			++n;
		} //
	}

	for (int i = 0; i < n / 2; ++i) {
		char tmp = *(str + i);
		*(str + i) = *(str + n - 1 - i);
		*(str + n - 1 - i) = tmp;
	}
}

// simple solution O(n^2),  using '\0' symbol to mark checked character, 
bool isPerm(std::string s1, std::string s2) {
	if (s1.size() != s2.size()) return false;

	for (int i = 0; i < s1.size(); ++i) {
		for (int j = 0; j < s2.size(); ++j) {
			if (s1[i] == s2[j]) {
				s2[j] = '\0';
				break;
			}
			if (j == s2.size() - 1) return false;
		}
	}

	return true;
}

bool isPerm2(std::string& s1, std::string& s2) {

	if (s1.size() != s2.size()) return false;

	unordered_map<char, int> umap1;
	unordered_map<char, int> umap2;
	
	for (int i = 0; i < s1.size(); ++i) {
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


void URLify(char* s, int n) {
	char subs[] = "%20";
	int offset = 2;
	for (int i = 0; i < n; ++i) {

		if (s[i] == ' ') {
			for (int j = n - 1; j > i; --j) {
				s[j + offset] = s[j];
			}

			for (int k = i; k < i + offset; ++k) {
				cout << i << i + offset << std::endl;
				s[k] = subs[k - i];
			}
			string tmp(s);
			cout << tmp << std::endl;
		}
	}
}

bool oneAway(std::string s1, std::string s2) {
	if (abs(static_cast<int>(s1.size() - s2.size())) <= 1) {
		
		int i = 0, j = 0, mismatch = 0;
		while (i < s1.size() && j < s2.size()) {

			if (s1[i] == s2[j]) {
				++i;
				++j;
			} else {
				++mismatch;
				if (s1.size() == s2.size()) {
					++i;
					++j;
				}
				else {
					s1.size() > s2.size() ? ++i : ++j;
				}
			}
		}
		if (mismatch <= 1) return true;
	}

	return false;
}
// forget about last alone symbol
std::string strCompression(const std::string& s)
{	
	string res;
	int count = 1;
	for (int i = 0; i < s.size() - 1; ++i) {
		if (s[i] == toupper(s[i + 1]) || s[i] == tolower(s[i + 1])) {
			++count;
			continue;
		} else {
			res = res + s[i] + std::to_string(count);
			count = 1;
		}
	}
	res = res + s[s.size()-1] + std::to_string(count);
	if (res.size() < s.size())
		return res;
	else
		return s;
}
//wrong index for rotated matrix, forgot about -1  : (n-j-1)*n+i
vector<int> rotate(vector<int> mat, int n)
{	
	if (n*n != mat.size()) return { -1 };
	vector<int> res(mat.size());
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			res[(n-j-1)*n+i] = mat[i*n + j];
	return res;
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
	int i = 0, j = 0;
	int count = 0;
	
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			
			if (v[i*N + j] == 1) {
				DFS(v, N, M, make_pair(i, j));
				++count;
			}
				//call DFS;
		}
	}

	return count;
}
