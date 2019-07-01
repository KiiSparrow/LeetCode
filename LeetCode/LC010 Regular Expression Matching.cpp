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
	bool isMatch(string s, string p)
	{
		vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1));
		dp[s.size()][p.size()] = true;

		for (int i = s.size(); i >= 0; --i)
		{
			for (int j = p.size() - 1; j >= 0; --j)
			{
				bool firstMatch = i < s.size() && (p[j] == s[i] || p[j] == '.');
				if (j + 1 < p.size() && p[j + 1] == '*')
					dp[i][j] = dp[i][j + 2] || firstMatch && dp[i + 1][j];
				else
					dp[i][j] = firstMatch && dp[i + 1][j + 1];
			}
		}

		return dp[0][0];
	}
};