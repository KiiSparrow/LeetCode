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
	vector<int> findDuplicates(vector<int>& nums)
	{
		vector<int> ans;
		int n = nums.size();

		int k;
		for (int i = 0; i < n; ++i)
		{
			k = abs(nums[i]) - 1;
			if (nums[k] < 0)
				ans.push_back(k + 1);
			nums[k] *= -1;
		}
		
		return ans;
	}
};