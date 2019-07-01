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
	string countAndSay(int n)
	{
		string str("1");
		while (--n)
		{
			str = countOne(str);
		}
		return str;
	}
	string countOne(string str)
	{
		int count = 0;
		char num = str[0];
		string ans;
		for (char c : str)
		{
			if (c == num)
			{
				++count;
			}
			else
			{
				ans.push_back('0' + count);
				ans.push_back(num);
				count = 1;
				num = c;
			}
		}
		ans.push_back('0' + count);
		ans.push_back(num);

		return ans;
	}

};