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
	int coinChange(vector<int>& coins, int amount)
	{
		int n = coins.size();
		vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
		//sort(coins.rbegin(), coins.rend());

		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= amount; ++j)
			{
				dp[i][j] = dp[i - 1][j];
				if (j >= coins[i])
				{
					dp[i][j] = max(dp[i - 1][j], dp[i][j - coins[i]] + coins[i]);
				}
			}
		}

		if (dp[n][amount] != amount)
			return -1;

		int cnt = 0;
		for (int i = n; i > 0; --i)
		{
			if (dp[i][amount] != dp[i - 1][amount])
			{
				++cnt;
				amount -= coins[i];
				if (dp[i][amount] < dp[i - 1][amount])
					++i;
			}
		}

		return cnt;
	}
};