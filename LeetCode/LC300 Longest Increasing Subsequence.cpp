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
	int lengthOfLIS(vector<int>& nums)
	{
		if (nums.empty())
			return 0;

		vector<int> orderedSub{ nums[0] };

		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i] > *(orderedSub.rbegin()))
			{
				orderedSub.push_back(nums[i]);
			}
			else
			{
				int start = 0, end = orderedSub.size() - 1;

				while (start <= end)
				{
					int mid = (start + end) / 2;

					if (nums[i] == orderedSub[mid])
					{
						start = mid;
						break;
					}
					else if (nums[i] < orderedSub[mid])
					{
						end = mid - 1;
					}
					else
					{
						start = mid + 1;
					}
				}

				orderedSub[start] = nums[i];
			}
		}

		return orderedSub.size();
	}

	/* O(n^2)
	int lengthOfLIS(vector<int>& nums)
	{
		if (nums.size() < 2)
			return nums.size();

		vector<int> dp(nums.size());
		int ans = 1;
		dp[0] = 1;
		for (int i = 1; i < nums.size(); i++)
		{
			for (int j = i - 1; j >= 0; j--)
			{
				if (nums[j] < nums[i])
				{
					dp[i] = max(dp[i], dp[j]);
				}
			}

			dp[i]++;
			ans = max(ans, dp[i]);
		}

		return ans;
	}*/
};