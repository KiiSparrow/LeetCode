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
	double myPow(double x, int n)
	{
		double ans = 1.0;

		for (int i = n; i != 0; i /= 2)
		{
			if (i % 2)
				ans *= x;
			x *= x;
		}

		return n < 0 ? 1 / ans : ans;
	}
};