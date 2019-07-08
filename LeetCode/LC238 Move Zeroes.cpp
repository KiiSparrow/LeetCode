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
	void moveZeroes(vector<int>& nums)
	{
		int zero = 0;

		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i])
			{
				swap(nums[zero], nums[i]);
				++zero;
			}
		}
	}
};