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
	string intToRoman(int num)
	{
		string ans;

		int d = num / 1000;
		ans.append(d, 'M');
		num -= 1000 * d;

		if (num >= 900)
		{
			ans += "CM";
			num -= 900;
		}
		if (num >= 500)
		{
			ans += 'D';
			num -= 500;
		}
		if (num >= 400)
		{
			ans += "CD";
			num -= 400;
		}

		d = num / 100;
		ans.append(d, 'C');
		num -= 100 * d;

		if (num >= 90)
		{
			ans += "XC";
			num -= 90;
		}
		if (num >= 50)
		{
			ans += 'L';
			num -= 50;
		}
		if (num >= 40)
		{
			ans += "XL";
			num -= 40;
		}

		d = num / 10;
		ans.append(d, 'X');
		num -= 10 * d;

		if (num >= 9)
		{
			ans += "IX";
			num -= 9;
		}
		if (num >= 5)
		{
			ans += 'V';
			num -= 5;
		}
		if (num >= 4)
		{
			ans += "IV";
			num -= 4;
		}

		ans.append(num, 'I');

		return ans;
	}
};