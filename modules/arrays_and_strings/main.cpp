#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>
#include "arrays_algorithms.h"
#include "gtest/gtest.h"

using namespace std; 

TEST(allUnique, empty_string) {
	string s = "";
	ASSERT_EQ(allUnique(s), true);
}

TEST(allUnique, one_char) {
	string s = "a";
	ASSERT_EQ(allUnique(s), true);
}

TEST(allUnique, unique_chars_1) {
	string s = "abc";
	ASSERT_EQ(allUnique(s), true);
}

TEST(allUnique, unique_chars_2) {
	string s = "cbdtsg";
	ASSERT_EQ(allUnique(s), true);
}

TEST(allUnique, no_unique_chars_1) {
	string s = "aabc";
	ASSERT_EQ(allUnique(s), false);
}

TEST(allUnique, no_unique_chars_2) {
	string s = "abca";
	ASSERT_EQ(allUnique(s), false);
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
//class A {
//public:
//		int a;
//		A() : a(200) {};
//} myA;
//
//int main(int argc, char** argv) {
//
//	string s1 = "    ";
//	string s2 = "a     ";
//	string s3 = "a b c  \\\\\\";
//	string s4 = "a";
//	string s5 = "abcdef2";
//	string s6 = "2defabc";
//	string s7 = "a";
//
//	//cout << isUnique(s6) << endl;
//
//	char c1[] = "";
//	char c2[] = "1";
//
//	char c3[] = "1 3000";
//	char c4[] = "3 2 1 \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\";
//	char c5[] = "1234";
//	char c6[] = "45";
//	//inverse(c6);
//	//cout << c6 << endl;
//	//URLify(c3, 3);
//	//string tmp(c3);
//	//cout << tmp << std::endl;
//
//	//cout << oneAway("dab", "ab") << endl;
//
//	vector<int> mat = { 1,0,1,0,
//		                0,1,0,0,
//						0,1,1,1, 
//						0,0,1,0, };
//	
//	int n = 4, m = 4;
//	int res = numberOfIslands(mat,n, m);
//	for (int i = 0; i < n; ++i) {
//		for (int j = 0; j < m; ++j)
//			cout << mat[i*n + j] << " ";
//		cout << endl;
//	}
//	cout << res << endl;
//	//for (int i = 0; i < n;  ++i) {
//	//	for (int j = 0; j < n; ++j)
//	//		cout << res[i*n + j] << " ";
//	//	cout << endl;
//	//}
//	int a1 = 4;
//	int* a  = &a1;
//	*a = 2;
//	A b;
//	cout << b.a << endl;
//	return 0;
//}