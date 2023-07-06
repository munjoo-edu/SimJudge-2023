#include "pch.h"
#include "..\SimJudge\SimJudge.cpp"

using namespace std;

TEST(TestSimJudge, TestSameChar) {
	SimJudge judge{};
	string a = "ABCD";
	string b = "DCBA";

	int expected = 40;
	int actual = judge.calPointMatchingChar(a, b);

	EXPECT_EQ(expected, actual);
}

TEST(TestSimJudge, TestDifferChar) {
	SimJudge judge{};
	string a = "ABCD";
	string b = "EFGH";

	int expected = 0;
	int actual = judge.calPointMatchingChar(a, b);

	EXPECT_EQ(expected, actual);
}