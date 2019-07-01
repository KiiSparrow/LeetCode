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
	bool wordBreak(string s, vector<string>& wordDict)
	{
		unordered_set<string> dict;
		int minLen = INT_MAX, maxLen = INT_MIN;
		for (auto word : wordDict)
		{
			dict.insert(word);
			minLen = min(minLen, (int)word.size());
			maxLen = max(maxLen, (int)word.size());
		}

		vector<int> dp(s.size());
		for (int i = s.size() - minLen; i >= 0; i--)
		{
			for (int len = minLen; len <= maxLen && (i + len - 1) < s.size(); len++)
			{
				if (dict.find(s.substr(i, len)) != dict.end())
				{
					if (i + len == s.size())
						dp[i] = len;
					else if (dp[i + len])
						dp[i] = len + dp[i + len];
				}
			}
		}

		return dp[0] > 0;
	}
};