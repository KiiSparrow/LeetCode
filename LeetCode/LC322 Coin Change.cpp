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
	int coinChange(vector<int>& coins, int amount)
	{
		int cnt = 0;
		
		sort(coins.begin(), coins.end());
		int p = coins.size() - 1;


		while (amount)
		{
			if (amount >= coins[p])
			{
				amount -= coins[p];
				++cnt;
			}
			else
			{
				--p;
				if (p < 0)
					return -1;
			}
		}

		return cnt;
	}
};