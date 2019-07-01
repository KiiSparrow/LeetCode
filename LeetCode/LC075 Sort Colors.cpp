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
	Solution()
	{
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
	}

	void sortColors(vector<int>& nums)
	{
		int left = 0;
		int right = nums.size() - 1;

		for (int i = 0; i <= right && left < right; )
		{
			if (nums[i] == 0)
			{
				swap(nums[i], nums[left]);
				++left;
				++i;
			}
			else if (nums[i] == 2)
			{
				swap(nums[i], nums[right]);
				--right;
			}
			else
			{
				++i;
			}
		}
	}
};