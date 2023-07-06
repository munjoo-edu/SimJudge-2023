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

TEST(TestSimJudge, TestWrongChar) {
	SimJudge judge{};
	string a = "aBCD";
	string b = "EFGH";
	
	EXPECT_THROW(judge.calPointMatchingChar(a, b), invalid_argument);
}


TEST(TestSimJudge, TestMatchingPartial) {
	SimJudge judge{};
	string a = "ABCD";
	string b = "ABAA";

	int expected = 20;
	int actual = judge.calPointMatchingChar(a, b);

	EXPECT_EQ(expected, actual);
}
