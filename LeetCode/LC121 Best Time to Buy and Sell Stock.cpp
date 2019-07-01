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
		int buy = INT_MIN, sell = 0;

		for (auto p : prices)
		{
			buy = max(buy, -p);
			sell = max(sell, buy + p);
		}

		return sell;
	}
};