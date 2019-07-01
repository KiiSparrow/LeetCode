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
	int climbStairs(int n)
	{
		if (n == 0)
			return 0;
		if (n == 1)
			return 1;
		if (n == 2)
			return 2;

		vector<int> dp(n + 1);
		for (int i = 0; i < 3; i++)
			dp[i] = i;

		for (int i = 3; i <= n; ++i)
			dp[i] = dp[i - 1] + dp[i - 2];

		return dp[n];
	}
};