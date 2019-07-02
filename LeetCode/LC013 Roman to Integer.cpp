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
	int romanToInt(string s)
	{
		if (!s.size())
			return 0;

		int res = 0;
		int numbers[26] = { 0 };

		numbers['I' - 'A'] = 1;
		numbers['V' - 'A'] = 5;
		numbers['X' - 'A'] = 10;
		numbers['L' - 'A'] = 50;
		numbers['C' - 'A'] = 100;
		numbers['D' - 'A'] = 500;
		numbers['M' - 'A'] = 1000;

		res = numbers[s[s.length() - 1] - 'A'];
		for (int i = s.length() - 2; i >= 0; --i)
		{
			if (numbers[s[i] - 'A'] < numbers[s[i + 1] - 'A'])
				res -= numbers[s[i] - 'A'];
			else
				res += numbers[s[i] - 'A'];
		}

		return res;
	}
};