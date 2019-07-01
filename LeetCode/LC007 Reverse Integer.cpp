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
	int reverse(int x)
	{
		int y = 0;
		int k = 1;

		if (x >= 0)
		{
			k = 1;
		}
		else
		{
			k = -1;
			x = -x;
		}

		while (x != 0)
		{
			y = 10 * y + x % 10;
			if (y % 10 != x % 10)
				return 0;
			x /= 10;
		}

		return k * y;
	}
};