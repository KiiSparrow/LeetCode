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
	bool isValid(string s)
	{
		stack<char> ss;
		for (int i = 0; i < s.length(); ++i)
		{
			if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			{
				ss.push(s[i]);
			}
			else if (ss.size() > 0)
			{
				if (s[i] == ')' && ss.top() == '(')
				{
					ss.pop();
					continue;
				}
				else if (s[i] == ']' &&  ss.top() == '[')
				{
					ss.pop();
					continue;
				}
				else if (s[i] == '}' &&  ss.top() == '{')
				{
					ss.pop();
					continue;
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}

		return ss.size() == 0;
	}
};