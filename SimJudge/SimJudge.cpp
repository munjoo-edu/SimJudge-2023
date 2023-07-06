#include <string>
#include <algorithm>
using namespace std;

class SimJudge
{
public:
	bool isSame(int a_len, int b_len)
	{
		return a_len == b_len;
	}

	int calPointLength(const std::string& a, const std::string& b)
	{
		int bigger = max(a.length(), b.length());
		int smaller = min(a.length(), b.length());

		if (isSame(bigger, smaller))
			return LENGTH_JUDGE_MAX_POINT;

		if (isDoubleDiff(bigger, smaller))
			return 0;

		return calPointPartial(bigger, smaller);
	}

	bool isDoubleDiff(int a_len, int b_len)
	{
		return a_len >= b_len * 2;
	}

	int calPointPartial(int a_len, int b_len)
	{
		return int((double)(a_len - b_len) / b_len * LENGTH_JUDGE_MAX_POINT);
	}

	const int LENGTH_JUDGE_MAX_POINT = 60;
};
