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
	vector<int> countBits(int num)
	{
		vector<int> bits(num + 1, 0);

		int pivot = 1;
		for (int i = 1; i <= num; ++i)
		{
			if (i == 2 * pivot)
				pivot *= 2;
			bits.push_back(bits[i - pivot] + 1);
		}

		return bits;
	}
};