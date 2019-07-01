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
	bool canJump(vector<int>& nums)
	{
		int n = nums.size() - 1;
		int maxJump = 0;
		for (int i = 0; i <= n && i <= maxJump; ++i)
		{
			maxJump = max(maxJump, i + nums[i]);
			if (maxJump >= n)
				return true;
		}

		return false;
	}
};