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
	vector<vector<int>> permute(vector<int>& nums)
	{
		vector<vector<int>> ans;
		backtrack(nums.size(), nums, ans, 0);

		return ans;
	}

	void backtrack(int n, vector<int> &nums, vector<vector<int>> &ans, int start)
	{
		if (start == n)
		{
			ans.push_back(nums);
		}

		for (int i = start; i < n; ++i)
		{
			swap(nums[start], nums[i]);
			backtrack(n, nums, ans, start + 1);
			swap(nums[start], nums[i]);
		}
	}
};