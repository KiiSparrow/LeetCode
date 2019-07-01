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
	int maxProduct(vector<int>& nums)
	{
		vector<vector<int>> dp(nums.size(), vector<int>(nums.size()));
		int ans = INT_MIN;

		for (int j = 0; j < nums.size(); j++)
		{
			dp[j][j] = nums[j];
			ans = max(ans, dp[j][j]);
			for (int i = j - 1; i >= 0; i--)
			{
				dp[i][j] = dp[i][j - 1] * nums[j];
				ans = max(ans, dp[i][j]);
			}
		}

		return ans;
	}
};