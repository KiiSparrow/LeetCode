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
		int ones = 0, twos = 0;

		for (auto num : nums)
		{
			ones = (ones ^ num) & ~twos;
			twos = (twos ^ num) & ~ones;
		}

		return ones;
	}
};