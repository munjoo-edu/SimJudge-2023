#include <xstring>

class SimJudge
{
public:
	int calPointLength(const std::string& a, const std::string& b)
	{
		int a_len = a.length();
		int b_len = b.length();

		if (a_len >= b_len * 2 || a_len * 2 <= b_len)
			return 0;
		if (a_len == b_len)
			return LENGTH_JUDGE_MAX_POINT;
		return calPointPartial(a_len, b_len);
	}

	int calPointPartial(int a_len, int b_len)
	{
		if (a_len > b_len)
			return int((double)(a_len - b_len) / a_len * LENGTH_JUDGE_MAX_POINT);
		return int((double)(b_len - a_len) / b_len * LENGTH_JUDGE_MAX_POINT);
	}

	const int LENGTH_JUDGE_MAX_POINT = 60;
};
