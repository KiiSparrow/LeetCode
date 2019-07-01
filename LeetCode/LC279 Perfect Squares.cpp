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
	int numSquares(int n)
	{
		//四平方数定理
		while (n % 4 == 0)
			n /= 4;

		if (n % 8 == 7)
			return 4;

		if (isSquare(n))
			return 1;

		for (int i = sqrt(n); i >= 1; i--)
		{
			if (isSquare(n - i * i))
				return 2;
		}

		return 3;
	}

	inline bool isSquare(int n)
	{
		int t = sqrt(n);
		return t * t == n;
	}

	int numSquares_Dp(int n)
	{
		vector<int> dp(n + 1);
		int top = 1;
		for (int i = 1; i <= n; i++)
		{
			if (i == (top + 1) * (top + 1))
				top++;

			dp[i] = 1 + dp[i - top * top];
			for (int j = top - 1; j >= 1; j--)
				dp[i] = min(dp[i], 1 + dp[i - j * j]);
		}

		return dp[n];
	}
};