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
	bool canPartition(vector<int>& nums)
	{
		if (nums.size() < 2)
			return false;
		if (nums.size() == 2)
			return nums[0] == nums[1];

		int sum = accumulate(nums.begin(), nums.end(), 0);
		if (sum % 2 != 0)
			return false;

		int target = sum / 2;

		int n = nums.size();
		vector<int> dp(target + 1, 0);
		for (int i = 0; i < n; ++i)
		{
			for (int j = target; j >= 0; --j)
			{
				if (j >= nums[i])
				{
					dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
					if (dp[j] == target)
						return true;
				}
			}
		}

		return false;
	}
};

class Solution2
{
public:
	bool canfind(int pos, int target, int sum, vector<int>& nums)
	{
		if (pos >= nums.size()) return false;
		if (sum + nums[pos] == target) return true;
		sum += nums[pos];

		bool quit = true;
		for (int i = pos + 1; i < nums.size(); ++i)
		{
			if (nums[i] + sum <= target)
				quit = false;
		}
		if (quit) return false;

		for (int i = pos + 1; i < nums.size(); ++i)
		{
			if (canfind(i, target, sum, nums))
				return true;
		}
		return false;
	}
	bool canPartition(vector<int>& nums)
	{
		if (nums.size() < 2) return false;
		if (nums.size() == 2) return nums[0] == nums[1];

		int sum = 0;
		for (int i : nums)
			sum += i;
		if (sum % 2 != 0) return false;
		sort(nums.rbegin(), nums.rend());
		return canfind(0, sum / 2, 0, nums);
	}
};