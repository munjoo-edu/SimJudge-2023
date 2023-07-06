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

TEST(TestSimJudge, TestDiffDouble) {
	SimJudge judge{};
	string a = "abcd";
	string b = "ef";

	int expected = 0;
	int actual = judge.calPointLength(a, b);

	EXPECT_EQ(expected, actual);
}

TEST(TestSimJudge, TestA3B4) {
	SimJudge judge{};
	string a = "abc";
	string b = "defg";

	int expected = 20;
	int actual = judge.calPointLength(a, b);

	EXPECT_EQ(expected, actual);
}

TEST(TestSimJudge, TestA4B3) {
	SimJudge judge{};
	string a = "defg";
	string b = "abc";

	int expected = 20;
	int actual = judge.calPointLength(a, b);

	EXPECT_EQ(expected, actual);
}