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
	int myAtoi(string str)
	{
		int len = str.size();
		int iter = 0;
		for (iter = 0; iter < len; ++iter)
		{
			if (str[iter] != ' ')
				break;
		}

		if (str[iter] >= 'a' && str[iter] <= 'z' || str[iter] >= 'A' && str[iter] <= 'Z')
			return 0;

		int flag = 1;
		if (str[iter] == '-')
		{
			flag = -1;
			++iter;
		}
		else if (str[iter] == '+')
		{
			flag = 1;
			++iter;
		}

		if (str[iter] < '0' || str[iter] > '9')
			return 0;

		long long ans = str[iter] - '0';
		for (++iter; str[iter] >= '0' && str[iter] <= '9'; ++iter)
		{
			ans = ans * 10 + str[iter] - '0';
			if (flag * ans < INT_MIN)
				return INT_MIN;
			if (flag * ans > INT_MAX)
				return INT_MAX;
		}

		return flag * ans;
	}
};