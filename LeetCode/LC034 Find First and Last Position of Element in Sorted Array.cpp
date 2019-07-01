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
	vector<int> searchRange(vector<int>& nums, int target)
	{
		if (nums.size() == 0)
			return vector<int>{-1, -1};

		return quickFind(nums, 0, nums.size() - 1, target);
	}

	vector<int> quickFind(vector<int> &nums, int left, int right, int target)
	{
		if (left == right)
			return nums[left] == target ? vector<int>{left, left} : vector<int>{ -1, -1 };

		int mid = (left + right) / 2;

		if (target == nums[mid])
		{
			return vector<int>{ findLeft(nums, left, mid, target), findRight(nums, mid, right, target) };
		}
		else if (target < nums[mid])
		{
			return quickFind(nums, left, mid, target);
		}
		else // target > nums[mid]
		{
			return quickFind(nums, mid + 1, right, target);
		}
	}

	int findLeft(vector<int> &nums, int left, int right, int target)
	{
		if (left == right)
			return left;

		int mid = (left + right) / 2;
		if (target == nums[mid])
			return findLeft(nums, left, mid, target);
		else
			return findLeft(nums, mid + 1, right, target);
	}

	int findRight(vector<int> &nums, int left, int right, int target)
	{
		if (left == right)
			return left;

		int mid = (left + right + 1) / 2;
		if (target == nums[mid])
			return findRight(nums, mid, right, target);
		else
			return findRight(nums, left, mid - 1, target);
	}
};