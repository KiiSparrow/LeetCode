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
	int getMoneyAmount(int n)
	{
		int left = 1;
		int right = n;
		int ans = 0;

		while (left < right)
		{
			int mid = (left + right) / 2;
			ans += mid;
			left = mid + 1;
		}

		return ans;
	}
};