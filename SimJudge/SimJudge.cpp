#include <string>
#include <stdexcept>
using namespace std;

class SimJudge
{
public:

	int calPointMatchingChar(const std::string& a, const std::string& b)
	{
		string contA = contractMessage(a);
		string contB = contractMessage(b);

		if (!isUpperCase(a + b))
			throw invalid_argument("Wrong char is used.");

		if (contA == contB)
			return MATCHING_CHAR_JUDGE_MAX_POINT;

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
