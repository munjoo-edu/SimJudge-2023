#include <string>
#include <algorithm>
#include <stdexcept>
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

  int calcPointMatchPartial(string contA, string contB)
	{
		int idxA = 0, idxB = 0, point = 0;

		while (idxA < contA.length() && idxB < contB.length())
		{
			if (contA[idxA] == contB[idxB])
			{
				point++;
				idxA++; idxB++;
			} else if (contA[idxA] > contB[idxB])
			{
				idxB++;
			} else
			{
				idxA++;
			}
		}

		return (double)point / contA.length() * MATCHING_CHAR_JUDGE_MAX_POINT;
	}

	int calPointMatchingChar(const std::string& a, const std::string& b)
	{
		string contA = contractMessage(a);
		string contB = contractMessage(b);

		if (!isUpperCase(a + b))
			throw invalid_argument("Wrong char is used.");

		if (contA == contB)
			return MATCHING_CHAR_JUDGE_MAX_POINT;

		return calcPointMatchPartial(contA, contB);
	}

	bool isUpperCase(string tar)
	{
		for (auto c : tar)
			if (c < 'A' || c > 'Z')
				return false;

		return true;
	}

	string contractMessage(const std::string& tar_string)
	{
		string cont = "";
		for (char look_for = 'A'; look_for <= 'Z'; look_for++)
		{
			for (auto tar_char : tar_string)
			{
				if (tar_char == look_for)
				{
					cont += look_for;
					break;
				}
			}
		}

		return cont;
	}

	const int MATCHING_CHAR_JUDGE_MAX_POINT = 40;
};
