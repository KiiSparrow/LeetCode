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
	int lengthOfLongestSubstring(string s)
	{
		int ans = 0;
		int k = 0;

		map<char, int> cMap;
		map<char, int>::iterator iter;

		for (int i = 0; i < s.length(); ++i)
		{
			k = 0;
			for (int j = i; j < s.length(); ++j)
			{
				iter = cMap.find(s[j]);
				if (iter == cMap.end())
				{
					cMap.insert(pair<char, int>(s[j], i));
					++k;
				}
				else
				{
					if (iter->second == i)
					{
						break;
					}
					else
					{
						iter->second = i;
						++k;
					}

				}

			}
			if (k > ans)
			{
				ans = k;
			}
		}

		return ans;
	}
};