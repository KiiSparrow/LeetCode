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
	int findUnsortedSubarray(vector<int>& nums)
	{
		if (nums.empty())
			return 0;
		if (nums.size() == 1)
			return 0;

		int left = 0;
		int right = nums.size() - 1;

		while (left < right && nums[left] <= nums[left + 1])
			++left;
		while (left < right && nums[right - 1] <= nums[right])
			--right;

		if (left == right)
			return 0;

		int minN = INT_MAX;
		int maxN = INT_MIN;
		for (int t = left; t <= right; ++t)
		{
			minN = min(minN, nums[t]);
			maxN = max(maxN, nums[t]);
		}

		while (left >= 0 && nums[left] > minN)
			--left;
		while (right < nums.size() && nums[right] < maxN)
			++right;

		return right - left - 1;
	}
};