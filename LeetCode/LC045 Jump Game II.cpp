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

	int jump(vector<int>& nums)
	{
		if (nums.size() == 1)
			return 0;

		int n = nums.size();

		int ans = 0;
		int flag = 0;
		int maxJ = nums[0];

		for (int i = 0; i < n; ++i)
		{
			maxJ = max(maxJ, i + nums[i]);
			if (maxJ >= n - 1)
				return ans + 1;
			if (i == flag)
			{
				flag = maxJ;
				++ans;
				if (flag >= n - 1)
					return ans;
			}
		}

		return ans;
	}
};