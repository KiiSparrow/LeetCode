#include "LeetCode.h"
using namespace std;


static const auto ioSyncOff = []()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();

class Solution
{
public:
	string decodeString(string s)
	{
		if (s.empty())
			return "";

		int currentPos = 0;
		string ans;
		while (currentPos != s.size())
		{
			ans = ans + decode(s, currentPos);
		}

		return ans;
	}

	string decode(string s, int& idx)
	{
		if ('a' <= s[idx] && s[idx] <= 'z')
		{
			string ans;
			while ('a' <= s[idx] && s[idx] <= 'z')
			{
				ans.push_back(s[idx]);
				++idx;
			}
			return ans;
		}

		int cnt = 0;
		//while ('0' <= s[idx] && s[idx] <= '9')
		while (s[idx] != '[')
		{
			cnt = 10 * cnt + s[idx] - '0';
			++idx;
		}
		++idx;

		string sub;
		while (s[idx] != ']')
		{
			if ('0' <= s[idx] && s[idx] <= '9')
			{
				sub = sub + decode(s, idx);
			}
			else
			{
				sub.push_back(s[idx]);
				++idx;
			}
		}
		++idx;

		string ans;
		while (cnt--)
		{
			ans = ans + sub;
		}

		return ans;
	}
};