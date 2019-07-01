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
	vector<vector<int>> threeSum(vector<int>& nums)
	{
		vector<vector<int>> ans;
		sort(nums.begin(), nums.end());
		int len = nums.size();

		for (int k = 0; k < len - 2; ++k)
		{
			if (nums[k] > 0) break;
			int i = k + 1, j = len - 1;
			int tar = -nums[k];
			while (i < j)
			{
				if (nums[i] + nums[j] == tar)
				{
					ans.push_back({ nums[k], nums[i], nums[j] });
					while (i < j && nums[i] == nums[i + 1]) ++i;
					while (i < j && nums[j] == nums[j - 1]) --j;
					++i;
					--j;
				}
				else if (nums[i] + nums[j] > tar)
					--j;
				else
					++i;
			}
			while (k < len - 2 && nums[k] == nums[k + 1]) ++k;
		}

		return ans;
	}
};