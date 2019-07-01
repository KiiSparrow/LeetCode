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
	int removeDuplicates(vector<int>& nums)
	{
		if (nums.size() == 0)
			return 0;
		else if (nums.size() == 1)
			return 1;

		int j = findNext(nums, 0);
		if (j == 0)
			return 1;

		int k;
		for (int i = 1; i < nums.size(); ++i)
		{
			nums[i] = nums[j];
			k = findNext(nums, j);
			if (k == j)
				return i + 1;
			else
				j = k;
		}
	}

	int findNext(vector<int>& nums, int left)
	{
		for (int i = left; i < nums.size(); ++i)
			if (nums[i] != nums[left])
				return i;
		return left;
	}
};