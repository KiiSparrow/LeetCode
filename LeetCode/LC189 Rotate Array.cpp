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
	void reverse(vector<int>& nums, int start, int end)
	{
		for (int i = 0; start + 2 * i < end; ++i)
		{
			swap(nums[start + i], nums[end - i]);
		}
	}

	void rotate(vector<int>& nums, int k)
	{
		int n = nums.size();
		k %= n;
		int position = n - k;
		reverse(nums, 0, position - 1);
		reverse(nums, position, n - 1);
		reverse(nums, 0, n - 1);
	}
};