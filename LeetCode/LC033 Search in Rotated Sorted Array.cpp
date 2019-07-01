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
	int search(vector<int>& nums, int target)
	{
		if (nums.size() == 0)
			return -1;
		if (nums.size() == 1)
			return nums[0] == target ? 0 : -1;

		return quickFindUnorder(nums, 0, nums.size() - 1, target);
	}

	int quickFindUnorder(vector<int>& nums, int left, int right, int target)
	{
		int mid = (left + right) / 2;
		if (nums[mid] == target)
			return mid;

		if (left == right)
			return -1;

		int index = -1;
		if (nums[left] < nums[mid])
		{
			if (nums[left] <= target && target < nums[mid])
				index = quickFind(nums, left, mid, target);
			else
				index = quickFindUnorder(nums, mid + 1, right, target);
		}
		else
		{
			if (nums[mid + 1] <= target && target <= nums[right])
				index = quickFind(nums, mid + 1, right, target);
			else
				index = quickFindUnorder(nums, left, mid, target);
		}

		return index;
	}

	int quickFind(vector<int>& nums, int left, int right, int target)
	{
		int mid = (left + right) / 2;
		if (nums[mid] == target)
			return mid;

		if (left == right)
			return -1;

		int index = -1;
		if (target < nums[mid])
			index = quickFind(nums, left, mid, target);
		else
			index = quickFind(nums, mid + 1, right, target);

		return index;
	}
};