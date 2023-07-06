#include <string>
#include <vector>
using namespace std;

class SimJudge
{
public:

	int calPointMatchingChar(const std::string& a, const std::string& b)
	{
		string contA = contractMessage(a);
		string contB = contractMessage(b);

		if (!isUpperCase(contA + contB))
			return 0;

		if (contA == contB)
			return MATCHING_CHAR_JUDGE_MAX_POINT;

		return 0;
	}

	bool isUpperCase(string tar)
	{
		for (auto c : tar)
			if (c < 'A' || c>'Z') return false;

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
					cont += look_for;
			}
		}

		return cont;
	}

	const int MATCHING_CHAR_JUDGE_MAX_POINT = 40;
};
