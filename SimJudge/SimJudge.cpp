#include <string>
#include <vector>
using namespace std;

class SimJudge
{
public:
	int calPointMatchingChar(const std::string& a, const std::string& b)
	{
		string a_chars = "";
		string b_chars = "";

		for(char look_for = 'A'; look_for <='Z'; look_for++)
		{
			for(auto tar:a)
			{
				if (tar == look_for)
					a_chars += look_for;
			}
			for (auto tar : b)
			{
				if (tar == look_for)
					b_chars += look_for;
			}
		}

		if (a_chars == b_chars)
			return MATCHING_CHAR_JUDGE_MAX_POINT;

		return 0;
	}

	const int MATCHING_CHAR_JUDGE_MAX_POINT = 40;
};
