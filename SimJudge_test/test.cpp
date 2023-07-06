#include "pch.h"
#include "..\SimJudge\SimJudge.cpp"

using namespace std;
#if 0
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
#endif
TEST(TestSimJudge, TestWrongChar) {
	SimJudge judge{};
	string a = "aBCD";
	string b = "EFGH";
	
	EXPECT_THROW(judge.calPointMatchingChar(a, b), invalid_argument);
}