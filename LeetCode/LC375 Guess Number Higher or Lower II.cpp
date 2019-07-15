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
	int getMoneyAmount(int n)
	{
		vector<vector<int>> dp(n + 1, vector<int>(n + 1));
		for (int i = n; i > 0; --i)
		{
			for (int j = i + 1; j <= n; ++j)
			{
				if (i == j)
					dp[i][j] = 0;
				else if (i + 1 == j)
					dp[i][j] = i;
				else
				{
					dp[i][j] = INT_MAX;
					for (int p = i + 1; p < j; ++p)
					{
						dp[i][j] = min(dp[i][j], p + max(dp[i][p - 1], dp[p + 1][j]));
					}
				}
			}
		}

		return dp[1][n];
	}
};