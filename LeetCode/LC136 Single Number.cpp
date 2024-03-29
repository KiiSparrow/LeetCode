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
	int singleNumber(vector<int>& nums)
	{
		int res = 0;
		for (int n : nums)
		{
			res ^= n;
		}
		return res;
	}
};