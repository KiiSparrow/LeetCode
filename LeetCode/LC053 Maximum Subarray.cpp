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
	int maxSubArray(vector<int>& nums)
	{
		//dp
		vector<int> dp(nums.size());

		dp[0] = nums[0];
		int ans = dp[0];
		for (int i = 1; i < nums.size(); i++)
		{
			if (dp[i - 1] >= 0)
				dp[i] = dp[i - 1] + nums[i];
			else
				dp[i] = nums[i];

			ans = max(ans, dp[i]);
		}

		return ans;
		//DC
		//return maxSubArrayDC(nums, 0, nums.size() - 1);
	}

	int maxSubArrayDC(vector<int>& nums, int left, int right)
	{
		if (left == right)
			return nums[left];

		int mid = (left + right) / 2;

		int max1 = nums[mid];
		int sum = 0;
		for (int i = mid; i >= left; --i)
		{
			sum += nums[i];
			max1 = max(max1, sum);
		}

		int max2 = nums[mid + 1];
		sum = 0;
		for (int i = mid + 1; i <= right; ++i)
		{
			sum += nums[i];
			max2 = max(max2, sum);
		}

		int ans1 = maxSubArrayDC(nums, left, mid);
		int ans2 = maxSubArrayDC(nums, mid + 1, right);
		int ans3 = max1 + max2;

		return max(ans1, max(ans2, ans3));
	}
};