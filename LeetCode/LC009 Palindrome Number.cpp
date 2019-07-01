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
	bool isPalindrome(int x)
	{
		if (x < 0 || x > 9 && x % 10 == 0)
			return false;

		int nx = 0;
		while (x > nx)
		{
			nx = 10 * nx + x % 10;
			x /= 10;
		}

		return x == nx || x == nx / 10;
	}
};