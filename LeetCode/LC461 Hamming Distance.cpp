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
	static int hammingDistance(int x, int y)
	{
		int ans = 0;
		int ham = x ^ y;

		while (ham)
		{
			if (ham & 1)
				++ans;
			ham >>= 1;
		}

		return ans;
	}
};