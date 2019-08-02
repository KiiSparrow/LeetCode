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
	int subarraySum(vector<int>& nums, int k)
	{
		int start = 0;
		int curSum = 0;
		int cnt = 0;
		
		for (int i = 0; i < nums.size();)
		{
			if (i && curSum > k)
			{
				curSum -= nums[start];
				++start;
			}
			else
			{
				curSum += nums[i];
				++i;
				if (curSum == k)
				{
					++cnt;
				}
			}
		}

		return cnt;
	}
};