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
	int searchInsert(vector<int>& nums, int target)
	{
		int b = 0;
		int e = nums.size() - 1;

		if (target < nums[b])
			return 0;
		if (target > nums[e])
			return e + 1;

		while (b < e)
		{
			int m = (b + e) / 2;
			if (target == nums[m])
			{
				return m;
			}
			else if (target < nums[m])
			{
				e = m - 1;
			}
			else
			{
				b = m + 1;
			}
		}

		if (target <= nums[b])
			return b;
		else
			return b + 1;
	}
};