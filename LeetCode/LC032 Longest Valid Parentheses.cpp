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
	int longestValidParentheses(string s)//DP
	{
		vector<int> dp(s.size(), 0);
		int ans = 0;
		for (int i = s.size() - 2; i >= 0; --i)
		{
			if (s[i] == ')')
				continue;
			if (s[i + dp[i + 1] + 1] == ')')
			{
				dp[i] = dp[i + 1] + 2;
				if (i + dp[i] < s.size() && dp[i + dp[i]] > 0)
				{
					dp[i] += dp[i + dp[i]];
				}
			}
			ans = max(ans, dp[i]);
		}
		return ans;
	}

	int longestValidParentheses_Stack(string s)
	{
		if (s.size() < 2)
			return 0;
		stack<int> ss;
		ss.push(-1);
		int ans = 0;
		int start = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == '(')
			{
				ss.push(i);
				start = i + 1;
			}
			else
			{
				if (ss.size() > 1)
				{
					ss.pop();
					start = ss.top() + 1;
					ans = max(ans, i - start + 1);
				}
				else
				{
					ss.pop();
					ss.push(i);
				}
			}
		}
		return ans;
	}
};