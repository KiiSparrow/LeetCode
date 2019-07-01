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
	vector<int> twoSum(vector<int>& nums, int target)
	{
		vector<int> ans{ 0,0 };
		for (int i = 0; i < nums.size(); ++i)
		{
			auto ta = find(nums.begin(), nums.end(), target - nums[i]);
			if (ta != nums.end() && i != ta - nums.begin())
			{
				ans[0] = i;
				ans[1] = ta - nums.begin();
			}
		}

		return ans;
	}
};