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
	vector<int> plusOne(vector<int>& digits)
	{
		int plus = 1;
		for (int i = digits.size() - 1; i >= 0 && plus; --i)
		{
			digits[i] += plus;
			plus = digits[i] / 10;
			digits[i] %= 10;
		}
		
		if (plus)
		{
			digits.insert(digits.begin(), 1);
		}

		return digits;
	}
};