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
	bool PredictTheWinner(vector<int>& nums)
	{
		int len = nums.size();
		if (len % 2 == 0 || len == 1)
		{
			return true;
		}

		vector<vector<int>> dp(len, vector<int>(len));
		for (int i = 0; i < len; ++i)
			dp[i][i] = nums[i];
		for (int i = len; i >= 0; --i)
		{
			for (int j = i + 1; j < len; ++j)
			{
				dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
			}
		}

		return dp[0][len - 1] > 0;
	}
};