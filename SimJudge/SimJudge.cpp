#include <string>

class SimJudge
{
public:
	int calPointLength(const std::string& a, const std::string& b)
	{
		int a_len = a.length();
		int b_len = b.length();

		if (a_len == b_len)
			return LENGTH_JUDGE_MAX_POINT;
		if (isDoubleDiff(a_len, b_len))
			return 0;
		return calPointPartial(a_len, b_len);
	}

	bool isDoubleDiff(int a_len, int b_len)
	{
		return a_len >= b_len * 2 || a_len * 2 <= b_len;
	}

	int calPointPartial(int a_len, int b_len)
	{
		if (a_len > b_len)
			return int((double)(a_len - b_len) / b_len * LENGTH_JUDGE_MAX_POINT);
		return int((double)(b_len - a_len) / a_len * LENGTH_JUDGE_MAX_POINT);
	}

	const int LENGTH_JUDGE_MAX_POINT = 60;
};
