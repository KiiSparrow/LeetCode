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
	int rob(vector<int>& nums)
	{
		if (nums.empty())
			return 0;

		vector<int> robY(nums.size());
		vector<int> robN(nums.size());

		robY[0] = nums[0];
		for (int i = 1; i < nums.size(); i++)
		{
			robY[i] = nums[i] + robN[i - 1];
			robN[i] = max(robY[i - 1], robN[i - 1]);
		}

		return max(robY[nums.size() - 1], robN[nums.size() - 1]);
	}
};