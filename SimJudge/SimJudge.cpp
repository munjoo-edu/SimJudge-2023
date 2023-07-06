#include <xstring>

class SimJudge
{
public:
	int calPointLength(const std::string& a, const std::string& b)
	{
		if (a.length() == b.length())
			return 60;
		if (a.length() > b.length())
		{
			return (double)(a.length() - b.length()) / a.length() * 60;
		} else
		{
			return (double)(b.length() - a.length()) / b.length() * 60;
		}
		return 0;
	}
};
