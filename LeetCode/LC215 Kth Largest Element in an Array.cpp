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
	int findKthLargest(vector<int>& nums, int k)
	{
		return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
	}

	int quickSelect(vector<int>& nums, int left, int right, int kSmall)
	{
		if (left == right)
			return nums[left];

		int p = partition(nums, left, right);

		if (p == kSmall)
		{
			return nums[p];
		}
		else if (p < kSmall)
		{
			quickSelect(nums, p + 1, right, kSmall);
		}
		else
		{
			quickSelect(nums, left, p - 1, kSmall);
		}

		return nums[p];
	}

	int partition(vector<int>& nums, int left, int right)
	{
		int i = left;
		int j = right;

		int p = left + rand() % (right - left);
		swap(nums[i], nums[p]);
		while (i < j)
		{
			while (i < j && nums[j] >= nums[left])
				--j;
			while (i < j && nums[i] <= nums[left])
				++i;
			swap(nums[i], nums[j]);
		}
		swap(nums[left], nums[i]);

		return i;
	}
};