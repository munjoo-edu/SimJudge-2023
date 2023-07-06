#include "pch.h"
#include "..\SimJudge\SimJudge.cpp"
#include <string>

using namespace std;

TEST(TestSimJudge, TestSameLen) {
	SimJudge judge{};
	string a = "abcd";
	string b = "efgh";

	int expected = 60;
	int actual = judge.calPointLength(a, b);

	EXPECT_EQ(expected, actual);
}

TEST(TestSimJudge, TestA2B4) {
	SimJudge judge{};
	string a = "ab";
	string b = "defg";

	int expected = 30;
	int actual = judge.calPointLength(a, b);

	EXPECT_EQ(expected, actual);
}

TEST(TestSimJudge, TestA4B2) {
	SimJudge judge{};
	string a = "defg";
	string b = "ab";

	int expected = 30;
	int actual = judge.calPointLength(a, b);

	EXPECT_EQ(expected, actual);
}