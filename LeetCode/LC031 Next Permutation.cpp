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
	void nextPermutation(vector<int>& nums)
	{
		if (nums.size() < 2) return;
		int ptr = nums.size() - 1;
		for (int i = ptr - 1; i >= 0; --i)
		{
			if (nums[i] >= nums[ptr])
				--ptr;
			else
				break;
		}

		if (ptr == 0)
		{
			reverse(nums.begin(), nums.end());
		}
		else
		{
			int target = ptr;
			for (int i = ptr + 1; i < nums.size(); ++i)
			{
				if (nums[i] > nums[ptr - 1] && nums[i] < nums[target])
				{
					target = i;
				}
			}
			swap(nums[ptr - 1], nums[target]);
			sort(nums.begin() + ptr, nums.end());
		}
	}
};