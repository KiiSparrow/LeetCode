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
	int numDecodings(string s)
	{
		if (s.empty())
			return 0;
		if (s.size() == 1)
			return s[0] == '0' ? 0 : 1;

		if (s[0] == '0')
			return 0;

		vector<long long> dp(s.size());
		dp[0] = 1;
		if (check(s.substr(0, 2)))
			dp[1] = 1;
		if (check(s.substr(1, 1)))
			dp[1]++;

		for (int i = 2; i < s.size(); i++)
		{
			if (check(s.substr(i - 1, 2)))
				dp[i] = dp[i - 2];
			if (check(s.substr(i, 1)))
				dp[i] += dp[i - 1];
		}

		return dp[s.size() - 1];
	}

	inline bool check(string s)
	{
		if (s[0] == '0' || atoi(s.c_str()) > 26)
			return false;
		return true;
	}
};