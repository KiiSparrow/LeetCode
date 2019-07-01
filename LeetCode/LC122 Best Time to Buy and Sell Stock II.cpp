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
	int maxProfit(vector<int>& prices)
	{
		int ans = 0;

		for (int i = 1; i < prices.size(); i++)
		{
			if (prices[i] > prices[i - 1])
				ans += prices[i] - prices[i - 1];
		}

		return ans;
	}
};