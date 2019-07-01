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
	int minCostClimbingStairs(vector<int>& cost)
	{
		vector<int> dp(cost.size() + 1);

		for (int i = 2; i <= cost.size(); i++)
		{
			dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
		}

		return dp[cost.size()];
	}
};