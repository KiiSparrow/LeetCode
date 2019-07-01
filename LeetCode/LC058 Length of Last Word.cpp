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
	int lengthOfLastWord(string s)
	{
		//使用string流处理
		istringstream word(s);
		string ans;
		while(word>>ans);
		return ans.size();
	}

	int lengthOfLastWord_Normal(string s)
	{
		int l = s.size();
		int start = l - 1;
		for (int i = start; i >= 0; --i)
		{
			if (s[i] != ' ')
			{
				start = i;
				break;
			}
		}
		int ans = 0;
		for (int i = start; i >= 0; --i)
		{
			if (s[i] != ' ')
				++ans;
			else
				break;
		}
		return ans;
	}
};