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
		if (n == 0)
			return 1;
		if (n == 1)
			return x;

		double tmp = myPow(x, n / 2);

		if (n % 2 == 0)
			return tmp * tmp;
		else
			return tmp * tmp * x;
	}
};