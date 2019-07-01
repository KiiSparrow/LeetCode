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

	vector<vector<int>> subsets(vector<int>& nums)
	{
		vector<vector<int>> ans;
		vector<int> cur{};
		trackback(nums.size(), cur, ans, nums, 0);

		return ans;
	}

	void trackback(int n, vector<int>& cur, vector<vector<int>>& ans, vector<int>& nums, int start)
	{
		ans.push_back(cur);
		for (int i = start; i < n; ++i)
		{
			vector<int> temp(cur);
			temp.push_back(nums[i]);
			trackback(n, temp, ans, nums, i + 1);
		}
	}
};