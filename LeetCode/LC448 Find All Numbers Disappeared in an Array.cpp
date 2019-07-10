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
	vector<int> findDisappearedNumbers(vector<int>& nums)
	{
		vector<int> ans;
		size_t n = nums.size();

		for (int i = 0; i < n; ++i)
		{
			if (nums[nums[i] - 1] != nums[i])
			{
				swap(nums[i], nums[nums[i] - 1]);
				--i;
			}
		}

		for (int i = 0; i < n; ++i)
		{
			if (nums[i] != i + 1)
				ans.push_back(i + 1);
		}

		return ans;
	}
};